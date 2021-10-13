//variables.hpp: 变量
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#include "event_queue.hpp"
#include <array>
#include <unordered_set>
#include "lift.hpp"
#include "passenger.hpp"
#include "constants.hpp"

namespace variable
{
extern event_queue_t event_queue;		                //事件队列
//在每层楼的电梯口的排队的人
extern std::array<zzc::queue<passenger_t>,constant::max_floor-constant::min_floor+1> waiting_queues_up,waiting_queues_down;
extern wbutton_t wall_buttons;			                //每层楼墙上的按钮
extern std::array<lift_t,2> lifts;		                //两部电梯
}
