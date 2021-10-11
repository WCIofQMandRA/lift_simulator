//variables.cpp: 变量
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#include "variables.hpp"

namespace variable
{
event_queue_t event_queue;		//事件队列
//在每层楼的电梯口的排队的人
std::array<zzc::queue<passenger_t>,constant::max_floor-constant::min_floor+1> waiting_queues;
wbutton_t wall_buttons;			//每层楼墙上的按钮
std::array<lift_t,2> lifts;		//两部电梯
}
