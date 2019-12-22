cmake_minimum_required(VERSION 3.6)
project(DoyConverter)

# set compiler options
set(CMAKE_CXX_STANDARD 11)

# set verbosity
set(CMAKE_VERBOSE_MAKEFILE OFF)

add_executable(doy src/doy.cpp)

add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries(doy doylib)