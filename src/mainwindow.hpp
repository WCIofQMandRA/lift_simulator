//mainwindow.hpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#pragma once
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/button.h>
#include <gtkmm/textview.h>
#include <gtkmm/textbuffer.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <memory>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include "lift.hpp"

namespace gui
{
class widget_lift;
class widget_wbutton;
class mainwindow:public Gtk::Window
{
public:
	mainwindow();
	~mainwindow();
protected:
	void on_next_clicked();
	void on_finish_clicked();
	void on_nextn_clicked();
	void on_step_inserted(guint position,const gchar* chars,guint n_chars);
	void on_step_deleted(guint position,guint n_chars);
	bool on_time_out();
	void thread_main();
private:
	Gtk::Box m_vbox{Gtk::ORIENTATION_VERTICAL};
	
	Gtk::Box m_hbox{Gtk::ORIENTATION_HORIZONTAL};
	Gtk::ScrolledWindow m_scrolled_lift0,m_scrolled_wbutton,m_scrolled_lift1;
	std::unique_ptr<widget_lift> m_lift0,m_lift1;
	std::unique_ptr<widget_wbutton> m_wbutton;
	Gtk::ButtonBox m_box_control{Gtk::ORIENTATION_VERTICAL};
	Gtk::Button m_button_next{"下一步"};
	Gtk::Button m_button_finish{"执行完毕"};
	Gtk::Box m_box_step;
	Gtk::Label m_label1{"步数"};
	Gtk::Entry m_entry_step;
	Gtk::Button m_button_nextn{"执行10步"};
	int m_nextn=10;
	
	Gtk::ScrolledWindow m_scrolled_message;
	Glib::RefPtr<Gtk::TextBuffer::Mark> m_endmark;
	Gtk::TextView m_view_message;

	Gtk::Box m_statusbar;
	Gtk::Label m_status_seed,m_status_total_steps,m_status_total_events;

	lift_state m_lift_state0,m_lift_state1;
	wbutton_state m_wbutton_state;

	std::atomic<size_t> steps_to_process=0,total_steps=0,total_events=0;
	std::thread sim_thread;
	std::atomic_bool sim_thread_done=false;
	std::condition_variable sim_thread_notifier;
	std::mutex sim_mutex,state_mutex;
	int pipe_fd[2];
};
}
