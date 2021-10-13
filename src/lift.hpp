//lift.hpp: 电梯
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#pragma once
#include <cstdint>
#include "event_queue.hpp"
#include "passenger.hpp"
#include "preprocessor.h"
#include "constants.hpp"

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
	
	lift_t *lift;
};

//令电梯位于指定层
class event_arrive_at:public event_t
{
public:
	event_arrive_at(uint64_t time,lift_t *which_lift,int16_t floor);
	void call()const override;
private:
	lift_t *lift;int16_t floor;
};

//改变电梯的运动状态
class event_change_direction:public event_t
{
public:
	event_change_direction(uint64_t time,lift_t *which_lift,int16_t dire);
	void call()const override;
	bool print(std::ostream&)const override{return false;}
private:
	lift_t *lift;
	int16_t dire;
};

//电梯开关门
class event_open_door:public event_t
{
public:
	event_open_door(uint64_t time,lift_t *which_lift,bool open);
	void call()const override;
private:
	lift_t *lift;
	bool open;
};

//乘客出电梯
//乘客严格先下后上
class event_passenger_out:public event_t
{
public:
	event_passenger_out(uint64_t time,lift_t *which_lift);
	void call()const override;
private:
	lift_t *lift;
};

//乘客进电梯
class event_passenger_in:public event_t
{
public:
	event_passenger_in(uint64_t time,lift_t *which_lift);
	void call()const override;
private:
	lift_t *lift;
};

//检查电梯在一层的等待时间是否达到了return_waiting_floor_tick
class event_check_timeout:public event_t
{
public:
	event_check_timeout(uint64_t time,lift_t *which_lift);
	void call()const override;
	bool print(std::ostream&)const override{return false;}
private:
	lift_t *lift;
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
	ADD_FRIEND(check_lift_state,arrive_at,change_direction,open_door,
		passenger_out,passenger_in,check_timeout);
	lift_t(int16_t ID):m_liftID(ID){}
	lift_t(const lift_t&)=delete;
	void press_floor(uint64_t time,int16_t floor);//按楼层键
	void press_close(uint64_t time);//按关门键
private:
	void add_called_up_floor(uint64_t time,int16_t floor);//将floor添加到m_called_up_floor中
	void add_called_down_floor(uint64_t time,int16_t floor);
	void add_pressed_button(uint64_t time,int16_t floor);
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
	void open_door(uint64_t time);
	void close_door(uint64_t time);
	void move_to(uint64_t time,int16_t floor);//移动到指定楼层
	void check_state(uint64_t time);//检查状态
private:
	//TODO: 引入正在开门/关门的状态
	bool m_is_door_open=false,m_passenger_ioing=false;//是否开门, 乘客是否正在上下电梯
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
	int16_t m_direction=0;
	uint64_t m_begin_static_time=0;//开始处在静止状态的时刻
	double m_carrying_weight=0;//载的乘客的质量
	uint64_t m_pressed_button=0;//按下的楼层按钮
	uint64_t m_called_down_floor=0,m_called_up_floor=0;//呼叫电梯的楼层
	std::array<zzc::queue<passenger_t>,constant::max_floor-constant::min_floor+1> m_passengers;//电梯内的乘客
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
	ADD_FRIEND(press_wbutton,check_lift_state);
	wbutton_t()=default;
	wbutton_t(const wbutton_t&)=delete;
	bool is_up_pressed(int16_t floor)const;
	bool is_down_pressed(int16_t floor)const;
	//按下按钮↑，同时呼叫电梯
	void press_up(uint64_t time,int16_t floor);
	void press_down(uint64_t time,int16_t floor);
private:
	//关闭向上的按钮，同时取消电梯的被呼叫状态
	void switch_off_up(int16_t floor);
	void switch_off_down(int16_t floor);
private:
	uint64_t m_up_pressed;//向上的按钮被按下
	uint64_t m_down_pressed;//向下的按钮被按下
};
