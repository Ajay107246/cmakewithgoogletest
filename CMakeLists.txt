cmake_minimum_required(VERSION 3.30)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    DOWNLOAD_DIR ${CMAKE_CURRENT_BINARY_DIR}/dependencies
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest DOWNLOAD_EXTRACT_TIMESTAMP  true)
FetchContent_MakeAvailable(googletest)


add_executable(my_tests dummy.cpp hello_test.cc dummy_tests.cc)
target_link_libraries(my_tests gtest_main)