//lift.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#include "lift.hpp"
#include "constants.hpp"
#include "variables.hpp"
#include "random.hpp"
#include "cassert"

namespace
{
template<typename T>
T lowbit(T x){return x&-x;}
}

/////////////////////////////////////
//lift_t
/////////////////////////////////////
void lift_t::add_called_up_floor(uint64_t time,int16_t floor)
{
	m_called_up_floor|=(uint64_t)1<<(floor-constant::min_floor);
	m_waiting_floor=-1;
	variable::event_queue.push<event_check_lift_state>(time,this);
}

void lift_t::add_called_down_floor(uint64_t time,int16_t floor)
{
	m_called_down_floor|=(uint64_t)1<<(floor-constant::min_floor);
	m_waiting_floor=-1;
	variable::event_queue.push<event_check_lift_state>(time,this);
}

uint64_t lift_t::move_to_time(int16_t floor)
{
	//TODO
	return m_floor>=floor?(m_floor-floor)*constant::lift_down_tick:
		(floor-m_floor)*constant::lift_up_tick;
}

/////////////////////////////////////
//wbutton_t
/////////////////////////////////////

bool wbutton_t::is_up_pressed(int16_t floor)const
{
	return m_up_pressed&((uint64_t)1<<(floor-constant::min_floor));
}

bool wbutton_t::is_down_pressed(int16_t floor)const
{
	return m_down_pressed&((uint64_t)1<<(floor-constant::min_floor));
}

void wbutton_t::press_up(uint64_t time,int16_t floor)
{
	if(!is_up_pressed(floor))
	{
		using variable::lifts;
		m_up_pressed|=(uint64_t)1<<(floor-constant::min_floor);
		auto t0=lifts[0].move_to_time(floor),t1=lifts[1].move_to_time(floor);
		if(t0<t1||(t0==t1&&rand_between(0,1)))
			lifts[0].add_called_up_floor(time,floor);
		else lifts[1].add_called_up_floor(time,floor);
	}
}

void wbutton_t::press_down(uint64_t time,int16_t floor)
{
	if(!is_down_pressed(floor))
	{
		using variable::lifts;
		m_down_pressed|=(uint64_t)1<<(floor-constant::min_floor);
		auto t0=lifts[0].move_to_time(floor),t1=lifts[1].move_to_time(floor);
		if(t0<t1||(t0==t1&&rand_between(0,1)))
			lifts[0].add_called_down_floor(time,floor);
		else lifts[1].add_called_down_floor(time,floor);
	}
}

//////////////////////////////////////////
//event
//////////////////////////////////////////


event_press_wbutton::event_press_wbutton(uint64_t time,int16_t dire,int16_t floor):
	event_t(time,dire>0?"按下按钮↑":"按下按钮↓",(dire>0?"press_up":"press_down")+std::to_string(floor)),
	dire(dire),floor(floor){}

void event_press_wbutton::call()const
{
	using variable::wall_buttons;
	if(dire>0)wall_buttons.press_up(time,floor);
	else wall_buttons.press_down(time,floor);
}


event_check_lift_state::event_check_lift_state(uint64_t time,lift_t *which_lift):
	event_t(time,""),lift(which_lift){}

