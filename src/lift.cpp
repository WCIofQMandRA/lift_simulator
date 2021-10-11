//lift.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#include "lift.hpp"
#include "constants.hpp"

event_press_wbutton::event_press_wbutton(uint64_t time,int32_t dire,int32_t floor):
	event_t(time,dire>0?"按下按钮↑":"按下按钮↓"),dire(dire),floor(floor){}

void event_press_wbutton::call()const
{
	//TODO
}

bool wbutton_t::is_up_pressed(int floor)const
{
	return m_up_pressed&((uint64_t)1<<(floor-constant::min_floor));
}

bool wbutton_t::is_down_pressed(int floor)const
{
	return m_down_pressed&((uint64_t)1<<(floor-constant::min_floor));
}

void wbutton_t::press_up(int floor)
{
	m_up_pressed&=(uint64_t)1<<(floor-constant::min_floor);
}

void wbutton_t::press_down(int floor)
{
	m_down_pressed&=(uint64_t)1<<(floor-constant::min_floor);
}
