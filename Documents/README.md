1. Create a simple main.cpp file

2. Create CMakeLists.txt in root directory

3. Create / configure CMakePresents.json with Unix Makefiles
include below cmake executable path
"CMAKE_MAKE_PROGRAM": "D:\\msys64\\usr\\bin\\make.exe"

4. update root CMakeLists.txt with below contents:
cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(my_tests hello_test.cc)
target_link_libraries(my_tests gtest_main)

5. add hello_test.cc with below contents:
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

6. Run the commands shown in guide.pdf
OR as below:
cd .\build\
cmake -Dgtest_build_samples=ON -DCMAKE_BUILD_TYPE=Debug ..
make -j4

NOTE: clean:
cmake --build . --clean-first

7. run exe for test:
.\my_tests.exe

8. logs:

    Directory: G:\CPP\2024\VSCode\cmakewithgoogletest\build

Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
d----           7/31/2024  1:36 PM                _deps
d----           7/31/2024  1:29 PM                .cmake
d----           7/31/2024  1:36 PM                bin
d----           7/31/2024  2:48 PM                CMakeFiles
d----           7/31/2024  2:39 PM                lib
d----           7/31/2024  2:35 PM                Testing
-a---           7/31/2024  2:30 PM           2165 cmake_install.cmake
-a---           7/31/2024  2:30 PM          25076 CMakeCache.txt
-a---           7/31/2024  2:47 PM          13599 compile_commands.json
-a---           7/31/2024  2:47 PM          17377 Makefile
-a---           7/31/2024  2:39 PM        5473553 my_tests.exe

PS G:\CPP\2024\VSCode\cmakewithgoogletest\build> cmake -Dgtest_build_samples=ON -DCMAKE_BUILD_TYPE=Debug ..
CMake Warning (dev) at C:/Program Files/CMake/share/cmake-3.30/Modules/FetchContent.cmake:1373 (message):
  The DOWNLOAD_EXTRACT_TIMESTAMP option was not given and policy CMP0135 is
  not set.  The policy's OLD behavior will be used.  When using a URL
  download, the timestamps of extracted files should preferably be that of
  the time of extraction, otherwise code that depends on the extracted
  contents might not be rebuilt if the URL changes.  The OLD behavior
  preserves the timestamps from the archive instead, but this is usually not
  what you want.  Update your project to the NEW behavior or specify the
  DOWNLOAD_EXTRACT_TIMESTAMP option with a value of true to avoid this
  robustness issue.
Call Stack (most recent call first):
  CMakeLists.txt:9 (FetchContent_Declare)
This warning is for project developers.  Use -Wno-dev to suppress it.

-- Configuring done (2.5s)
-- Generating done (0.5s)
-- Build files have been written to: G:/CPP/2024/VSCode/cmakewithgoogletest/build
PS G:\CPP\2024\VSCode\cmakewithgoogletest\build> make -j4
[  5%] Built target gtest
[ 11%] Built target gmock
[ 16%] Built target gtest_main
[ 25%] Built target sample9_unittest
[ 27%] Built target sample10_unittest
[ 33%] Built target gmock_main
[ 50%] Built target my_tests
[ 52%] Built target sample1_unittest
[ 61%] Built target sample2_unittest
[ 69%] Built target sample4_unittest
[ 77%] Built target sample5_unittest
[ 83%] Built target sample3_unittest
[ 88%] Built target sample6_unittest
[ 94%] Built target sample8_unittest
[100%] Built target sample7_unittest
PS G:\CPP\2024\VSCode\cmakewithgoogletest\build> ls

    Directory: G:\CPP\2024\VSCode\cmakewithgoogletest\build

Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
d----           7/31/2024  1:36 PM                _deps
d----           7/31/2024  1:29 PM                .cmake
d----           7/31/2024  1:36 PM                bin
d----           7/31/2024  2:50 PM                CMakeFiles
d----           7/31/2024  2:39 PM                lib
d----           7/31/2024  2:35 PM                Testing
-a---           7/31/2024  2:30 PM           2165 cmake_install.cmake
-a---           7/31/2024  2:30 PM          25076 CMakeCache.txt
-a---           7/31/2024  2:50 PM          13599 compile_commands.json
-a---           7/31/2024  2:50 PM          17377 Makefile
-a---           7/31/2024  2:39 PM        5473553 my_tests.exe

PS G:\CPP\2024\VSCode\cmakewithgoogletest\build> .\my_tests.exe
[==========] Running 2 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 1 test from DummyFunctionTest
[ RUN      ] DummyFunctionTest.ReturnExpectedValue
[       OK ] DummyFunctionTest.ReturnExpectedValue (10 ms)
[----------] 1 test from DummyFunctionTest (14 ms total)

