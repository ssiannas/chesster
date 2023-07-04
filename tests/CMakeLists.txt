project(chesster)
include(FetchContent)
include(GoogleTest)
set (CHESS_INCL ${CMAKE_SOURCE_DIR}/src)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.13.0
)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(board_test masks_test.cpp)
target_include_directories(board_test PUBLIC ${CHESS_INCL})
target_link_libraries(board_test 
    PRIVATE
    GTest::GTest)

# gtest_discover_tests(board_test)
add_test(board_tests board_test)
