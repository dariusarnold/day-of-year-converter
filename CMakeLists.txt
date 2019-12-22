cmake_minimum_required(VERSION 3.6)
project(DoyConverter)

# set compiler options
set(CMAKE_CXX_STANDARD 11)
set(CMKAE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# set verbosity
set(CMAKE_VERBOSE_MAKEFILE ON)

# Create static executable
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

# add source files
set(SOURCE_FILES src/doy.cpp src/DoyConverter.cpp src/DoyConverter.h src/Date.h src/Date.cpp)
add_executable(${CMAKE_PROJECT_NAME}_Run ${SOURCE_FILES})

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)

