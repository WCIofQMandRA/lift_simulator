//main.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#include "queue.hpp"
#include "passenger.hpp"
#include "lift.hpp"
#include "constants.hpp"
#include "variables.hpp"
#include "random.hpp"
#include <iostream>
#include <array>

//生成乘客
void generate_passengers()
{
	using namespace constant;
	int n_passengers=rand_between(passenger_number_range);
	while(n_passengers--)
	{
		int start;
		if(rand_between(0,1))
			start=rand_between(min_floor,base_floor);
		else start=rand_between<int16_t>(base_floor+1,max_floor);
		variable::event_queue.push(std::make_unique<event_passenger_appear>(rand_between(take_lift_time),start));
	}
}

int main([[maybe_unused]]int argc,[[maybe_unused]]char **argv)
{
	rand_engine.seed(std::random_device()());
	generate_passengers();
	using namespace variable;
	while(!event_queue.empty())
	{
		bool printed=event_queue.top()->print(std::cout);
		event_queue.top()->call();
		//call()函数可能有输出，所以在call之后才输出用于分割的空行
		if(printed)std::cout<<std::endl;
		event_queue.pop();
		if(printed)while(getchar()!='\n');
	}
	return 0;
}
