//mainwindow.hpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#pragma once
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/button.h>
#include <gtkmm/textview.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <memory>

namespace gui
{
class widget_lift;
class widget_wbutton;
class mainwindow:public Gtk::Window
{
public:
	mainwindow();
	~mainwindow();
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
	
	Gtk::ScrolledWindow m_scrolled_message;
	Gtk::TextView m_view_message;
};
}
