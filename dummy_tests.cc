#include <iostream>
#include <gtest/gtest.h>
#include "dummy.h"

using namespace std;

// Google Test: Test that the main function prints the correct message
TEST(DummyFunctionTest, ReturnExpectedValue) {
    testing::internal::CaptureStdout(); // Capture stdout
    auto result = dummyFunct(); // Call your main function
    string output = testing::internal::GetCapturedStdout(); // Get the captured output
    //beloe EXPECT_EQ() will failed since we put string = dummyFunction() called!
    EXPECT_EQ(output, "\ncmake with googletest\n"); // Check if the output matches
    EXPECT_EQ(result, 1);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}