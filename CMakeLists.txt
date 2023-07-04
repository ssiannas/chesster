cmake_minimum_required(VERSION 3.1.0)
project(chesster VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)

add_executable(game game.cpp)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Werror -Wpedantic)
endif()

set (CHESS_INCL ${CMAKE_SOURCE_DIR}/src)
target_include_directories(game PUBLIC ${CHESS_INCL})

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_subdirectory(tests)