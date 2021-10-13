//lift.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#include "lift.hpp"
#include "constants.hpp"
#include "variables.hpp"
#include "random.hpp"
#include "cassert"

namespace
{
template<typename T>
T lowbit(T x){return x&-x;}
}

/////////////////////////////////////
//lift_t
/////////////////////////////////////
void lift_t::add_called_up_floor(int16_t floor)
{
	m_called_up_floor|=(uint64_t)1<<(floor-constant::min_floor);
	m_waiting_floor=-1;
}

void lift_t::add_called_down_floor(int16_t floor)
{
	m_called_down_floor|=(uint64_t)1<<(floor-constant::min_floor);
	m_waiting_floor=-1;
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

void wbutton_t::press_up(int16_t floor)
{
	if(!is_up_pressed(floor))
	{
		using variable::lifts;
		m_up_pressed|=(uint64_t)1<<(floor-constant::min_floor);
		auto t0=lifts[0].move_to_time(floor),t1=lifts[1].move_to_time(floor);
		if(t0<t1||(t0==t1&&rand_between(0,1)))
			lifts[0].add_called_up_floor(floor);
		else lifts[1].add_called_up_floor(floor);
	}
}

void wbutton_t::press_down(int16_t floor)
{
	if(!is_down_pressed(floor))
	{
		using variable::lifts;
		m_down_pressed|=(uint64_t)1<<(floor-constant::min_floor);
		auto t0=lifts[0].move_to_time(floor),t1=lifts[1].move_to_time(floor);
		if(t0<t1||(t0==t1&&rand_between(0,1)))
			lifts[0].add_called_down_floor(floor);
		else lifts[1].add_called_down_floor(floor);
	}
}
