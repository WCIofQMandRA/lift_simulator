//random.hpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#pragma once
#include <random>
#include <cstdint>
#include <type_traits>

extern std::mt19937_64 rand_engine;

template<typename T,std::enable_if_t<std::is_integral_v<T>,int> U=0>
T rand_between(T a,T b)
{
	std::uniform_int_distribution<T> r(a,b);
	return r(rand_engine);
}

template<typename T,std::enable_if_t<std::is_floating_point_v<T>,int> U=1>
T rand_between(T a,T b)
{
	std::uniform_real_distribution<T> r(a,b);
	return r(rand_engine);
}

template<typename T>
T rand_between(const std::pair<T,T> &range)
{
	return rand_between(range.first,range.second);
}
