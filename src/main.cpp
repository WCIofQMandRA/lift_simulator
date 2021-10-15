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
#include <iomanip>

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
		variable::event_queue.push<event_passenger_appear>(rand_between(take_lift_time),start);
	}
}

//输出统计信息
static void output_statistics()
{
	using namespace statistic;
	using std::cout,std::endl;
	cout<<"总乘客数: "<<up_total_passengers+down_total_passengers
	<<"， 其中"<<up_total_passengers_lift+down_total_passengers_lift<<"人乘坐电梯\n";
	cout<<"平均耗时: 上楼"<<0.1*(double)up_total_tick/(double)up_total_floors<<"s/层   下楼"
	<<0.1*(double)down_total_tick/(double)down_total_floors<<"s/层\n";
	cout<<"乘梯的平均耗时: 上楼"<<0.1*(double)up_total_tick_lift/(double)up_total_floors_lift<<"s/层   下楼"
	<<0.1*(double)down_total_tick_lift/(double)down_total_floors_lift<<"s/层\n";
	cout<<"最长耗时: 上楼"<<up_max_time<<"s/层   下楼"<<down_max_time<<"s/层\n";
	cout<<"乘梯的最长耗时: 上楼"<<up_max_time_lift<<"s/层   下楼"<<down_max_time_lift<<"s/层\n";
	cout<<"最短耗时: 上楼"<<up_min_time<<"s/层   下楼"<<down_min_time<<"s/层\n";
	cout<<"乘梯的最短耗时: 上楼"<<up_min_time_lift<<"s/层   下楼"<<down_min_time_lift<<"s/层\n";
}

int main([[maybe_unused]]int argc,[[maybe_unused]]char **argv)
{
	std::cout<<std::setprecision(4)<<std::fixed;
#ifdef NDEBUG
	rand_engine.seed(std::random_device()());
#else
	auto seed=std::random_device()();
	//auto seed=405214910;
	std::cout<<"Seed: "<<seed<<"\n\n";
	rand_engine.seed(seed);
#endif
	generate_passengers();
	using namespace variable;
	while(!event_queue.empty())
	{
		bool printed=event_queue.print(std::cout);
		event_queue.call_and_pop(std::cout);
		//call()函数可能有输出，所以在call之后才输出用于分割的空行
#ifndef __cplusplus//NDEBUG
		if(printed)system(R"(bash -c "read -s -n 1 -p \"请按任意键继续...\" && echo \"\"")");
#endif
		if(printed)std::cout<<"\n";
	}
	output_statistics();
	return 0;
}
