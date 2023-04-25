cmake_minimum_required(VERSION 3.24)

project(smooth_sort_benchmark LANGUAGES CXX)

find_package(benchmark REQUIRED)
find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} benchmark.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE -O3)
target_link_libraries(${PROJECT_NAME} PRIVATE benchmark::benchmark)

add_executable(test test.cpp)
target_link_libraries(test PRIVATE GTest::gtest_main)

