cmake_minimum_required(VERSION 3.3)

project(task_tests)

add_subdirectory(lib/gtest-1.7)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(run_all_tests
        task1_test.cpp
        turn_predicate_test.cpp
        middle_point_test.cpp)

target_link_libraries(run_all_tests gtest gtest_main)
target_link_libraries(run_all_tests task1_lib)
