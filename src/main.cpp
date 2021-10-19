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
#include <fstream>
#include <cstdlib>
#include <filesystem>
#include <sstream>
#include "config_paser.hpp"
namespace fs=std::filesystem;

#define FOR_EACH_II(x,y,...)  ZZCPP_FOR_EACH(x,y,__VA_ARGS__)
static void load_constants()
{
#define OPTION_LIST\
	tick_time,iolift_tick_range,ocdoor_tick,\
	press_close_extra_tick,auto_close_door_tick,return_waiting_floor_tick,\
	lift_up_tick,lift_down_tick,lift_up_first_extra_tick,lift_up_last_extra_tick,\
	lift_down_first_extra_tick,lift_down_last_extra_tick,walk_up_tick_range,\
	walk_down_tick_range,walk_up_fl_extra,walk_down_fl_extra,tolerance_tick_rate_range,\
	min_take_lift_up,min_take_lift_down,press_button_tick,n_floors,base_floor,\
	floor_name,waiting_floor,passenger_weight_range,passenger_number_range,\
	take_lift_time,full_weight
	using namespace constant;
	zzc::ini_parser parser;
	char *exepath=realpath("/proc/self/exe",nullptr);
	std::ifstream fin(fs::u8path(exepath).parent_path().parent_path()/"etc/lift_simulator/constants.ini");
	free(exepath);
#define ADD_OP_IMPL(x) (parser.add_key<decltype(x)>(#x))
	FOR_EACH_II(ADD_OP_IMPL,;,OPTION_LIST);
#undef ADD_OP_IMPL
	parser.load(fin);
#define LOAD_CONFIG_IMPL(x) parser.get_key(x,#x)
	FOR_EACH_II(LOAD_CONFIG_IMPL,;,OPTION_LIST);
#undef LOAD_CONFIG_IMPL
#undef OPTION_LIST
#undef FOR_EACH_II
}

//生成乘客
static void generate_passengers()
{
	using namespace constant;
	int n_passengers=rand_between(passenger_number_range);
	while(n_passengers--)
	{
		int16_t start;
		if(rand_between(0,1))
			start=rand_between<int16_t>(0,base_floor);
		else start=static_cast<int16_t>(rand_between(base_floor+1,n_floors-1));
		variable::event_queue.push<event_passenger_appear>(rand_between(take_lift_time),start);
	}
}

//输出统计信息
static void output_statistics()
{
	using namespace statistic;
	using std::cout,std::endl,constant::floor_name;
	cout<<"总乘客数: "<<up_total_passengers+down_total_passengers
	<<"， 其中"<<up_total_passengers_lift+down_total_passengers_lift<<"人乘坐电梯\n";
	cout<<"平均耗时: 上楼"<<0.1*(double)up_total_tick/(double)up_total_floors<<"s/层   下楼"
	<<0.1*(double)down_total_tick/(double)down_total_floors<<"s/层\n";
	cout<<"电梯的平均耗时: 上楼"<<0.1*(double)up_total_tick_lift/(double)up_total_floors_lift<<"s/层   下楼"
	<<0.1*(double)down_total_tick_lift/(double)down_total_floors_lift<<"s/层\n";
	cout<<"楼梯的平均耗时: 上楼"<<0.1*double(up_total_tick-up_total_tick_lift)
	/double(up_total_floors-up_total_floors_lift)<<"s/层   下楼"
	<<0.1*double(down_total_tick-down_total_tick_lift)
	/double(down_total_floors-down_total_floors_lift)<<"s/层\n\n";

	cout<<"最长耗时: 上楼"<<up_max_time<<"s/层   下楼"<<down_max_time<<"s/层\n";
	cout<<"电梯的最长耗时: 上楼"<<up_max_time_lift<<"s/层   下楼"<<down_max_time_lift<<"s/层\n";
	cout<<"楼梯的最长耗时: 上楼"<<up_max_time_stairs<<"s/层   下楼"<<down_max_time_stairs<<"s/层\n\n";

	cout<<"最短耗时: 上楼"<<up_min_time<<"s/层   下楼"<<down_min_time<<"s/层\n";
	cout<<"电梯的最短耗时: 上楼"<<up_min_time_lift<<"s/层   下楼"<<down_min_time_lift<<"s/层\n";
	cout<<"楼梯的最短耗时: 上楼"<<up_min_time_stairs<<"s/层   下楼"<<down_min_time_stairs<<"s/层\n\n";

	std::string filename=std::to_string(rand_between(0,100000000))+".csv";
	std::ofstream fout(filename);
	fout<<"乘客,起点,终点,出现时刻,启程时刻,到达时刻,最大等待时间,乘坐电梯\n";
	while(!all_passengers.empty())
	{
		auto &p=all_passengers.front();
		fout<<p.first.ID<<","<<floor_name[p.first.source]<<","<<floor_name[p.first.destination]<<","
		<<p.first.appear_time<<","<<p.first.depart_time<<","<<p.first.arrive_time<<","<<p.first.tolerance_time<<","
		<<p.second<<"\n";
		all_passengers.pop();
	}
	fout.close();
	cout<<"详细信息见 "<<filename<<endl;
}

int main([[maybe_unused]]int argc,[[maybe_unused]]char **argv)
{
	std::cout<<std::setprecision(4)<<std::fixed;
#ifdef NDEBUG
	rand_engine.seed(std::random_device()());
#else
	auto seed=std::random_device()();
	std::cout<<"Seed: "<<seed<<"\n\n";
	rand_engine.seed(seed);
#endif
	load_constants();
	{
		using namespace variable;
		using constant::n_floors;
		waiting_queues_down.resize(n_floors);
		waiting_queues_up.resize(n_floors);
		for(auto &i:lifts)
			i.size_nfloors();
	}
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
