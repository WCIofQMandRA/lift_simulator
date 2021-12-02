//widget_lift.hpp
//Author: 张子辰
//This file is part of the 电梯模拟器.
//电梯模拟器 is released into public domain,
//see README.md for detail.

#pragma once
#include <gtkmm/box.h>
#include <memory>

struct lift_state;
namespace gui
{
struct widget_lift_impl;
class widget_lift:public Gtk::Box
{
public:
    widget_lift(lift_state *lift);
    ~widget_lift();
    void update();
private:
    lift_state *m_lift;
    std::unique_ptr<widget_lift_impl> data;
};
}
