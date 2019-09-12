cmake_minimum_required(VERSION 3.14)
project(type_traits_christianledgard)

set(CMAKE_CXX_STANDARD 17)

add_executable(type_traits_christianledgard main.cpp test/tester.cpp mock/mocker.cpp)