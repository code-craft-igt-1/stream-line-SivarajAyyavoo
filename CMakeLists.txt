cmake_minimum_required(VERSION 3.14)
project(sender)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")

include(FetchContent)
FetchContent_Declare(
  googletest
  DOWNLOAD_EXTRACT_TIMESTAMP true
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB SENDER "sender.cpp")
file(GLOB TEST_SENDER "test_sender.cpp")

add_executable(
    sender
  ${SENDER}
)

add_executable(
    test-sender
  ${TEST_SENDER}
)

target_link_libraries(
    test-sender
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test-sender)
