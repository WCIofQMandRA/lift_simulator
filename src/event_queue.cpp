//event_queue.cpp: 事件队列
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#include "event_queue.hpp"

uint64_t event_t::event_order=0;

event_t::event_t(uint64_t time,const std::string &name,const std::string &sign):
	time(time),order(event_order++),name(name),signature(sign){}

bool event_t::print(std::ostream &os)const
{
	output_time(os<<"[",time)<<"]\t"<<name<<"\n";
	return true;
}

std::ostream& event_t::output_time(std::ostream &os,uint64_t time)const
{
	char t[]="hh:mm:ss.s";
	auto h=time;
	auto s=h%600;h/=600;
	auto m=h%60;h/=60;
	t[0]=static_cast<char>(h/10+48);
	t[1]=static_cast<char>(h%10+48);
	t[3]=static_cast<char>(m/10+48);
	t[4]=static_cast<char>(m%10+48);
	t[9]=static_cast<char>(s%10+48);
	s/=10;
	t[6]=static_cast<char>(s/10+48);
	t[7]=static_cast<char>(s%10+48);
	return os<<t;
}

std::unordered_set<std::string> event_queue_t::event_happening(256);

void event_queue_t::call_and_pop(std::ostream &os)
{
	//先erase再call,这样在call中就可以加入相同的事件
	event_happening.erase(qu.top()->signature);
	//由于event_passenger_walk的存在，call中插入的事件的优先级可能比top高
	auto top=std::move(const_cast<std::unique_ptr<event_t>&>(qu.top()));
	qu.pop();
	if(top->time==(8*3600+4*60+48)*10+9)
		std::cout<<"Attention!\n";
	top->call(os);
}
