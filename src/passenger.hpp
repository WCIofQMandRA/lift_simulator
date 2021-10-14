//passenger.hpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#pragma once
#include <cstdint>
#include "event_queue.hpp"

struct passenger_t
{
	int16_t source,destination;
	uint32_t ID;
	double weight;
	uint64_t appear_time;//出现时间
	uint64_t tolerance_time;//最大等待时间
	uint64_t arrive_time;//到达时间
	static passenger_t generate(int16_t from,uint64_t appear_time);
};

//乘客出现事件
class event_passenger_appear:public event_t
{
public:
	//出现时间，乘坐电梯的起点
	event_passenger_appear(uint64_t time,int16_t src);
	void call(std::ostream &os=std::cout)const override;
	bool print(std::ostream &os=std::cout)const override;
private:
	passenger_t passenger;
};

//乘客走楼梯, 这一事件无后效性，可以在任何时候处理
class event_passenger_walk:public event_t
{
public:
	event_passenger_walk(uint64_t time,const passenger_t &passenger);
	void call(std::ostream &os=std::cout)const override;
	bool print(std::ostream &os=std::cout)const override;
private:
	passenger_t passenger;
};

//乘客到达
class event_passenger_arrive:public event_t
{
public:
	event_passenger_arrive(const passenger_t &passenger,bool taking_lift);
	void call(std::ostream &os=std::cout)const override;
	bool print(std::ostream &os=std::cout)const override;
private:
	passenger_t passenger;
	bool taking_lift;
};
