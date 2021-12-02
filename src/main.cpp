//main.cpp
//Author: 张子辰
//This file is part of the 电梯模拟器.
//电梯模拟器 is released into public domain,
//see README.md for detail.

#include <fstream>
#include <cstdlib>
#include <filesystem>
#include "config_paser.hpp"
#include "mainwindow.hpp"
#include "preprocessor.h"
#include "constants.hpp"
#include "variables.hpp"
#include "random.hpp"
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

int main(int argc,char **argv)
{
	std::cout<<std::setprecision(4)<<std::fixed;
	variable::random_seed=argc==2?std::stoull(argv[1]):std::random_device()();
//	std::cout<<"Seed: "<<variable::random_seed<<"\n\n";
	rand_engine.seed(variable::random_seed);
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

////////////////////////////////
	auto app=Gtk::Application::create();
	gui::mainwindow window;
	return app->run(window);
}
