//lift.hpp: 电梯
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#pragma once
#include <cstdint>
#include "event_queue.hpp"
#include "preprocessor.h"

#define ADD_FRIEND_IMPL(x) friend class event_##x

#define ADD_FRIEND(...) ZZCPP_FOR_EACH(ADD_FRIEND_IMPL,;,__VA_ARGS__)

class wbutton_t;
class lift_t;

//检查电梯状态（电梯将决定继续移动还是停止）
class event_check_lift_state:public event_t
{
public:
	event_check_lift_state(uint64_t time,lift_t *which_lift);
	void call()const override;
	bool print(std::ostream&)const override{return false;}//不输出
private:
	
	lift_t *which_lift;
};

//令电梯位于指定层
class event_arrive_at:public event_t
{
public:
	event_arrive_at(uint64_t time,lift_t *which_lift,int16_t floor);
	void call()const override;
private:
	lift_t *which_lift;int16_t floor;
};

//电梯
//电梯的移动策略：
//1. 向一个方向移动，在每个途径的目标楼层开门，如果目标楼层墙上的按钮与m_direction一致，则将其熄灭，
// 直到到达这个方向上最后的目标楼层
//2. 清空m_pressed_button（这与包括z005的电梯在内的许多电梯的行为一致）
//3. 如果墙上的按钮没有按下，则将移动状态设为0；如果墙上m_direction方向的按钮按下，则继续向这个方向移动；
//  否则，将m_direction设置为-m_direction
class lift_t
{
public:
	friend class wbutton_t;
	ADD_FRIEND(check_lift_state,arrive_at);
	lift_t(int16_t ID):m_liftID(ID){}
	lift_t(const lift_t&)=delete;
	void press_floor(uint64_t time,int16_t floor);//按楼层键
	void press_close(uint64_t time);//按关门键
private:
	void add_called_floor(uint64_t time,int16_t floor);//将floor添加到m_called_floor中
	uint64_t move_to_time(int16_t floor);//查询移动到指定楼层的预期用时
	void open_door(uint64_t time);
	void close_door(uint64_t time);
	void move_to(uint64_t time,int16_t floor);//移动到指定楼层
	void check_state(uint64_t time);//检查状态
private:
	bool m_is_door_open=false;//是否开门
	int16_t m_floor=1;//楼层
	int16_t m_liftID;//电梯编号
	//移动方向：-2 -1 0 1 2
	//一次只能改变1，耗时：
	//-2 -> -1 lift_down_last_extra_tick
	//-1 -> -2 lift_down_first_extra_tick
	//2 -> 1 lift_up_last_extra_tick
	//1 -> 2 lift_up_first_extra_tick
	//0 -> 1/-1  1/-1 -> 0 无耗时
	int16_t m_direction=0;
	double m_carrying_weight=0;//载的乘客的质量
	uint64_t m_pressed_button=0;//按下的楼层按钮
	uint64_t m_called_floor=0;//呼叫电梯的楼层
};

//按下墙上的按钮
class event_press_wbutton:public event_t
{
public:
	//按下按钮的时间，方向，楼层
	event_press_wbutton(uint64_t time,int16_t dire,int16_t floor);
	void call()const override;
private:
	int16_t dire,floor;
};

//位于每层楼墙上的按钮
class wbutton_t
{
public:
	friend class lift_t;
	ADD_FRIEND(press_wbutton);
	wbutton_t()=default;
	wbutton_t(const wbutton_t&)=delete;
	bool is_up_pressed(int16_t floor)const;
	bool is_down_pressed(int16_t floor)const;
	void press_up(uint64_t time,int16_t floor);
	void press_down(uint64_t time,int16_t floor);
private:
	void switch_off_up(uint64_t time,int16_t floor);//关闭向上的按钮
	void switch_off_down(uint64_t time,int16_t floor);
private:
	uint64_t m_up_pressed;//向上的按钮被按下
	uint64_t m_down_pressed;//向下的按钮被按下
};