void event_check_lift_state::call()const
{
	//TODO
	//正在全速下降
	using variable::event_queue;
	if(lift->m_direction==-2)
	{
		//需要在当前楼层开门——减速
		if(lift->is_called_down()&&lift->m_carrying_weight<constant::full_weight
			||lift->is_pressed())
		{
			lift->m_waiting_floor=-1;
			event_queue.push<event_change_direction>(time+constant::lift_down_last_extra_tick,lift,-1);
		}
		//需要继续下降，并在底下的楼层开门
		else if(lift->is_called_down_lower()||lift->is_called_up_lower()||
			lift->is_pressed_lower())
		{
			lift->m_waiting_floor=-1;
			event_queue.push<event_arrive_at>(time+constant::lift_down_tick,lift,lift->m_floor-1);
		}
		//本层有人按↑
		else if(lift->is_called_up())
		{
			lift->m_waiting_floor=-1;
			event_queue.push<event_change_direction>(time+constant::lift_down_last_extra_tick,lift,1);
		}
		//上方有人呼叫电梯，需要先减速
		else if(lift->is_called_up_upper()||lift->is_called_down_upper())
		{
			assert(lift->m_waiting_floor!=-1);
			lift->m_waiting_floor=-1;
			//FIXME: constants.h中已指出，lift_down_last_extra_tick并不完全是由减速
			//引起的，其中还包含了开门的准备时间，而此时，电梯的减速并不是为开门做准备，所以
			//lift_down_last_extra_tick长于实际用时
			event_queue.push<event_change_direction>(time+constant::lift_down_last_extra_tick,lift,1);
		}
		//没有人呼叫电梯并且电梯正在返回待命层
		else if(lift->m_waiting_floor!=-1)
		{
			assert(constant::waiting_floor[lift->m_waiting_floor]<=lift->m_floor);
			if(constant::waiting_floor[lift->m_waiting_floor]==lift->m_floor)
				event_queue.push<event_change_direction>(time+constant::lift_down_last_extra_tick,lift,0);
			else
				event_queue.push<event_arrive_at>(time+constant::lift_down_tick,lift,lift->m_floor-1);
		}
		else assert(false);//不可能？
	}
	else if(lift->m_direction==2)
	{
		//需要在当前楼层开门——减速
		if(lift->is_called_up()&&lift->m_carrying_weight<constant::full_weight
			||lift->is_pressed())
		{
			lift->m_waiting_floor=-1;
			event_queue.push<event_change_direction>(time+constant::lift_up_last_extra_tick,lift,1);
		}
		//需要继续上升，并在顶上的楼层开门
		else if(lift->is_called_down_upper()||lift->is_called_up_upper()||
			lift->is_pressed_upper())
		{
			lift->m_waiting_floor=-1;
			event_queue.push<event_arrive_at>(time+constant::lift_up_tick,lift,lift->m_floor+1);
		}
		//本层有人按↓
		else if(lift->is_called_down())
		{
			lift->m_waiting_floor=-1;
			event_queue.push<event_change_direction>(time+constant::lift_up_last_extra_tick,lift,-1);
		}
		//下方有人呼叫电梯，需要先减速
		else if(lift->is_called_up_lower()||lift->is_called_down_lower()||lift->is_called_down())
		{
			assert(lift->m_waiting_floor!=-1);
			lift->m_waiting_floor=-1;
			//FIXME
			event_queue.push<event_change_direction>(time+constant::lift_up_last_extra_tick,lift,-1);
		}
		//没有人呼叫电梯并且电梯正在返回待命层
		else if(lift->m_waiting_floor!=-1)
		{
			assert(constant::waiting_floor[lift->m_waiting_floor]>=lift->m_floor);
			if(constant::waiting_floor[lift->m_waiting_floor]==lift->m_floor)
				event_queue.push<event_change_direction>(time+constant::lift_up_last_extra_tick,lift,0);
			else
				event_queue.push<event_arrive_at>(time+constant::lift_up_tick,lift,lift->m_floor+1);
		}
		else assert(false);//不可能？
	}
	else if(lift->m_direction==-1)
	{
		assert(lift->m_waiting_floor==-1);
		if(lift->m_is_door_open)
		{
			if(lift->m_passengers[lift->m_floor].size())
				event_queue.push<event_passenger_out>(time+rand_between(constant::iolift_tick_range),lift);
			else if(variable::waiting_queues_down[lift->m_floor].size())
			{
				auto &pass=variable::waiting_queues_down[lift->m_floor].front();
				//乘客已等待超时
				if(pass.appear_time+pass.tolerance_time<time)
				{
					event_queue.push<event_passenger_walk>(pass.appear_time+pass.tolerance_time,pass);
					variable::waiting_queues_down[lift->m_floor].pop();
				}
				//电梯没有满员
				else if(lift->m_carrying_weight<constant::full_weight)
					event_queue.push<event_passenger_in>(time+rand_between(constant::iolift_tick_range),lift);
				else
				{
					//电梯满员：电梯关门、乘客重新呼叫电梯
					event_queue.push<event_open_door>(time+constant::ocdoor_tick,lift,false);
					event_queue.push<event_press_wbutton>(time+constant::press_button_tick,-1,lift->m_floor);
				}
			}
			//没有人需要进出
			//TODO:在电梯内有人时会按关门键，否则等待auto_close_door_tick再关门
			else event_queue.push<event_open_door>(time+constant::ocdoor_tick,lift,false);
		}
		//需要在当前楼层开门
		else if(bool called_down=lift->is_called_down(),pressed=lift->is_pressed();
			!lift->m_is_door_open&&(called_down||pressed))
		{
			//如果电梯因呼叫而减速到-1，则其不可能满员
			assert(pressed||lift->m_carrying_weight<constant::full_weight);
			//熄灭按钮
			variable::wall_buttons.switch_off_down(time,lift->m_floor);
			lift->remove_pressed_button();
			event_queue.push<event_open_door>(time+constant::ocdoor_tick,lift,true);
		}
		//需要继续下降，并在底下的楼层开门
		else if(lift->is_called_down_lower()||lift->is_called_up_lower()||
			lift->is_pressed_lower())
		{
			event_queue.push<event_change_direction>(time+constant::lift_down_first_extra_tick,lift,-2);
		}
		else if(lift->is_called_down_upper()||lift->is_called_up_upper()||
			lift->is_pressed_upper())
		{
			event_queue.push<event_change_direction>(time+constant::lift_up_first_extra_tick,lift,2);
		}
		else
		{
			lift->m_direction=0;
		}
	}
	else if(lift->m_direction==1)
	{
		assert(lift->m_waiting_floor==-1);
		if(lift->m_is_door_open)
		{
			if(lift->m_passengers[lift->m_floor].size())
				event_queue.push<event_passenger_out>(time+rand_between(constant::iolift_tick_range),lift);
			else if(variable::waiting_queues_up[lift->m_floor].size())
			{
				auto &pass=variable::waiting_queues_up[lift->m_floor].front();
				//乘客已等待超时
				if(pass.appear_time+pass.tolerance_time<time)
				{
					event_queue.push<event_passenger_walk>(pass.appear_time+pass.tolerance_time,pass);
					variable::waiting_queues_up[lift->m_floor].pop();
				}
				//电梯没有满员
				else if(lift->m_carrying_weight<constant::full_weight)
					event_queue.push<event_passenger_in>(time+rand_between(constant::iolift_tick_range),lift);
				else
				{
					//电梯满员：电梯关门、乘客重新呼叫电梯
					event_queue.push<event_open_door>(time+constant::ocdoor_tick,lift,false);
					event_queue.push<event_press_wbutton>(time+constant::press_button_tick,1,lift->m_floor);
				}
			}
			//没有人需要进出
			//TODO:在电梯内有人时会按关门键，否则等待auto_close_door_tick再关门
			else event_queue.push<event_open_door>(time+constant::ocdoor_tick,lift,false);
		}
		//需要在当前楼层开门
		else if(bool called_up=lift->is_called_up(),pressed=lift->is_pressed();
			!lift->m_is_door_open&&(called_up||pressed))
		{
			//如果电梯因呼叫而减速到1，则其不可能满员
			assert(pressed||lift->m_carrying_weight<constant::full_weight);
			//熄灭按钮
			variable::wall_buttons.switch_off_up(time,lift->m_floor);
			lift->remove_pressed_button();
			event_queue.push<event_open_door>(time+constant::ocdoor_tick,lift,true);
		}
		//需要继续上升，并在顶上的楼层开门
		else if(lift->is_called_down_upper()||lift->is_called_up_upper()||
			lift->is_pressed_upper())
		{
			event_queue.push<event_change_direction>(time+constant::lift_up_first_extra_tick,lift,2);
		}
		else if(lift->is_called_down_lower()||lift->is_called_up_lower()||
			lift->is_pressed_lower())
		{
			event_queue.push<event_change_direction>(time+constant::lift_down_first_extra_tick,lift,-2);
		}
		else
		{
			lift->m_direction=0;
		}
	}
	else
	{
		assert(lift->m_direction==0);
		
	}
}

