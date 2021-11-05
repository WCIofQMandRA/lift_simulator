//main.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#include "mainwindow.hpp"

int main()
{
	auto app=Gtk::Application::create();
	gui::mainwindow window;
	return app->run(window);
}
