//variables.cpp: 变量
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#include "variables.hpp"

namespace variable
{
uint64_t current_tick;
//在每层楼的电梯口的排队的人
std::array<zzc::queue<passenger_t>,constant::max_floor-constant::min_floor+1> waiting_queues_up,waiting_queues_down;
wbutton_t wall_buttons;			    //每层楼墙上的按钮
std::array<lift_t,2> lifts{0,1};	//两部电梯
}
