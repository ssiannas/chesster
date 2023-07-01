cmake_minimum_required(VERSION 3.0.0)
project(chesster VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)

enable_testing()
# add_subdirectory(tests)

set (CHESS_INCL ${CMAKE_SOURCE_DIR}/chess-engine)

add_executable(game game.cpp)
target_include_directories(game PUBLIC ${CHESS_INCL})
