//passenger_t.hpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#pragma once
#include <cstdint>
#include <memeory>

struct passenger_t
{
	const int32_t destination;
	const double weight;
	static passenger_t generate(int32_t from);
};
