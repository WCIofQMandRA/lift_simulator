//main.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#include "queue.hpp"
#include "passenger.hpp"
#include "lift.hpp"
#include "constants.hpp"
#include "variables.hpp"
#include "random.hpp"
#include <iostream>
#include <array>

namespace
{
class compare_passenger
{
public:
	bool operator()(const passenger_t &p1,const passenger_t &p2)
	{
		return p1.appear_time==p2.appear_time?p1.ID>p2.ID:p1.appear_time>p2.appear_time;
	}
};
zzc::priority_queue<passenger_t,compare_passenger> passengers_to_appear;

//生成乘客
void generate_passengers()
{
	using namespace constant;
	int n_passengers=rand_between(passenger_number_range);
	while(n_passengers--)
	{
		int16_t start;
		if(rand_between(0,1))
			start=rand_between(min_floor,base_floor);
		else start=rand_between<int16_t>(base_floor+1,max_floor);
		passengers_to_appear.push(passenger_t::generate(start,rand_between(take_lift_time)));
	}
}

//把新出现的乘客放入等待乘梯队列
void add_new_passenger_to_waiting_queue()
{
	for(auto top=passengers_to_appear.top();top.appear_time==variable::current_tick;
		passengers_to_appear.pop(),top=passengers_to_appear.top())
	{
		if(top.destination<top.source)
		{
			top.tolerence_time=static_cast<uint64_t>
				(rand_between(constant::tolerance_tick_rate_range)*(top.source-top.destination)+0.5);
			variable::waiting_queues_down[top.source].push(top);
		}
		else
		{
			top.tolerence_time=static_cast<uint64_t>
				(rand_between(constant::tolerance_tick_rate_range)*(top.destination-top.source)+0.5);
			variable::waiting_queues_up[top.source].push(top);
		}
	}
}

}//namespace

int main([[maybe_unused]]int argc,[[maybe_unused]]char **argv)
{
	rand_engine.seed(std::random_device()());
	generate_passengers();
	using namespace variable;
	for(current_tick=0;current_tick<864000;++current_tick)
	{
		add_new_passenger_to_waiting_queue();
		
	}
	return 0;
}