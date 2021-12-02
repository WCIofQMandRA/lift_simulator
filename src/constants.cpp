//constants.hpp: 常量
//Author: 张子辰
//This file is part of the 电梯模拟器.
//电梯模拟器 is released into public domain,
//see README.md for detail.

#include "constants.hpp"

namespace constant
{
double tick_time;
std::pair<uint64_t,uint64_t> iolift_tick_range;
uint64_t ocdoor_tick;
uint64_t press_close_extra_tick;
uint64_t auto_close_door_tick;
uint64_t return_waiting_floor_tick;
uint64_t lift_up_tick;
uint64_t lift_down_tick;
uint64_t lift_up_first_extra_tick;
uint64_t lift_up_last_extra_tick;
uint64_t lift_down_first_extra_tick;
uint64_t lift_down_last_extra_tick;
std::pair<uint64_t,uint64_t> walk_up_tick_range;
std::pair<uint64_t,uint64_t> walk_down_tick_range;
std::pair<uint64_t,uint64_t> walk_up_fl_extra;
std::pair<uint64_t,uint64_t> walk_down_fl_extra;
std::pair<double,double> tolerance_tick_rate_range;
uint64_t min_take_lift_up;
uint64_t min_take_lift_down;
uint64_t press_button_tick;

int16_t n_floors,base_floor;
zzc::vector<std::string> floor_name;
zzc::vector<int16_t> waiting_floor;
std::pair<double,double> passenger_weight_range;
std::pair<int,int> passenger_number_range;
std::pair<uint64_t,uint64_t> take_lift_time;

double full_weight;
}
