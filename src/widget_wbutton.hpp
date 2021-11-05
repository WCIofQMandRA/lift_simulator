//widget_wbutton.hpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.


#pragma once
#include <gtkmm/grid.h>
#include <memory>

struct wbutton_state;
namespace gui
{
struct widget_wbutton_impl;
class widget_wbutton:public Gtk::Grid
{
public:
    widget_wbutton(wbutton_state *wbutton);
    ~widget_wbutton();
    void update();
private:
    wbutton_state *m_wbutton;
    std::unique_ptr<widget_wbutton_impl> data;
};
}