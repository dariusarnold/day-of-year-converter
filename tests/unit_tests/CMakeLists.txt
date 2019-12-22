include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(DoyConverter_Tests test_DateConstruction.cpp test_LeapYear.cpp)

target_link_libraries(DoyConverter_Tests gtest gtest_main)
target_link_libraries(DoyConverter_Tests doylib)