//mainwindow.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#include "mainwindow.hpp"
namespace gui
{
mainwindow::mainwindow()
{
	set_title("电梯模拟器");
	set_border_width(5);
}
}

int main(int argc,char **argv)
{
	auto app=Gtk::Application::create(argc,argv);
	gui::mainwindow window;
	return app->run(window);
}
