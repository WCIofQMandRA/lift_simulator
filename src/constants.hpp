//constants.hpp: 常量
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#pragma once
#include <cstdint>
#include <utility>
#include <array>
namespace constant
{
constexpr double tick_time=0.1;//一个基本时间单位的长度
constexpr std::pair<uint64_t,uint64_t> iolift_tick_range={5,30};//人进出电梯的时间
constexpr uint64_t ocdoor_tick=25;//电梯开关门的时间
constexpr uint64_t press_close_extra_tick=31;//从按关门键到开始关门的时间
//无人进出而自动关门的时间
//在实际测量时差异很大：
//当来自电梯内的请求使电梯开门且只出来一个人时，为111
//当来自电梯内的请求使电梯开门且出来多个人时，为30
//当来自电梯外的请求使电梯开门且无人进出时，为48
//为了简便，姑且取35
constexpr uint64_t auto_close_door_tick=35;
constexpr uint64_t return_waiting_floor_tick=330;//回到待命层的时间
constexpr uint64_t lift_up_tick=21;//电梯向上移动一层的时间
constexpr uint64_t lift_down_tick=21;//电梯向下移动一层的时间
constexpr uint64_t lift_up_first_extra_tick=32;//向上移动的首层的额外时间（电梯加速需要时间）
constexpr uint64_t lift_up_last_extra_tick=55;//向上移动的末层的额外时间（似乎并不是完全由减速引起的，电梯停稳后过了一会儿才开门）
constexpr uint64_t lift_down_first_extra_tick=32;//向下移动的首层的额外时间
constexpr uint64_t lift_down_last_extra_tick=55;//向下移动的末层的额外时间
constexpr std::pair<uint64_t,uint64_t> walk_up_tick_range={99,150};//走楼梯上一层楼的时间
constexpr std::pair<uint64_t,uint64_t> walk_down_tick_range={80,132};//走楼梯下一层楼的时间
constexpr std::pair<uint64_t,uint64_t> walk_up_fl_extra={10,50};//上楼时，从楼梯口走到楼梯和从楼梯走到楼梯口的额外时间
constexpr std::pair<uint64_t,uint64_t> walk_down_fl_extra={20,45};
constexpr std::pair<double,double> tolerance_tick_rate_range={0.2,0.6};//等待电梯的忍耐时间与走楼梯前往目标楼层的时间的比
constexpr uint64_t min_take_lift_up=4;//上楼时，选择乘坐电梯的最小楼层差
constexpr uint64_t min_take_lift_down=5;//下楼时，选择乘坐电梯的最小楼层差
constexpr uint64_t press_button_tick=10;//乘客从按下呼叫电梯的按钮的耗时

constexpr int16_t max_floor=12,min_floor=0,base_floor=1;
constexpr std::array<int16_t,2> waiting_floor={1,7};//待命楼层
constexpr std::pair<double,double> passenger_weight_range={40,80};//乘客质量
#ifdef NDEBUG
constexpr std::pair<int,int> passenger_number_range={2800,4000};//一天进出楼的人数
#else
constexpr std::pair<int,int> passenger_number_range={100,150};//一天进出楼的人数
#endif
constexpr std::pair<uint64_t,uint64_t> take_lift_time={216000,828000};//一天内有人坐电梯的时段

constexpr double max_weight=1000;//电梯载重量
}
