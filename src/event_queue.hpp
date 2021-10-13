//event_queue.hpp: 事件队列
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#pragma once
#include "queue.hpp"
#include <cstdint>
#include <string>
#include <iostream>
#include <memory>

//事件
class event_t
{
public:
	event_t(uint64_t time,const std::string &name);
	virtual void call()const=0;					//完成event需要进行的操作
	virtual bool print(std::ostream &)const;	//输出操作的情况, 返回是否真的输出了内容
	virtual ~event_t()=default;
	uint64_t time;								//事件发生的时间
	uint64_t order;								//事件被创建的顺序（用于确定同一时刻的多个事件的处理顺序）
	std::string name;							//事件名称
	//事件签名。对于持续性事件，有时需要知道事件是否“正在发生”，为此引入事件签名。
	//当事件开始发生时，事件签名被放入一个集合中，同时事件被放入事件队列，在调用call后，事件被从该集合中删去
	//在这个集合中的事件是正在发生的事件
	std::string signature;
protected:
	std::ostream& output_time(std::ostream &)const;	//以[hh:mm:ss]的格式输出时间
private:
	static uint64_t event_order;
};

class compare_event
{
public:
	bool operator()(const std::unique_ptr<event_t> &x,const std::unique_ptr<event_t> &y)const noexcept
	{
		return x->time==y->time?
			x->order>y->order : x->time>y->time;
	}
};

typedef zzc::priority_queue<std::unique_ptr<event_t>,compare_event> event_queue_t;
