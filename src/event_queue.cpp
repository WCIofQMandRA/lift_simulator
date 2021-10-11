//event_queue.cpp: 事件队列
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#include "event_queue.hpp"

uint64_t event_t::event_order=0;

event_t::event_t(uint64_t time,const std::string &name):
	time(time),order(event_order++),name(name){}

void event_t::print(std::ostream &os)const
{
	output_time(os)<<"\t"<<name<<"\n";
}

std::ostream& event_t::output_time(std::ostream &os)const
{
	char t[]="[hh:mm:ss.s]";
	auto h=this->time;
	auto s=h%600;h/=600;
	auto m=h%60;h/=60;
	t[1]=static_cast<char>(h/10+48);
	t[2]=static_cast<char>(h%10+48);
	t[4]=static_cast<char>(m/10+48);
	t[5]=static_cast<char>(m%10+48);
	t[10]=static_cast<char>(s%10+48);
	s/=10;
	t[7]=static_cast<char>(s/10+48);
	t[8]=static_cast<char>(s%10+48);
	return os<<t;
}
