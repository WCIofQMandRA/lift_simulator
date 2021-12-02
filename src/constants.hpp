//constants.hpp: 常量，指在模拟电梯运行期间不改变的量，并非带const限定符的变量
//Author: 张子辰
//This file is part of the 电梯模拟器.
//电梯模拟器 is released into public domain,
//see README.md for detail.

#pragma once
#include <cstdint>
#include <utility>
#include "vector.hpp"
#include <string>
namespace constant
{
extern double tick_time;//一个基本时间单位的长度
extern std::pair<uint64_t,uint64_t> iolift_tick_range;//人进出电梯的时间
extern uint64_t ocdoor_tick;//电梯开关门的时间
extern uint64_t press_close_extra_tick;//从按关门键到开始关门的时间
//无人进出而自动关门的时间
//在实际测量时差异很大：
//当来自电梯内的请求使电梯开门且只出来一个人时，为111
//当来自电梯内的请求使电梯开门且出来多个人时，为30
//当来自电梯外的请求使电梯开门且无人进出时，为48
//为了简便，姑且取35
extern uint64_t auto_close_door_tick;
extern uint64_t return_waiting_floor_tick;//回到待命层的时间
extern uint64_t lift_up_tick;//电梯向上移动一层的时间
extern uint64_t lift_down_tick;//电梯向下移动一层的时间
extern uint64_t lift_up_first_extra_tick;//向上移动的首层的额外时间（电梯加速需要时间）
extern uint64_t lift_up_last_extra_tick;//向上移动的末层的额外时间（似乎并不是完全由减速引起的，电梯停稳后过了一会儿才开门）
extern uint64_t lift_down_first_extra_tick;//向下移动的首层的额外时间
extern uint64_t lift_down_last_extra_tick;//向下移动的末层的额外时间
extern std::pair<uint64_t,uint64_t> walk_up_tick_range;//走楼梯上一层楼的时间
extern std::pair<uint64_t,uint64_t> walk_down_tick_range;//走楼梯下一层楼的时间
extern std::pair<uint64_t,uint64_t> walk_up_fl_extra;//上楼时，从楼梯口走到楼梯和从楼梯走到楼梯口的额外时间
extern std::pair<uint64_t,uint64_t> walk_down_fl_extra;
extern std::pair<double,double> tolerance_tick_rate_range;//等待电梯的忍耐时间与走楼梯前往目标楼层的时间的比
extern uint64_t min_take_lift_up;//上楼时，选择乘坐电梯的最小楼层差
extern uint64_t min_take_lift_down;//下楼时，选择乘坐电梯的最小楼层差
extern uint64_t press_button_tick;//乘客从按下呼叫电梯的按钮的耗时

extern int16_t n_floors,base_floor;
extern zzc::vector<std::string>floor_name;
extern zzc::vector<int16_t> waiting_floor;//待命楼层, 按优先级从高到低排序
extern std::pair<double,double> passenger_weight_range;//乘客质量
extern std::pair<int,int> passenger_number_range;//一天进出楼的人数
extern std::pair<uint64_t,uint64_t> take_lift_time;//一天内有人坐电梯的时段

extern double full_weight;//电梯显示满员时的载重量
}
