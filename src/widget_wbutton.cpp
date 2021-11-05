//widget_wbutton.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#include "widget_wbutton.hpp"
#include "lift.hpp"
#include "constants.hpp"
#include <gtkmm/label.h>

namespace gui
{
struct widget_wbutton_impl
{
    zzc::vector<Gtk::Label> labels_num,labels_up,labels_down;
};
widget_wbutton::widget_wbutton(wbutton_state *wbutton):
    m_wbutton(wbutton),data(std::make_unique<widget_wbutton_impl>())
{
    data->labels_num.resize(constant::n_floors);
    data->labels_up.resize(constant::n_floors);
    data->labels_down.resize(constant::n_floors);
    insert_column(0),insert_column(1),insert_column(2);
    set_column_spacing(5);
    set_row_spacing(5);
    for(int i=0;i<constant::n_floors;++i)
    {
        data->labels_num[i].set_label(constant::floor_name[i]);
        data->labels_num[i].set_halign(Gtk::ALIGN_START);
        data->labels_num[i].set_size_request(20,-1);
        attach(data->labels_num[i],0,i);

        data->labels_up[i].set_label("↑");
        data->labels_up[i].set_halign(Gtk::ALIGN_START);
        data->labels_up[i].set_size_request(5,-1);
        data->labels_up[i].override_background_color(Gdk::RGBA("rgb(255,255,255)"));
        attach(data->labels_up[i],1,i);

        data->labels_down[i].set_label("↓");
        data->labels_down[i].set_halign(Gtk::ALIGN_START);
        data->labels_down[i].set_size_request(5,-1);
        data->labels_down[i].override_background_color(Gdk::RGBA("rgb(255,255,255)"));
        attach(data->labels_down[i],2,i);
    }

    update();
}
widget_wbutton::~widget_wbutton(){}

void widget_wbutton::update()
{
    for(int i=0;i<constant::n_floors;++i)
    {
        if(m_wbutton->up_pressed&(1ull<<i))
            data->labels_up[i].override_background_color(Gdk::RGBA("rgb(255,255,0)"));
        else
            data->labels_up[i].override_background_color(Gdk::RGBA("rgb(255,255,255)"));
        
        if(m_wbutton->down_pressed&(1ull<<i))
            data->labels_down[i].override_background_color(Gdk::RGBA("rgb(255,255,0)"));
        else
            data->labels_down[i].override_background_color(Gdk::RGBA("rgb(255,255,255)"));
    }
}
}