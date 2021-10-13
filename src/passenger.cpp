//passenger.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#include "passenger.hpp"
#include "random.hpp"
#include "constants.hpp"
#include "variables.hpp"
#include "lift.hpp"

static uint32_t PID=0;

passenger_t passenger_t::generate(int16_t from,uint64_t appear_time)
{
	using namespace constant;
	if(from<=base_floor)
		return {from,rand_between<int16_t>(base_floor+1,max_floor),PID++,
			rand_between(passenger_weight_range),appear_time,0,0};
	else
		return {from,rand_between<int>(0,2)?rand_between(min_floor,base_floor):base_floor,PID++,
		rand_between(passenger_weight_range),appear_time,0,0};
}
