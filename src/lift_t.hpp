//lift_t.hpp: 电梯
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#pragma once
#include <cstdint>
#include "event_queue.hpp"

class wbutton_t;
//电梯
class lift_t
{
public:
	lift_t()=default;
	lift_t(const lift_t&)=delete;
	friend class wbutton_t;
	void press_floor(int floor);//按楼层键
	void press_close();//按关门键
private:
	void move_to(int floor);//移动到floor层
	void open_door();
	void close_door();
	bool m_is_door_open;//是否开门
	int16_t m_floor;//楼层
	int16_t m_direction;//移动方向：-1 0 1
	double m_carrying_weight;//载的乘客的质量
	uint64_t m_pressed_button;//按下的楼层按钮
};

//位于每层楼墙上的按钮
class wbutton_t
{
public:
	wbutton_t()=default;
	wbutton_t(const wbutton_t&)=delete;
	bool is_up_pressed(int floor)const;
	bool is_down_pressed(int floor)const;
	void press_up(int floor);
	void press_down(int floor);
	friend class lift_t;
private:
	void switch_off_up(int floor);//关闭向上的按钮，用lift_t类触发
	void switch_off_down(int floor);
	uint64_t m_up_pressed;//向上的按钮被按下
	uint64_t m_down_pressed;//向下的按钮被按下
};
