cmake_minimum_required(VERSION 3.0.0)
project(EX3 VERSION 0.1.0)

set(MTM_FLAGS_DEBUG "-std=c++11 -Wall -Werror -pedantic-errors -L.")
set(MTM_FLAGS_RELEASE "{MTM_FLAGS_DEBUG} -DNDBUG")

set(CMAKE_CXX_FLAGS ${MTM_FLAGS_DEBUG})

add_library(date date.c date_wrap.h)
add_executable(ex3 date_wrap.cpp test_partA.cpp)
target_link_libraries(ex3 date)
