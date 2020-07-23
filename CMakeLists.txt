cmake_minimum_required(VERSION 3.14)
project(Vector)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_compile_options(-fno-elide-constructors)

add_executable(Vector main.cpp QRandom.cpp)