//lift.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#include "lift.hpp"
#include "constants.hpp"
#include "variables.hpp"
#include "random.hpp"

/////////////////////////////////////
//lift_t
/////////////////////////////////////
void lift_t::add_called_floor(uint64_t time,int16_t floor)
{
	m_called_floor|=(uint64_t)1<<(floor-constant::min_floor);
	variable::event_queue.push(std::make_unique<event_check_lift_state>(time,this));
}

uint64_t lift_t::move_to_time(int16_t floor)
{
	//TODO
	return m_floor>=floor?(m_floor-floor)*constant::lift_down_tick:
		(floor-m_floor)*constant::lift_up_tick;
}

/////////////////////////////////////
//wbutton_t
/////////////////////////////////////

bool wbutton_t::is_up_pressed(int16_t floor)const
{
	return m_up_pressed&((uint64_t)1<<(floor-constant::min_floor));
}

bool wbutton_t::is_down_pressed(int16_t floor)const
{
	return m_down_pressed&((uint64_t)1<<(floor-constant::min_floor));
}

void wbutton_t::press_up(uint64_t time,int16_t floor)
{
	if(!is_up_pressed(floor))
	{
		using variable::lifts;
		m_up_pressed|=(uint64_t)1<<(floor-constant::min_floor);
		auto t0=lifts[0].move_to_time(floor),t1=lifts[1].move_to_time(floor);
		if(t0<t1||(t0==t1&&rand_between(0,1)))
			lifts[0].add_called_floor(time,floor);
		else lifts[1].add_called_floor(time,floor);
	}
}

void wbutton_t::press_down(uint64_t time,int16_t floor)
{
	if(!is_down_pressed(floor))
	{
		using variable::lifts;
		m_down_pressed|=(uint64_t)1<<(floor-constant::min_floor);
		auto t0=lifts[0].move_to_time(floor),t1=lifts[1].move_to_time(floor);
		if(t0<t1||(t0==t1&&rand_between(0,1)))
			lifts[0].add_called_floor(time,floor);
		else lifts[1].add_called_floor(time,floor);
	}
}

//////////////////////////////////////////
//event
//////////////////////////////////////////


event_press_wbutton::event_press_wbutton(uint64_t time,int16_t dire,int16_t floor):
	event_t(time,dire>0?"按下按钮↑":"按下按钮↓"),dire(dire),floor(floor){}

void event_press_wbutton::call()const
{
	using variable::wall_buttons;
	if(dire>0)wall_buttons.press_up(time,floor);
	else wall_buttons.press_down(time,floor);
}


event_check_lift_state::event_check_lift_state(uint64_t time,lift_t *which_lift):
	event_t(time,""),which_lift(which_lift){}

void event_check_lift_state::call()const
{
	//TODO
}

event_arrive_at::event_arrive_at(uint64_t time,lift_t *which_lift,int16_t floor):
	event_t(time,"电梯 #"+std::to_string(which_lift->m_liftID)+"到达 "+std::to_string(floor)+" 层"),
	which_lift(which_lift),floor(floor){}

void event_arrive_at::call()const
{
	which_lift->m_floor=floor;
	variable::event_queue.push(std::make_unique<event_check_lift_state>(time,which_lift));
}
