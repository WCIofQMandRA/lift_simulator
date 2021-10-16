//passenger.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#include "passenger.hpp"
#include "random.hpp"
#include "constants.hpp"
#include "variables.hpp"
#include "lift.hpp"
#include <cassert>

static uint32_t PID=0;

passenger_t passenger_t::generate(int16_t from,uint64_t appear_time)
{
	using namespace constant;
	int16_t dest;
	uint64_t tolerance;
	if(from<=base_floor)
	{
		dest=rand_between<int16_t>(base_floor+1,max_floor);
		tolerance=static_cast<uint64_t>(double((dest-from)*walk_up_tick_range.second+walk_up_fl_extra.second)
			*rand_between(tolerance_tick_rate_range)+0.5);
	}
	else
	{
		dest=rand_between<int>(0,2)?rand_between(min_floor,base_floor):base_floor;
		tolerance=static_cast<uint64_t>(double((from-dest)*walk_down_tick_range.second+walk_down_fl_extra.second)
			*rand_between(tolerance_tick_rate_range)+0.5);
	}
	return {from,dest,PID++,rand_between(passenger_weight_range),appear_time,tolerance,0};
}

event_passenger_appear::event_passenger_appear(uint64_t time,int16_t src):
	event_t(time,"乘客出现"),passenger(passenger_t::generate(src,time)){}

void event_passenger_appear::call(std::ostream &)const
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

event_passenger_walk::event_passenger_walk(uint64_t time,const passenger_t &passenger):
	event_t(time,"乘客放弃等待"),passenger(passenger){}

void event_passenger_walk::call(std::ostream &)const
{
	auto pass2=passenger;
	pass2.arrive_time=time+(pass2.source>pass2.destination?(pass2.source-pass2.destination)
		*rand_between(constant::walk_down_tick_range)+rand_between(constant::walk_down_fl_extra)
		:(pass2.destination-pass2.source)*rand_between(constant::walk_up_tick_range)+
		rand_between(constant::walk_up_fl_extra));
	variable::event_queue.push<event_passenger_arrive>(pass2,false);
}

bool event_passenger_walk::print(std::ostream &os)const
{
	event_t::print(os);
	os<<"#"<<passenger.ID<<", "<<passenger.source<<"->"<<passenger.destination<<", "<<passenger.weight<<"kg\n";
	return true;
}

event_passenger_arrive::event_passenger_arrive(const passenger_t &passenger,bool taking_lift):
	event_t(passenger.arrive_time,"乘客到达"),passenger(passenger),taking_lift(taking_lift){}

void event_passenger_arrive::call(std::ostream &)const
{
	//统计一天中的乘客
	using namespace statistic;
	all_passengers.push({passenger,taking_lift});
	auto time_cost=passenger.arrive_time-passenger.appear_time;
	double time_cost_d=static_cast<double>(time_cost);
	if(passenger.destination>passenger.source)
	{
		auto up_floor=passenger.destination-passenger.source;
		double up_floor_d(up_floor);
		up_total_passengers++;
		up_total_tick+=time_cost;
		up_max_time=std::max(up_max_time,0.1*time_cost_d/up_floor_d);
		up_min_time=std::min(up_min_time,0.1*time_cost_d/up_floor_d);
		up_total_floors+=up_floor;
		if(taking_lift)
		{
			up_total_passengers_lift++;
			up_total_tick_lift+=time_cost;
			up_max_time_lift=std::max(up_max_time_lift,0.1*time_cost_d/up_floor_d);
			up_min_time_lift=std::min(up_min_time_lift,0.1*time_cost_d/up_floor_d);
			up_total_floors_lift+=up_floor;
		}
		else
		{
			up_max_time_stairs=std::max(up_max_time_stairs,0.1*time_cost_d/up_floor_d);
			up_min_time_stairs=std::min(up_min_time_stairs,0.1*time_cost_d/up_floor_d);
		}
	}
	else
	{
		assert(passenger.destination<passenger.source);
		auto down_floor=passenger.source-passenger.destination;
		double down_floor_d(down_floor);
		down_total_passengers++;
		down_total_tick+=time_cost;
		down_max_time=std::max(down_max_time,0.1*time_cost_d/down_floor_d);
		down_min_time=std::min(down_min_time,0.1*time_cost_d/down_floor_d);
		down_total_floors+=down_floor;
		if(taking_lift)
		{
			down_total_passengers_lift++;
			down_total_tick_lift+=time_cost;
			down_max_time_lift=std::max(down_max_time_lift,0.1*time_cost_d/down_floor_d);
			down_min_time_lift=std::min(down_min_time_lift,0.1*time_cost_d/down_floor_d);
			down_total_floors_lift+=down_floor;
		}
		else
		{
			down_max_time_stairs=std::max(down_max_time_stairs,0.1*time_cost_d/down_floor_d);
			down_min_time_stairs=std::min(down_min_time_stairs,0.1*time_cost_d/down_floor_d);
		}
	}
}

bool event_passenger_arrive::print(std::ostream &os)const
{
	event_t::print(os);
	os<<"#"<<passenger.ID<<", "<<passenger.source<<"->"<<passenger.destination<<", "<<passenger.weight<<"kg\n";
	output_time(os<<"出发时间: ",passenger.appear_time)<<"\n";
	output_time(os<<"到达时间: ",passenger.arrive_time)<<"\n";
	os<<(taking_lift?"(乘坐电梯)\n":"(走楼梯)\n");
	return true;
}
