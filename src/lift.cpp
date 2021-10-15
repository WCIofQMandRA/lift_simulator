//lift.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#include "lift.hpp"
#include "constants.hpp"
#include "variables.hpp"
#include "random.hpp"
#include "cassert"

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

void lift_t::add_pressed_button(uint64_t time,int16_t floor)
{
	m_pressed_button|=(uint64_t)1<<(floor-constant::min_floor);
	m_waiting_floor=-1;
	variable::event_queue.push<event_check_lift_state>(time,this);
}

void lift_t::remove_called_up_floor()
{
	m_called_up_floor&=~((uint64_t)1<<(m_floor-constant::min_floor));
}
void lift_t::remove_called_down_floor()
{
	m_called_down_floor&=~((uint64_t)1<<(m_floor-constant::min_floor));
}
void lift_t::remove_called_up_floor(int16_t floor)
{
	m_called_up_floor&=~((uint64_t)1<<(floor-constant::min_floor));
}
void lift_t::remove_called_down_floor(int16_t floor)
{
	m_called_down_floor&=~((uint64_t)1<<(floor-constant::min_floor));
}
void lift_t::remove_pressed_button()
{
	m_pressed_button&=~((uint64_t)1<<(m_floor-constant::min_floor));
}
bool lift_t::is_pressed()
{
	return m_pressed_button&((uint64_t)1<<(m_floor-constant::min_floor));
}
bool lift_t::is_pressed_lower()
{
	//避免出现左移64位（此时实际左移了64mod64=0位）
	return m_floor!=constant::min_floor&&m_pressed_button<<(64-(m_floor-constant::min_floor))!=0;
}
bool lift_t::is_pressed_upper()
{
	return m_pressed_button>>(m_floor-constant::min_floor+1)!=0;
}
bool lift_t::is_called_up()
{
	return m_called_up_floor&((uint64_t)1<<(m_floor-constant::min_floor));
}
bool lift_t::is_called_up_lower()
{
	return m_floor!=constant::min_floor&&m_called_up_floor<<(64-(m_floor-constant::min_floor))!=0;
}
bool lift_t::is_called_up_upper()
{
	return m_called_up_floor>>(m_floor-constant::min_floor+1)!=0;
}
bool lift_t::is_called_down()
{
	return m_called_down_floor&((uint64_t)1<<(m_floor-constant::min_floor));
}
bool lift_t::is_called_down_lower()
{
	return m_floor!=constant::min_floor&&m_called_down_floor<<(64-(m_floor-constant::min_floor))!=0;
}
bool lift_t::is_called_down_upper()
{
	return m_called_down_floor>>(m_floor-constant::min_floor+1)!=0;
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

void wbutton_t::switch_off_up(int16_t floor)
{
	m_up_pressed&=~((uint64_t)1<<(floor-constant::min_floor));
	for(auto &i:variable::lifts)
		i.remove_called_up_floor(floor);
}
void wbutton_t::switch_off_down(int16_t floor)
{
	m_down_pressed&=~((uint64_t)1<<(floor-constant::min_floor));
	for(auto &i:variable::lifts)
		i.remove_called_down_floor(floor);
}

//////////////////////////////////////////
//event
//////////////////////////////////////////


event_press_wbutton::event_press_wbutton(uint64_t time,int16_t dire,int16_t floor):
	event_t(time,dire>0?"按下按钮↑":"按下按钮↓",(dire>0?"press_up":"press_down")+std::to_string(floor)),
	dire(dire),floor(floor){}

void event_press_wbutton::call(std::ostream&)const
{
	using variable::wall_buttons;
	if(dire>0)wall_buttons.press_up(time,floor);
	else wall_buttons.press_down(time,floor);
}


event_check_lift_state::event_check_lift_state(uint64_t time,lift_t *which_lift):
	event_t(time,""),lift(which_lift){}

void event_check_lift_state::call(std::ostream &os)const
{
	//TODO
	//正在全速下降
	using variable::event_queue;
	if(lift->m_direction==-2)
	{
		//需要在当前楼层开门——减速
		if((lift->is_called_down()&&lift->m_carrying_weight<constant::full_weight)
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
			//呼叫电梯的函数已经把m_waiting_floor设置为-1，所以这个assertion一定失败
			//assert(lift->m_waiting_floor!=-1);
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
			{
				os<<"电梯 #"<<std::to_string(lift->m_liftID)<<"到达待命楼层.\n";
				event_queue.push<event_change_direction>(time+constant::lift_down_last_extra_tick,lift,0);
			}
			else
				event_queue.push<event_arrive_at>(time+constant::lift_down_tick,lift,lift->m_floor-1);
		}
		else assert(false);//不可能？
	}
	else if(lift->m_direction==2)
	{
		//需要在当前楼层开门——减速
		if((lift->is_called_up()&&lift->m_carrying_weight<constant::full_weight)
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
			//呼叫电梯的函数已经把m_waiting_floor设置为-1，所以这个assertion一定失败
			//assert(lift->m_waiting_floor!=-1);
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
			if(lift->m_passengers[lift->m_floor-constant::min_floor].size())
				event_queue.push<event_passenger_out>(time+rand_between(constant::iolift_tick_range),lift);
			else if(variable::waiting_queues_down[lift->m_floor-constant::min_floor].size())
			{
				auto &pass=variable::waiting_queues_down[lift->m_floor-constant::min_floor].front();
				//乘客已等待超时
				if(pass.appear_time+pass.tolerance_time<time)
				{
					event_queue.push<event_passenger_walk>(pass.appear_time+pass.tolerance_time,pass);
					variable::waiting_queues_down[lift->m_floor-constant::min_floor].pop();
				}
				//电梯没有满员
				else if(lift->m_carrying_weight<constant::full_weight)
					event_queue.push<event_passenger_in>(time+rand_between(constant::iolift_tick_range),lift,-1);
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
			variable::wall_buttons.switch_off_down(lift->m_floor);
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
			lift->m_begin_static_time=time;
			event_queue.push<event_check_lift_state>(time,lift);
		}
	}
	else if(lift->m_direction==1)
	{
		assert(lift->m_waiting_floor==-1);
		if(lift->m_is_door_open)
		{
			if(lift->m_passengers[lift->m_floor-constant::min_floor].size())
				event_queue.push<event_passenger_out>(time+rand_between(constant::iolift_tick_range),lift);
			else if(variable::waiting_queues_up[lift->m_floor-constant::min_floor].size())
			{
				auto &pass=variable::waiting_queues_up[lift->m_floor-constant::min_floor].front();
				//乘客已等待超时
				if(pass.appear_time+pass.tolerance_time<time)
				{
					event_queue.push<event_passenger_walk>(pass.appear_time+pass.tolerance_time,pass);
					variable::waiting_queues_up[lift->m_floor-constant::min_floor].pop();
				}
				//电梯没有满员
				else if(lift->m_carrying_weight<constant::full_weight)
					event_queue.push<event_passenger_in>(time+rand_between(constant::iolift_tick_range),lift,1);
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
			variable::wall_buttons.switch_off_up(lift->m_floor);
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
			lift->m_begin_static_time=time;
			event_queue.push<event_check_lift_state>(time,lift);
		}
	}
	else
	{
		assert(lift->m_direction==0);
		assert(lift->m_pressed_button==0);
		assert(fabs(lift->m_carrying_weight)<1e-6);
		//本层楼有人呼叫电梯
		if(lift->is_called_down())
		{
			lift->m_waiting_floor=-1;
			if(!lift->is_called_up()||rand_between(0,1))
				lift->m_direction=-1;
			else lift->m_direction=1;
			event_queue.push<event_check_lift_state>(time,lift);
		}
		else if(lift->is_called_up())
		{
			lift->m_waiting_floor=-1;
			lift->m_direction=1;
			event_queue.push<event_check_lift_state>(time,lift);
		}
		//下方的楼层有人呼叫电梯
		else if(lift->is_called_down_lower()||lift->is_called_up_lower())
		{
			lift->m_waiting_floor=-1;
			if(!(lift->is_called_down_upper()||lift->is_called_up_upper())||rand_between(0,1))
				event_queue.push<event_change_direction>(time+constant::lift_down_first_extra_tick,lift,-2);
			else event_queue.push<event_change_direction>(time+constant::lift_up_first_extra_tick,lift,2);
		}
		//上方的楼层有人呼叫电梯
		else if(lift->is_called_down_upper()||lift->is_called_up_upper())
		{
			lift->m_waiting_floor=-1;
			event_queue.push<event_change_direction>(time+constant::lift_up_first_extra_tick,lift,2);
		}
		else if(lift->m_waiting_floor==-1)
		{
			if(lift->m_begin_static_time+constant::return_waiting_floor_tick<=time)
			{
				auto another_lift=&variable::lifts[1-lift->m_liftID];
				switch (another_lift->m_waiting_floor)
				{
				case 0:lift->m_waiting_floor=1;break;
				case 1:lift->m_waiting_floor=0;break;
				default:
				{
					auto d0=std::abs(lift->m_floor-constant::waiting_floor[0]);
					auto d1=std::abs(lift->m_floor-constant::waiting_floor[1]);
					//优先在waiting_floor[0]层等待
					lift->m_waiting_floor=d0<=d1?0:1;
				}
				}
				if(constant::waiting_floor[lift->m_waiting_floor]<lift->m_floor)
				{
					os<<"电梯 #"<<std::to_string(lift->m_liftID)<<"前往待命楼层.\n";
					event_queue.push<event_change_direction>(time+constant::lift_down_first_extra_tick,lift,-2);
				}
				else if(constant::waiting_floor[lift->m_waiting_floor]>lift->m_floor)
				{
					os<<"电梯 #"<<std::to_string(lift->m_liftID)<<"前往待命楼层.\n";
					event_queue.push<event_change_direction>(time+constant::lift_up_first_extra_tick,lift,2);
				}
				//否则电梯已位于待命楼层
			}
			else event_queue.push<event_check_timeout>(lift->m_begin_static_time+constant::return_waiting_floor_tick,lift);
		}
	}
}

event_arrive_at::event_arrive_at(uint64_t time,lift_t *which_lift,int16_t floor):
	event_t(time,"电梯 #"+std::to_string(which_lift->m_liftID)+"到达 "+std::to_string(floor)+" 层",
	std::to_string(which_lift->m_liftID)+"arrive_at"+std::to_string(floor)),
	lift(which_lift),floor(floor){}

void event_arrive_at::call(std::ostream&)const
{
	lift->m_floor=floor;
	variable::event_queue.push<event_check_lift_state>(time,lift);
}

event_change_direction::event_change_direction(uint64_t time,lift_t *which_lift,int16_t dire):
	event_t(time,"",std::to_string(which_lift->m_liftID)+"change_dire"+std::to_string(dire)),
	lift(which_lift),dire(dire){}

void event_change_direction::call(std::ostream&)const
{
	lift->m_direction=dire;
	variable::event_queue.push<event_check_lift_state>(time,lift);
}	

event_open_door::event_open_door(uint64_t time,lift_t *which_lift,bool open):
	event_t(time,"电梯 #"+std::to_string(which_lift->m_liftID)+(open?"开门":"关门"),
	std::to_string(which_lift->m_liftID)+(open?"open_door":"close_door")),lift(which_lift),open(open){}

void event_open_door::call(std::ostream&)const
{
	lift->m_is_door_open=open;
	variable::event_queue.push<event_check_lift_state>(time,lift);
}

event_passenger_out::event_passenger_out(uint64_t time,lift_t *which_lift):
	event_t(time,"乘客出电梯 #"+std::to_string(which_lift->m_liftID),
	"passengerio"+std::to_string(which_lift->m_liftID)),lift(which_lift){}

void event_passenger_out::call(std::ostream &os)const
{
	auto pass=lift->m_passengers[lift->m_floor-constant::min_floor].front();
	lift->m_passengers[lift->m_floor-constant::min_floor].pop();
	lift->m_carrying_weight-=pass.weight;
	os<<"乘客信息: #"<<pass.ID<<", "<<pass.source<<"->"<<pass.destination<<", "<<pass.weight<<"kg\n";
	pass.arrive_time=time;
	variable::event_queue.push<event_passenger_arrive>(pass,true);
	variable::event_queue.push<event_check_lift_state>(time,lift);
}

event_passenger_in::event_passenger_in(uint64_t time,lift_t *which_lift,int16_t dire):
	event_t(time,"乘客进电梯 #"+std::to_string(which_lift->m_liftID),
	"passengerio"+std::to_string(which_lift->m_liftID)),lift(which_lift),dire(dire){}

void event_passenger_in::call(std::ostream &os)const
{
	if(dire>0)
	{
		auto &pass=variable::waiting_queues_up[lift->m_floor-constant::min_floor].front();
		os<<"乘客信息: #"<<pass.ID<<", "<<pass.source<<"->"<<pass.destination<<", "<<pass.weight<<"kg\n";
		lift->m_carrying_weight+=pass.weight;
		lift->m_passengers[pass.destination-constant::min_floor].push(pass);
		//把乘客按电梯内的楼层按钮的时间也算在进入电梯的时间中，故直接用time
		lift->add_pressed_button(time,pass.destination);
		variable::waiting_queues_up[lift->m_floor].pop();
	}
	else
	{
		auto &pass=variable::waiting_queues_down[lift->m_floor-constant::min_floor].front();
		os<<"乘客信息: #"<<pass.ID<<", "<<pass.source<<"->"<<pass.destination<<", "<<pass.weight<<"kg\n";
		lift->m_carrying_weight+=pass.weight;
		lift->m_passengers[pass.destination-constant::min_floor].push(pass);
		lift->add_pressed_button(time,pass.destination);
		variable::waiting_queues_down[lift->m_floor].pop();
	}
	variable::event_queue.push<event_check_lift_state>(time,lift);
}

event_check_timeout::event_check_timeout(uint64_t time,lift_t *which_lift):
	event_t(time,""),lift(which_lift){}

void event_check_timeout::call(std::ostream&)const
{
	if(lift->m_direction==0&&lift->m_begin_static_time+constant::return_waiting_floor_tick<=time)
	{
		assert(lift->m_called_down_floor==0);
		assert(lift->m_called_up_floor==0);
		assert(lift->m_pressed_button==0);
		variable::event_queue.push<event_check_lift_state>(time,lift);
	}
}
