//widget_lift.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#include "widget_lift.hpp"
#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include <glibmm/ustring.h>
#include <gtkmm/grid.h>
#include "lift.hpp"
#include "constants.hpp"

namespace gui
{

struct widget_lift_impl
{
    Gtk::Label label_liftID,label_floor,label_speed,label_carrying,label_door;
    Gtk::Box hbox1;
    Gtk::Grid grid_pressed_button;
    zzc::vector<Gtk::Label> label_buttons;
};
widget_lift::widget_lift(lift_state *lift):Gtk::Box(Gtk::ORIENTATION_VERTICAL),m_lift(lift),data(std::make_unique<widget_lift_impl>())
{
    
    pack_start(data->label_liftID);
    pack_start(data->hbox1);
    data->hbox1.pack_start(data->label_floor);
    data->hbox1.pack_start(data->label_speed,Gtk::PACK_EXPAND_WIDGET,20);
    pack_start(data->label_carrying);
    pack_start(data->label_door);
    pack_start(data->grid_pressed_button);

    data->label_liftID.set_halign(Gtk::ALIGN_START);
    data->hbox1.set_halign(Gtk::ALIGN_START);
    data->label_carrying.set_halign(Gtk::ALIGN_START);
    data->label_door.set_halign(Gtk::ALIGN_START);
    data->grid_pressed_button.set_halign(Gtk::ALIGN_START);

    constexpr int button_per_row=6;
    int n_col=(constant::n_floors+button_per_row-1)/button_per_row;
    for(int i=0;i<button_per_row;++i)
        data->grid_pressed_button.insert_row(i);
    for(int i=0;i<n_col;++i)
        data->grid_pressed_button.insert_column(i);
    data->grid_pressed_button.set_row_spacing(5);
    data->grid_pressed_button.set_column_spacing(5);
    data->label_buttons.resize(constant::n_floors);
    for(int i=0;i<constant::n_floors;++i)
    {
        data->label_buttons[i].set_size_request(20,20);
        data->label_buttons[i].set_xalign(0.5f);
        data->label_buttons[i].set_yalign(0.5f);
        data->label_buttons[i].override_background_color(Gdk::RGBA("rgb(255,255,255)"));
        data->label_buttons[i].set_label(constant::floor_name[i]);
        data->grid_pressed_button.attach(data->label_buttons[i],i%button_per_row,i/button_per_row);
    }

    update();
}

widget_lift::~widget_lift(){}

void widget_lift::update()
{
    data->label_liftID.set_markup(Glib::ustring::compose("<b><big>电梯 #%1</big></b>",m_lift->liftID));
    data->label_floor.set_markup(Glib::ustring::compose("<b>楼层</b>: %1",constant::floor_name[m_lift->floor]));
    data->label_speed.set_markup(Glib::ustring::compose("<b>方向</b>: %1 <small>(%2)</small>",
        m_lift->direction==0?"—":(m_lift->direction>0?"↑":"↓"),m_lift->direction));
    data->label_carrying.set_markup(Glib::ustring::compose("<b>载重</b>: %1kg",m_lift->carrying_weight));
    data->label_door.set_label(m_lift->is_door_open==0?"关门":(m_lift->is_door_open==1?"正在开/关门":"开门"));
    for(int i=0;i<constant::n_floors;++i)
    {
        if(m_lift->pressed_button&(1ull<<i))
            data->label_buttons[i].override_background_color(Gdk::RGBA("rgb(255,255,0)"));
        else
            data->label_buttons[i].override_background_color(Gdk::RGBA("rgb(255,255,255)"));
    }
}
}