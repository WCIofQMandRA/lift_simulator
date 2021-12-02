#CMakeLists.txt
#Author: 张子辰
#This file is part of the 电梯模拟器.
#电梯模拟器 is released into public domain,
#see README.md for detail.

cmake_minimum_required(VERSION 3.4)
project(lift_simulator)
set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -Wpedantic -Wformat=2 -Wconversion)

set(OUTPUT_DIR ${CMAKE_BINARY_DIR}/output)

find_package(PkgConfig)
pkg_check_modules(gtkmm REQUIRED gtkmm-3.0)

add_subdirectory(src)
