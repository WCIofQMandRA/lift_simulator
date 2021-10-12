//passenger.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#include "passenger.hpp"
#include "random.hpp"
#include "constants.hpp"
#include "variables.hpp"
#include "lift.hpp"

static uint32_t PID=0;

passenger_t passenger_t::generate(int32_t from,uint64_t appear_time)
{
	using namespace constant;
	if(from<=base_floor)
		return {rand_between<int32_t>(base_floor+1,max_floor),PID++,rand_between(passenger_weight_range),appear_time};
	else
		return {rand_between<int>(0,2)?rand_between<int32_t>(min_floor,base_floor):base_floor,PID++,rand_between(passenger_weight_range),appear_time};
}

event_passenger_appear::event_passenger_appear(uint64_t time,int16_t src):
	event_t(time,"乘客出现"),source(src),passenger(passenger_t::generate(src,time)){}

void event_passenger_appear::call()const
{
	using namespace variable;
	if(passenger.destination>source)
	{
		if(!wall_buttons.is_up_pressed(source))
			event_queue.push(std::make_unique<event_press_wbutton>(time+constant::press_button_tick,1,source));
		waiting_queues_up[source].push(passenger);
	}
	else
	{
		if(!wall_buttons.is_down_pressed(source))
			event_queue.push(std::make_unique<event_press_wbutton>(time+constant::press_button_tick,-1,source));
		waiting_queues_down[source].push(passenger);
	}
}

bool event_passenger_appear::print(std::ostream &os)const
{
	event_t::print(os);
	os<<"#"<<passenger.ID<<", "<<source<<"->"<<passenger.destination<<", "<<passenger.weight<<"kg\n";
	return true;
}
