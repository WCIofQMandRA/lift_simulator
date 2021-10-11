//passenger_t.cpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#include "passenger_t.hpp"
#include "random.hpp"
#include "constants.hpp"

passenger_t passenger_t::generate(int32_t from)
{
	using namespace constant;
	if(from<=base_floor)
		return {rand_between<int32_t>(base_floor+1,max_floor),rand_between(passenger_weight_range)};
	else
		return {rand_between<int>(0,2)?rand_between<int32_t>(min_floor,base_floor):base_floor,rand_between(passenger_weight_range)};
}
