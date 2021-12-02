//widget_wbutton.hpp
//Author: 张子辰
//This file is part of the 电梯模拟器.
//电梯模拟器 is released into public domain,
//see README.md for detail.

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
