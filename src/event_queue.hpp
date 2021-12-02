//event_queue.hpp: 事件队列
//Author: 张子辰
//This file is part of the 电梯模拟器.
//电梯模拟器 is released into public domain,
//see README.md for detail.

#pragma once
#include "queue.hpp"
#include <cstdint>
#include <string>
#include <iostream>
#include <memory>
#include <cassert>
#include "plain_hash_table.hpp"

//事件
class event_t
{
public:
	event_t(uint64_t time,const std::string &name,const std::string &sign="");
	virtual void call(std::ostream &os=std::cout)const=0;	//完成event需要进行的操作
	virtual bool print(std::ostream &os=std::cout)const;	//输出操作的情况, 返回是否真的输出了内容
	virtual ~event_t()=default;
	uint64_t time;								//事件发生的时间
	uint64_t order;								//事件被创建的顺序（用于确定同一时刻的多个事件的处理顺序）
	std::string name;							//事件名称
	//事件签名。对于持续性事件，有时需要知道事件是否“正在发生”，为此引入事件签名。
	//当事件开始发生时，事件签名被放入一个集合中，同时事件被放入事件队列，在调用call后，事件被从该集合中删去
	//在这个集合中的事件是正在发生的事件
	//事实上，除了event_passenger_appear外，所有事件在加入event_queue时开始发送
	std::string signature;
protected:
	std::ostream& output_time(std::ostream &,uint64_t)const;	//以[hh:mm:ss]的格式输出时间
private:
	static uint64_t event_order;
};

//事件队列
class event_queue_t
{
public:
	event_queue_t()=default;
	template<typename Event,typename... Args>
	void push(Args &&...args)
	{
		auto new_event=std::make_unique<Event>(std::forward<Args>(args)...);
		if(new_event->signature!=""&&event_happening.count(new_event->signature))return;
		event_happening.insert(new_event->signature);
		qu.push(std::move(new_event));
	}
	void call_and_pop(std::ostream &os=std::cout);
	bool print(std::ostream &os)
	{
		return qu.top()->print(os);
	}
	bool empty()noexcept
	{
		return qu.empty();
	}
private:
	class compare_event
	{
	public:
		bool operator()(const std::unique_ptr<event_t> &x,const std::unique_ptr<event_t> &y)const noexcept
		{
			return x->time==y->time?
				x->order>y->order : x->time>y->time;
		}
	};
	zzc::priority_queue<std::unique_ptr<event_t>,compare_event> qu;
	static plain_hash_table event_happening;
};
