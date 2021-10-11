//random.hpp
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#pragma once
#include <random>
#include <cstdint>
#include <type_traits>

extern mt19937_64 rand_engine;

template<typename T,typename U=std::enable_if_t<is_integral_v<T>,T>>
U rand_between(T a,T b)
{
	std::uniform_int_distribution<U> r(a,b);
	return r(rand_engine);
}

template<typename T,typename U=std::enable_if_t<is_floating_point_v<T>,T>>
U rand_between(T a,T b)
{
	std::uniform_real_distribution<U> r(a,b);
	return r(rand_engine);
}

template<typename T>
T rand_between(const std::pair<T,T> &range)
{
	return rand_between(range.first,range.second);
}
