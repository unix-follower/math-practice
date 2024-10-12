cmake_minimum_required(VERSION 3.5.0)
project(linear_systems VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Boost REQUIRED)
find_package(Armadillo REQUIRED)

add_executable(example1_boost src/example1_boost.cpp)
set_target_properties(example1_boost PROPERTIES OUTPUT_NAME "example1_boost")
target_link_libraries(example1_boost boost::boost)

add_executable(example1_armadillo src/example1_armadillo.cpp)
set_target_properties(example1_armadillo PROPERTIES OUTPUT_NAME "example1_armadillo")
target_link_libraries(example1_armadillo ${ARMADILLO_LIBRARIES})