event_arrive_at::event_arrive_at(uint64_t time,lift_t *which_lift,int16_t floor):
	event_t(time,"电梯 #"+std::to_string(which_lift->m_liftID)+"到达 "+std::to_string(floor)+" 层",
	std::to_string(which_lift->m_liftID)+"arrive_at"+std::to_string(floor)),
	lift(which_lift),floor(floor){}

void event_arrive_at::call()const
{
	lift->m_floor=floor;
	variable::event_queue.push<event_check_lift_state>(time,lift);
}

event_change_direction::event_change_direction(uint64_t time,lift_t *which_lift,int16_t dire):
	event_t(time,"",std::to_string(which_lift->m_liftID)+"change_dire"+std::to_string(dire)),
	lift(which_lift),dire(dire){}

void event_change_direction::call()const
{
	lift->m_direction=dire;
	variable::event_queue.push<event_check_lift_state>(time,lift);
}	

event_open_door::event_open_door(uint64_t time,lift_t *which_lift,bool open):
	event_t(time,"电梯 #"+std::to_string(which_lift->m_liftID)+(open?"开门":"关门"),
	std::to_string(which_lift->m_liftID)+(open?"open_door":"close_door")),lift(which_lift),open(open){}

void event_open_door::call()const
{
	lift->m_is_door_open=open;
	variable::event_queue.push<event_check_lift_state>(time,lift);
}
