//variables.cpp: 变量
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#include "variables.hpp"
#include <limits>

namespace variable
{
event_queue_t event_queue;		    //事件队列
//在每层楼的电梯口的排队的人
zzc::vector<zzc::queue<passenger_t>> waiting_queues_up,waiting_queues_down;
wbutton_t wall_buttons;			    //每层楼墙上的按钮
std::array<lift_t,2> lifts{0,1};	//两部电梯
std::unordered_set<std::string> event_happening(256);
}

namespace statistic
{
constexpr double inf=std::numeric_limits<double>::infinity();
int up_total_passengers=0;                          //一天中出现的上楼乘客的总数
int up_total_passengers_lift=0;                     //坐电梯上楼的乘客的总数
int down_total_passengers=0,down_total_passengers_lift=0;
uint64_t up_total_tick=0,down_total_tick=0;     //总用时
uint64_t up_total_tick_lift=0,down_total_tick_lift=0;
double up_max_time=0,down_max_time=0;         //最长用时
double up_max_time_lift=0,down_max_time_lift=0;
double up_max_time_stairs=0,down_max_time_stairs=0;
double up_min_time=inf,down_min_time=inf;       //最短用时
double up_min_time_lift=inf,down_min_time_lift=inf;
double up_min_time_stairs=inf,down_min_time_stairs=inf;
uint64_t up_total_floors=0,down_total_floors=0; //上升/下降的总楼层数
uint64_t up_total_floors_lift=0,down_total_floors_lift=0;
zzc::queue<std::pair<passenger_t,bool>> all_passengers;
}
