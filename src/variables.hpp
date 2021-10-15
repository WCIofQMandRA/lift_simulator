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

namespace statistic
{
extern int up_total_passengers;                             //一天中出现的上楼乘客的总数
extern int up_total_passengers_lift;                        //坐电梯上楼的乘客的总数
extern int down_total_passengers,down_total_passengers_lift;
extern uint64_t up_total_tick,down_total_tick;              //总用时
extern uint64_t up_total_tick_lift,down_total_tick_lift;
extern double up_max_time,down_max_time;                    //最长用时
extern double up_max_time_lift,down_max_time_lift;
extern double up_min_time,down_min_time;                    //最短用时
extern double up_min_time_lift,down_min_time_lift;
extern uint64_t up_total_floors,down_total_floors;          //上升/下降的总楼层数
extern uint64_t up_total_floors_lift,down_total_floors_lift;
extern zzc::queue<std::pair<passenger_t,bool>> all_passengers;//一天内出现的所有乘客
}
