//lift.hpp: 电梯
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#pragma once
#include <cstdint>

class wbutton_t;
class lift_t;

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
	lift_t(int16_t ID):m_liftID(ID){}
	lift_t(const lift_t&)=delete;
	void press_floor(int16_t floor);//按楼层键
	void press_close();//按关门键
private:
	void add_called_up_floor(int16_t floor);//将floor添加到m_called_up_floor中
	void add_called_down_floor(int16_t floor);
	void add_pressed_button(int16_t floor);
	void remove_called_up_floor();
	void remove_called_down_floor();
	void remove_pressed_button();
	bool is_pressed();//电梯内的m_floor层按钮是否被按下
	bool is_pressed_lower();//电梯内，在m_floor层下方的按钮是否被按下
	bool is_pressed_upper();//电梯内，在m_floor层上方的按钮是否被按下
	bool is_called_up();//位于m_floor层的墙上的↑按钮是否被按下
	bool is_called_up_lower();
	bool is_called_up_upper();
	bool is_called_down();
	bool is_called_down_lower();
	bool is_called_down_upper();
	uint64_t move_to_time(int16_t floor);//查询移动到指定楼层的预期用时
	void open_door();
	void close_door();
	void move_to(int16_t floor);//移动到指定楼层
	void check_state();//检查状态
private:
	bool m_is_door_open=false;//是否开门
	//若电梯正在返回或已经位于待命层，则为0/1，否则为-1
	//电梯的待命层为waiting_floor[m_waiting_floor]
	int16_t m_waiting_floor=-1;
	int16_t m_floor=1;//楼层
	int16_t m_liftID;//电梯编号
	//移动方向：-2 -1 0 1 2
	//耗时：
	//-2 -> -1 lift_down_last_extra_tick
	//-1 -> -2 lift_down_first_extra_tick
	//2 -> 1 lift_up_last_extra_tick
	//1 -> 2 lift_up_first_extra_tick
	//±2 <-> 其他 不允许
	//其他 无耗时
	int16_t m_direction=0;
	double m_carrying_weight=0;//载的乘客的质量
	uint64_t m_pressed_button=0;//按下的楼层按钮
	uint64_t m_called_down_floor=0,m_called_up_floor=0;//呼叫电梯的楼层
};

//位于每层楼墙上的按钮
class wbutton_t
{
public:
	friend class lift_t;
	wbutton_t()=default;
	wbutton_t(const wbutton_t&)=delete;
	bool is_up_pressed(int16_t floor)const;
	bool is_down_pressed(int16_t floor)const;
	void press_up(int16_t floor);
	void press_down(int16_t floor);
private:
	void switch_off_up(int16_t floor);//关闭向上的按钮
	void switch_off_down(int16_t floor);
private:
	uint64_t m_up_pressed;//向上的按钮被按下
	uint64_t m_down_pressed;//向下的按钮被按下
};
