//passenger.hpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#pragma once
#include <cstdint>

struct passenger_t
{
	int16_t source,destination;
	uint32_t ID;
	double weight;
	uint64_t appear_time;
	static passenger_t generate(int16_t from,uint64_t appear_time);
};