[----------] 1 test from HelloTest
[ RUN      ] HelloTest.BasicAssertions
[       OK ] HelloTest.BasicAssertions (0 ms)
[----------] 1 test from HelloTest (1 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 2 test suites ran. (27 ms total)
[  PASSED  ] 2 tests.

9. from tool vscode, cmake build  log:
[main] Building folder: G:/CPP/2024/VSCode/cmakewithgoogletest/out/build/CMakePresents.json 
[build] Starting build
[proc] Executing command: "C:\\Program Files\\CMake\\bin\\cmake.exe" --build G:/CPP/2024/VSCode/cmakewithgoogletest/out/build/CMakePresents.json --parallel 6 --
[build] [  8%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj[0m
[build] [ 16%] [32m[1mLinking CXX static library ../../../lib/libgtest.a[0m
[build] [ 16%] Built target gtest
[build] [ 25%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj[0m
[build] [ 33%] [32mBuilding CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj[0m
[build] [ 41%] [32m[1mLinking CXX static library ../../../lib/libgtest_main.a[0m
[build] [ 41%] Built target gtest_main
[build] [ 50%] [32mBuilding CXX object CMakeFiles/my_tests.dir/dummy.cpp.obj[0m
[build] [ 58%] [32mBuilding CXX object CMakeFiles/my_tests.dir/hello_test.cc.obj[0m
[build] [ 66%] [32mBuilding CXX object CMakeFiles/my_tests.dir/dummy_tests.cc.obj[0m
[build] [ 75%] [32m[1mLinking CXX executable my_tests.exe[0m
[build] [ 83%] [32m[1mLinking CXX static library ../../../lib/libgmock.a[0m
[build] [ 83%] Built target gmock
[build] [ 91%] [32mBuilding CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj[0m
[build] [ 91%] Built target my_tests
[build] [100%] [32m[1mLinking CXX static library ../../../lib/libgmock_main.a[0m
[build] [100%] Built target gmock_main
[driver] Build completed: 00:00:36.002
[build] Build finished with exit code 0

-------------------------------------------------
[main] Building folder: G:/CPP/2024/VSCode/cmakewithgoogletest/build 
[build] Starting build
[proc] Executing command: "C:\\Program Files\\CMake\\bin\\cmake.exe" --build G:/CPP/2024/VSCode/cmakewithgoogletest/build --parallel 6 --
[build] [  2%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj[0m
[build] [  5%] [32m[1mLinking CXX static library ../../../lib/libgtest.a[0m
[build] [  5%] Built target gtest
[build] [  8%] [32mBuilding CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj[0m
[build] [ 11%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj[0m
[build] [ 13%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/sample9_unittest.dir/samples/sample9_unittest.cc.obj[0m
[build] [ 16%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.obj[0m
[build] [ 19%] [32m[1mLinking CXX static library ../../../lib/libgtest_main.a[0m
[build] [ 22%] [32m[1mLinking CXX executable sample9_unittest.exe[0m
[build] [ 22%] Built target gtest_main
[build] [ 25%] [32m[1mLinking CXX executable sample10_unittest.exe[0m
[build] [ 27%] [32mBuilding CXX object CMakeFiles/my_tests.dir/dummy.cpp.obj[0m
[build] [ 30%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/sample1_unittest.dir/samples/sample1_unittest.cc.obj[0m
[build] [ 33%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.obj[0m
[build] [ 36%] Built target sample9_unittest
[build] [ 36%] [32mBuilding CXX object CMakeFiles/my_tests.dir/hello_test.cc.obj[0m
[build] [ 36%] Built target sample10_unittest
[build] [ 38%] [32m[1mLinking CXX static library ../../../lib/libgmock.a[0m
[build] [ 41%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/sample1_unittest.dir/samples/sample1.cc.obj[0m
[build] [ 44%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.obj[0m
[build] [ 47%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/sample2_unittest.dir/samples/sample2.cc.obj[0m
[build] [ 50%] [32mBuilding CXX object CMakeFiles/my_tests.dir/dummy_tests.cc.obj[0m
[build] [ 52%] [32m[1mLinking CXX executable sample1_unittest.exe[0m
[build] [ 52%] Built target gmock
[build] [ 55%] [32m[1mLinking CXX executable sample2_unittest.exe[0m
[build] [ 58%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/sample4_unittest.dir/samples/sample4_unittest.cc.obj[0m
[build] [ 61%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/sample5_unittest.dir/samples/sample5_unittest.cc.obj[0m
[build] [ 63%] [32m[1mLinking CXX executable sample3_unittest.exe[0m
[build] [ 66%] [32m[1mLinking CXX executable my_tests.exe[0m
[build] [ 66%] Built target sample1_unittest
[build] [ 69%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/sample4_unittest.dir/samples/sample4.cc.obj[0m
[build] [ 69%] Built target sample2_unittest
[build] [ 72%] [32m[1mLinking CXX executable sample4_unittest.exe[0m
[build] [ 75%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/sample6_unittest.dir/samples/sample6_unittest.cc.obj[0m
[build] [ 75%] Built target my_tests
[build] [ 77%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/sample5_unittest.dir/samples/sample1.cc.obj[0m
[build] [ 80%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/sample7_unittest.dir/samples/sample7_unittest.cc.obj[0m
[build] [ 80%] Built target sample3_unittest
[build] [ 83%] [32m[1mLinking CXX executable sample5_unittest.exe[0m
[build] [ 86%] [32mBuilding CXX object _deps/googletest-build/googletest/CMakeFiles/sample8_unittest.dir/samples/sample8_unittest.cc.obj[0m
[build] [ 88%] [32mBuilding CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj[0m
[build] [ 88%] Built target sample4_unittest
[build] [ 91%] Built target sample5_unittest
[build] [ 91%] [32m[1mLinking CXX executable sample6_unittest.exe[0m
[build] [ 94%] [32m[1mLinking CXX executable sample7_unittest.exe[0m
[build] [ 97%] [32m[1mLinking CXX static library ../../../lib/libgmock_main.a[0m
[build] [ 97%] Built target sample6_unittest
[build] [ 97%] Built target gmock_main
[build] [ 97%] Built target sample7_unittest
[build] [100%] [32m[1mLinking CXX executable sample8_unittest.exe[0m
[build] [100%] Built target sample8_unittest
[driver] Build completed: 00:01:31.932
[build] Build finished with exit code 0

9.  cmake --build . --clean-first
[  2%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj
[  5%] Linking CXX static library ../../../lib/libgtest.a
[  5%] Built target gtest
[  8%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj
[ 11%] Linking CXX static library ../../../lib/libgtest_main.a
[ 11%] Built target gtest_main
[ 13%] Building CXX object CMakeFiles/my_tests.dir/dummy.cpp.obj
[ 16%] Building CXX object CMakeFiles/my_tests.dir/hello_test.cc.obj
[ 19%] Building CXX object CMakeFiles/my_tests.dir/dummy_tests.cc.obj
[ 22%] Linking CXX executable my_tests.exe
[ 22%] Built target my_tests
[ 25%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj
[ 27%] Linking CXX static library ../../../lib/libgmock.a
[ 27%] Built target gmock
[ 30%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj
[ 33%] Linking CXX static library ../../../lib/libgmock_main.a
[ 33%] Built target gmock_main
[ 36%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/sample1_unittest.dir/samples/sample1_unittest.cc.obj
[ 38%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/sample1_unittest.dir/samples/sample1.cc.obj
[ 41%] Linking CXX executable sample1_unittest.exe
[ 41%] Built target sample1_unittest
[ 44%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.obj
[ 47%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/sample2_unittest.dir/samples/sample2.cc.obj
[ 50%] Linking CXX executable sample2_unittest.exe
[ 50%] Built target sample2_unittest
[ 52%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.obj
[ 55%] Linking CXX executable sample3_unittest.exe
[ 55%] Built target sample3_unittest
[ 58%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/sample4_unittest.dir/samples/sample4_unittest.cc.obj
[ 61%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/sample4_unittest.dir/samples/sample4.cc.obj
[ 63%] Linking CXX executable sample4_unittest.exe
[ 63%] Built target sample4_unittest
[ 66%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/sample5_unittest.dir/samples/sample5_unittest.cc.obj
[ 69%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/sample5_unittest.dir/samples/sample1.cc.obj
[ 72%] Linking CXX executable sample5_unittest.exe
[ 72%] Built target sample5_unittest
[ 75%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/sample6_unittest.dir/samples/sample6_unittest.cc.obj
[ 77%] Linking CXX executable sample6_unittest.exe
[ 77%] Built target sample6_unittest
[ 80%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/sample7_unittest.dir/samples/sample7_unittest.cc.obj
[ 83%] Linking CXX executable sample7_unittest.exe
[ 83%] Built target sample7_unittest
[ 86%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/sample8_unittest.dir/samples/sample8_unittest.cc.obj
[ 88%] Linking CXX executable sample8_unittest.exe
[ 88%] Built target sample8_unittest
[ 91%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/sample9_unittest.dir/samples/sample9_unittest.cc.obj
[ 94%] Linking CXX executable sample9_unittest.exe
[ 94%] Built target sample9_unittest
[ 97%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.obj
[100%] Linking CXX executable sample10_unittest.exe
[100%] Built target sample10_unittest 