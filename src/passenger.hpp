//passenger.hpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#pragma once
#include <cstdint>
#include "event_queue.hpp"

struct passenger_t
{
	int32_t destination;
	uint32_t ID;
	double weight;
	uint64_t appear_time;
	static passenger_t generate(int32_t from,uint64_t appear_time);
};

//乘客出现事件
class event_passenger_appear:public event_t
{
public:
	//出现时间，乘坐电梯的起点
	event_passenger_appear(uint64_t time,int16_t src);
	void call()const override;
	bool print(std::ostream &)const override;
private:
	int16_t source;
	passenger_t passenger;
};
