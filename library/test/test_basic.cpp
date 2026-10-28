#include <mine.hpp>
#include <gtest/gtest.h>

TEST(mine, basic)
{
    testing::internal::CaptureStdout();

    hello_world();
    auto output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Hello World!\n");
}
