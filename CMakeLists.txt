cmake_minimum_required(VERSION 3.14)
project(Vector)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

# set(CMAKE_CXX_FLAGS "-fno-elide-constructors ${CMAKE_CXX_FLAGS}")
# add_compile_options(-fno-elide-constructors)

add_executable(Vector main.cpp QRandom.cpp)