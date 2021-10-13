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
	uint64_t appear_time;//出现时间
	uint64_t tolerence_time;//最大等待时间
	uint64_t arrive_time;//到达时间
	static passenger_t generate(int16_t from,uint64_t appear_time);
};
