cmake_minimum_required(VERSION 3.23)
project(iteratorimpl)

set(CMAKE_CXX_STANDARD 20)

add_executable(01_naive_iterator 01_naive_iterator.cpp)
add_executable(02_iterator_traits  02_iterator_traits.cpp)
add_executable(03_distance 03_distance.cpp)
add_executable(04_distance_constexpr 04_distance_constexpr.cpp)
add_executable(05_not_naive_iterator 05_not_naive_iterator.cpp)
add_executable(06_conditional 06_conditional.cpp)
add_executable(07_const_iterator 07_const_iterator.cpp)
add_executable(08_reverse_iterator 08_reverse_iterator.cpp)