//mainwindow.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#include "mainwindow.hpp"
#include <gtkmm/textbuffer.h>
#include <gtkmm/entrybuffer.h>
#include "widget_wbutton.hpp"
#include "widget_lift.hpp"
#include "variables.hpp"
namespace gui
{
mainwindow::mainwindow()
{
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

	m_button_next.signal_clicked().connect(sigc::mem_fun(*this,&mainwindow::on_next_clicked));
	m_button_finish.signal_clicked().connect(sigc::mem_fun(*this,&mainwindow::on_finish_clicked));
	m_button_nextn.signal_clicked().connect(sigc::mem_fun(*this,&mainwindow::on_nextn_clicked));
	m_entry_step.get_buffer()->signal_inserted_text().connect(sigc::mem_fun(*this,&mainwindow::on_step_inserted));
	m_entry_step.get_buffer()->signal_deleted_text().connect(sigc::mem_fun(*this,&mainwindow::on_step_deleted));

	show_all_children();
}

mainwindow::~mainwindow(){}

void mainwindow::on_next_clicked()
{
	using namespace variable;
	//执行到控制台第一次输出
	std::stringstream str_cout;
	while(!event_queue.empty())
	{
		bool printed=event_queue.print(str_cout);
		event_queue.call_and_pop(str_cout);
		if(printed)
		{
			str_cout<<"\n";
			break;
		}
	}
	if(auto s=str_cout.str();s.size())
	{
		auto &buf=*m_view_message.get_buffer().get();
		buf.insert(buf.end(),s);
		m_view_message.scroll_to(m_endmark);
	}
	lifts[0].load_state(m_lift_state0);
	lifts[1].load_state(m_lift_state1);
	wall_buttons.load_state(m_wbutton_state);
	m_lift0->update();
	m_lift1->update();
	m_wbutton->update();
}

void mainwindow::on_finish_clicked()
{

}

void mainwindow::on_nextn_clicked()
{

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
}
