#src/CMakeLists.txt
#Copyright 2021-2022 张子辰
#This file is part of the 电梯模拟器.

aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRC_LIFT)

add_executable(lift_simulator ${SRC_LIFT})
target_compile_options(lift_simulator PRIVATE ${gtkmm_CFLAGS})
target_link_libraries(lift_simulator ${gtkmm_LDFLAGS})

set_target_properties(lift_simulator PROPERTIES BUILD_WITH_INSTALL_RPATH TRUE)
set_target_properties(lift_simulator PROPERTIES INSTALL_RPATH "\$ORIGIN/lib")

set_property(TARGET lift_simulator PROPERTY RUNTIME_OUTPUT_DIRECTORY $<1:${OUTPUT_DIR}>)
