//passenger.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#include "passenger.hpp"
#include "random.hpp"
#include "constants.hpp"
#include "variables.hpp"
#include "lift.hpp"

static uint32_t PID=0;

passenger_t passenger_t::generate(int16_t from,uint64_t appear_time)
{
	using namespace constant;
	int16_t dest;
	uint64_t tolerance;
	if(from<=base_floor)
	{
		dest=rand_between<int16_t>(base_floor+1,max_floor);
		tolerance=static_cast<uint64_t>(double((dest-from)*lift_up_tick+lift_up_first_extra_tick+lift_up_last_extra_tick)
			*rand_between(tolerance_tick_rate_range)+0.5);
	}
	else
	{
		dest=rand_between<int>(0,2)?rand_between(min_floor,base_floor):base_floor;
		tolerance=static_cast<uint64_t>(double((from-dest)*lift_down_tick+lift_down_first_extra_tick+lift_down_last_extra_tick)
			*rand_between(tolerance_tick_rate_range)+0.5);
	}
	return {from,dest,PID++,rand_between(passenger_weight_range),appear_time,tolerance,0};
}

event_passenger_appear::event_passenger_appear(uint64_t time,int16_t src):
	event_t(time,"乘客出现"),passenger(passenger_t::generate(src,time)){}

void event_passenger_appear::call()const
{
	using namespace variable;
	if(passenger.destination>passenger.source)
	{
		if(!wall_buttons.is_up_pressed(passenger.source))
			event_queue.push<event_press_wbutton>(time+constant::press_button_tick,1,passenger.source);
		waiting_queues_up[passenger.source].push(passenger);
	}
	else
	{
		if(!wall_buttons.is_down_pressed(passenger.source))
			event_queue.push<event_press_wbutton>(time+constant::press_button_tick,-1,passenger.source);
		waiting_queues_down[passenger.source].push(passenger);
	}
}

bool event_passenger_appear::print(std::ostream &os)const
{
	event_t::print(os);
	os<<"#"<<passenger.ID<<", "<<passenger.source<<"->"<<passenger.destination<<", "<<passenger.weight<<"kg\n";
	return true;
}
