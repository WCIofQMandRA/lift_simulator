//mainwindow.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#include "mainwindow.hpp"
#include <gtkmm/textbuffer.h>
#include <gtkmm/entrybuffer.h>
#include "widget_wbutton.hpp"
#include "widget_lift.hpp"
#include "variables.hpp"
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <glibmm/main.h>
#include <fstream>
#include "random.hpp"
namespace gui
{
mainwindow::mainwindow()
{
	::pipe2(pipe_fd,O_NONBLOCK|O_DIRECT);
	sim_thread=std::thread(sigc::mem_fun(this,&mainwindow::thread_main));

	variable::lifts[0].load_state(m_lift_state0);
	variable::lifts[1].load_state(m_lift_state1);
	variable::wall_buttons.load_state(m_wbutton_state);

	m_lift0=std::make_unique<widget_lift>(&m_lift_state0);
	m_lift1=std::make_unique<widget_lift>(&m_lift_state1);
	m_wbutton=std::make_unique<widget_wbutton>(&m_wbutton_state);

	set_title("电梯模拟器");
	set_border_width(5);
	
	add(m_vbox);
	m_vbox.pack_start(m_hbox);
	
	m_hbox.set_spacing(10);
	m_hbox.pack_start(m_scrolled_lift0);
	m_hbox.pack_start(m_scrolled_wbutton);
	m_hbox.pack_start(m_scrolled_lift1);
	m_hbox.pack_start(m_box_control);
	
	m_box_control.pack_start(m_button_next);
	m_box_control.pack_start(m_button_finish);
	m_box_control.pack_start(m_box_step);
	m_box_step.pack_start(m_label1);
	m_box_step.pack_start(m_entry_step);
	m_box_control.pack_start(m_button_nextn);
	
	m_vbox.pack_start(m_scrolled_message,Gtk::PACK_EXPAND_WIDGET,10);

	m_vbox.pack_start(m_statusbar,Gtk::PACK_SHRINK);
	m_statusbar.pack_start(m_status_seed,Gtk::PACK_SHRINK,10);
	m_statusbar.pack_start(m_status_total_steps,Gtk::PACK_SHRINK,10);
	m_statusbar.pack_start(m_status_total_events,Gtk::PACK_SHRINK,10);
	
	////////////////////////
	//控制按钮
	m_entry_step.set_buffer(Gtk::EntryBuffer::create());
	m_entry_step.set_placeholder_text("10");
	m_entry_step.set_width_chars(6);
	//展示电梯的状态
	m_scrolled_lift0.set_policy(Gtk::POLICY_NEVER,Gtk::POLICY_AUTOMATIC);
	m_scrolled_lift0.add(*m_lift0);
	m_scrolled_lift0.set_min_content_height(200);
	m_scrolled_lift1.set_policy(Gtk::POLICY_NEVER,Gtk::POLICY_AUTOMATIC);
	m_scrolled_lift1.add(*m_lift1);
	m_scrolled_lift1.set_min_content_height(200);
	m_scrolled_wbutton.set_policy(Gtk::POLICY_NEVER,Gtk::POLICY_AUTOMATIC);
	m_scrolled_wbutton.add(*m_wbutton);
	m_scrolled_wbutton.set_min_content_height(200);
	//终端消息
	m_scrolled_message.set_policy(Gtk::POLICY_AUTOMATIC,Gtk::POLICY_AUTOMATIC);
	m_scrolled_message.set_min_content_height(150);
	m_scrolled_message.set_min_content_width(450);
	m_scrolled_message.add(m_view_message);
	m_view_message.set_buffer(Gtk::TextBuffer::create());
	m_view_message.set_wrap_mode(Gtk::WRAP_WORD_CHAR);
	m_view_message.property_editable()=false;
	m_endmark=m_view_message.get_buffer()->create_mark(m_view_message.get_buffer()->end(),false);
	//状态栏
	m_statusbar.set_halign(Gtk::ALIGN_END);
	m_statusbar.set_valign(Gtk::ALIGN_END);
	m_status_seed.set_markup(Glib::ustring::compose("<b>随机数种子</b>: %1",variable::random_seed));
	m_status_total_steps.set_markup("<b>总步骤数</b>: 0");
	m_status_total_events.set_markup("<b>总事件数</b>: 0");

	m_button_next.signal_clicked().connect(sigc::mem_fun(*this,&mainwindow::on_next_clicked));
	m_button_finish.signal_clicked().connect(sigc::mem_fun(*this,&mainwindow::on_finish_clicked));
	m_button_nextn.signal_clicked().connect(sigc::mem_fun(*this,&mainwindow::on_nextn_clicked));
	m_entry_step.get_buffer()->signal_inserted_text().connect(sigc::mem_fun(*this,&mainwindow::on_step_inserted));
	m_entry_step.get_buffer()->signal_deleted_text().connect(sigc::mem_fun(*this,&mainwindow::on_step_deleted));
	Glib::signal_timeout().connect(sigc::mem_fun(*this,&mainwindow::on_time_out),20);

	show_all_children();
}

mainwindow::~mainwindow()
{
	if(sim_thread.joinable())
	{
		sim_thread_done=true;
		sim_thread_notifier.notify_one();
		sim_thread.join();
	}
}

void mainwindow::thread_main()
{
	using namespace variable;
	std::unique_lock lock1(sim_mutex);
	while(!event_queue.empty())
	{
		std::ostringstream str_out;
		while(steps_to_process==0)
		{
			sim_thread_notifier.wait(lock1);
			if(sim_thread_done)
				return;
		}
		++total_events;
		bool printed=event_queue.print(str_out);
		event_queue.call_and_pop(str_out);
		if(printed)
		{
			str_out<<"\n";
			--steps_to_process;
			++total_steps;
			if(state_mutex.try_lock())
			{
				lifts[0].load_state(m_lift_state0);
				lifts[1].load_state(m_lift_state1);
				wall_buttons.load_state(m_wbutton_state);
				state_mutex.unlock();
			}
		}
		auto s=str_out.str();
		if(s.size())
			::write(pipe_fd[1],s.data(),s.size());
	}
	sim_thread_done=true;
}

void mainwindow::on_next_clicked()
{
	m_button_finish.set_sensitive(false);
	m_button_next.set_sensitive(false);
	m_button_nextn.set_sensitive(false);
	m_entry_step.set_sensitive(false);
	++steps_to_process;
	sim_thread_notifier.notify_one();
}

void mainwindow::on_finish_clicked()
{
	m_button_finish.set_sensitive(false);
	m_button_next.set_sensitive(false);
	m_button_nextn.set_sensitive(false);
	m_entry_step.set_sensitive(false);
	steps_to_process+=1u<<31;
	sim_thread_notifier.notify_one();
}

void mainwindow::on_nextn_clicked()
{
	m_button_finish.set_sensitive(false);
	m_button_next.set_sensitive(false);
	m_button_nextn.set_sensitive(false);
	m_entry_step.set_sensitive(false);
	steps_to_process+=m_nextn;
	sim_thread_notifier.notify_one();
}

void mainwindow::on_step_inserted(guint,const gchar*,guint)
{
	auto text=m_entry_step.get_text();
	bool text_changed=false;
	if(text.length()>5)text=text.substr(0,5),text_changed=true;
	if([&]
	{
		for(auto it=text.begin();it!=text.end();++it)
			if(*it<'0'||*it>'9')
				return true;
		return false;
	}())
	{
		Glib::ustring new_text;
		for(auto i:text)
		{
			if(i>='0'&&i<='9')
				new_text+=i;
		}
		text=new_text;
		text_changed=true;
	}
	if(text_changed)
		m_entry_step.set_text(text);

	if(text.size())
		m_nextn=std::stoi(text.raw());
	else m_nextn=10;//默认值
	m_button_nextn.set_label(Glib::ustring::compose("执行%1步",m_nextn));
}

void mainwindow::on_step_deleted(guint,guint)
{
	auto text=m_entry_step.get_text();
	if(text.size())
		m_nextn=std::stoi(text.raw());
	else m_nextn=10;//默认值
	m_button_nextn.set_label(Glib::ustring::compose("执行%1步",m_nextn));
}

bool mainwindow::on_time_out()
{
	if(sim_thread_done&&sim_thread.joinable())
	{
		sim_thread.join();
		m_button_finish.set_sensitive(false);
		m_button_next.set_sensitive(false);
		m_button_nextn.set_sensitive(false);
		m_entry_step.set_sensitive(false);
		std::thread(sigc::mem_fun(this,&mainwindow::output_statistics)).detach();
	}
	static thread_local char buffer[PIPE_BUF];
	for(auto len=::read(pipe_fd[0],buffer,PIPE_BUF);len>0;
		len=::read(pipe_fd[0],buffer,PIPE_BUF))
	{
		std::string s(buffer,len);
		auto &buf=*m_view_message.get_buffer().get();
		buf.insert(buf.end(),s);
		m_view_message.scroll_to(m_endmark);
	}
	state_mutex.lock();
	m_lift0->update();
	m_lift1->update();
	m_wbutton->update();
	state_mutex.unlock();
	m_status_total_steps.set_markup(Glib::ustring::compose("<b>总步骤数</b>: %1",
		total_steps.load(std::memory_order_relaxed)));
	m_status_total_events.set_markup(Glib::ustring::compose("<b>总事件数</b>: %1",
		total_events.load(std::memory_order_relaxed)));
	if(!sim_thread_done&&steps_to_process==0)
	{
		m_button_finish.set_sensitive(true);
		m_button_next.set_sensitive(true);
		m_button_nextn.set_sensitive(true);
		m_entry_step.set_sensitive(true);
	}
	return true;
}

void mainwindow::output_statistics()
{
	using namespace statistic;
	using std::endl,constant::floor_name;
	std::string s;
	std::ostringstream cout;
	cout<<"总乘客数: "<<up_total_passengers+down_total_passengers
	<<"， 其中"<<up_total_passengers_lift+down_total_passengers_lift<<"人乘坐电梯\n";
	cout<<"平均耗时: 上楼"<<0.1*(double)up_total_tick/(double)up_total_floors<<"s/层   下楼"
	<<0.1*(double)down_total_tick/(double)down_total_floors<<"s/层\n";
	cout<<"电梯的平均耗时: 上楼"<<0.1*(double)up_total_tick_lift/(double)up_total_floors_lift<<"s/层   下楼"
	<<0.1*(double)down_total_tick_lift/(double)down_total_floors_lift<<"s/层\n";
	cout<<"楼梯的平均耗时: 上楼"<<0.1*double(up_total_tick-up_total_tick_lift)
	/double(up_total_floors-up_total_floors_lift)<<"s/层   下楼"
	<<0.1*double(down_total_tick-down_total_tick_lift)
	/double(down_total_floors-down_total_floors_lift)<<"s/层\n\n";
	s=cout.str();cout.str("");
	::write(pipe_fd[1],s.data(),s.size());

	cout<<"最长耗时: 上楼"<<up_max_time<<"s/层   下楼"<<down_max_time<<"s/层\n";
	cout<<"电梯的最长耗时: 上楼"<<up_max_time_lift<<"s/层   下楼"<<down_max_time_lift<<"s/层\n";
	cout<<"楼梯的最长耗时: 上楼"<<up_max_time_stairs<<"s/层   下楼"<<down_max_time_stairs<<"s/层\n\n";
	s=cout.str();cout.str("");
	::write(pipe_fd[1],s.data(),s.size());

	cout<<"最短耗时: 上楼"<<up_min_time<<"s/层   下楼"<<down_min_time<<"s/层\n";
	cout<<"电梯的最短耗时: 上楼"<<up_min_time_lift<<"s/层   下楼"<<down_min_time_lift<<"s/层\n";
	cout<<"楼梯的最短耗时: 上楼"<<up_min_time_stairs<<"s/层   下楼"<<down_min_time_stairs<<"s/层\n\n";
	s=cout.str();cout.str("");
	::write(pipe_fd[1],s.data(),s.size());

	std::string filename=std::to_string(rand_between(0,100000000))+".csv";
	std::ofstream fout(filename);
	fout<<"乘客,起点,终点,出现时刻,启程时刻,到达时刻,最大等待时间,乘坐电梯\n";
	while(!all_passengers.empty())
	{
		auto &p=all_passengers.front();
		fout<<p.first.ID<<","<<floor_name[p.first.source]<<","<<floor_name[p.first.destination]<<","
		<<p.first.appear_time<<","<<p.first.depart_time<<","<<p.first.arrive_time<<","<<p.first.tolerance_time<<","
		<<p.second<<"\n";
		all_passengers.pop();
	}
	fout.close();
	cout<<"详细信息见 "<<filename<<endl;
	s=cout.str();cout.str("");
	::write(pipe_fd[1],s.data(),s.size());
}
}
