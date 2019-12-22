project(${CMAKE_PROJECT_NAME}_lib)

add_library(doylib doylib/Date.cpp doylib/DoyConverter.cpp)

set(WARNINGS -Werror -Wall -Wextra)

target_compile_options(doylib PRIVATE ${WARNINGS})
target_include_directories(doylib PUBLIC .)