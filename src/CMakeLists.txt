#src/CMakeLists.txt
#Author: 张子辰
#This file is part of the 电梯模拟器.
#电梯模拟器 is released into public domain,
#see README.md for detail.

aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRC_LIFT)

add_executable(lift_simulator ${SRC_LIFT})
target_compile_options(lift_simulator PRIVATE ${gtkmm_CFLAGS})
target_include_directories(lift_simulator PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../ext)
target_link_libraries(lift_simulator -pthread ${gtkmm_LDFLAGS})

set_target_properties(lift_simulator PROPERTIES BUILD_WITH_INSTALL_RPATH TRUE)
set_target_properties(lift_simulator PROPERTIES INSTALL_RPATH "\$ORIGIN/../lib")
file(COPY ${CMAKE_CURRENT_LIST_DIR}/constants.ini DESTINATION ${OUTPUT_DIR}/etc/lift_simulator)

set_property(TARGET lift_simulator PROPERTY RUNTIME_OUTPUT_NAME 电梯模拟器.AppImage)
set_property(TARGET lift_simulator PROPERTY RUNTIME_OUTPUT_DIRECTORY $<1:${OUTPUT_DIR}/bin>)
