#include <gtest/gtest.h>
#include <vector>
#include "../../../../projects/cyber_dojo/leap_year/leap_year_take_01/src/leap_year.hpp"

class LeapYearTest : public ::testing::Test {
};

// Test regular years
TEST_F(LeapYearTest, RegularYearsAreNotLeapYears) {
    EXPECT_FALSE(isLeapYear(2001));
    EXPECT_FALSE(isLeapYear(2023));
}

// Test years divisible by 4 but not by 100
TEST_F(LeapYearTest, YearsDivisibleBy4ButNotBy100AreLeapYears) {
    EXPECT_TRUE(isLeapYear(1996));
    EXPECT_TRUE(isLeapYear(2024));
}

// Test years divisible by 100 but not by 400
TEST_F(LeapYearTest, YearsDivisibleBy100ButNotBy400AreNotLeapYears) {
    EXPECT_FALSE(isLeapYear(1900));
    EXPECT_FALSE(isLeapYear(1800));
}

// Test years divisible by 400
TEST_F(LeapYearTest, YearsDivisibleBy400AreLeapYears) {
    EXPECT_TRUE(isLeapYear(2000));
    EXPECT_TRUE(isLeapYear(1600));
}

// Test invalid years
TEST_F(LeapYearTest, InvalidYearsAreNotLeapYears) {
    EXPECT_FALSE(isLeapYear(0));
    EXPECT_FALSE(isLeapYear(-1));
}

TEST_F(LeapYearTest, RunSeveralYearTests) {
    struct TestCase {
        int input;
        bool expected;
    };

    std::vector<TestCase> tests = {
        {2001, false},
        {1996, true},
        {1900, false},
        {2000, true},
        {2023, false},
        {2024, true},
        {0, false}
    };

    for (const auto& [input, expected] : tests) {
        bool result = isLeapYear(input);
        EXPECT_EQ(result, expected)
            << "isLeapYear(" << input << ") = "
            << (result ? "true" : "false") << "; want "
            << (expected ? "true" : "false");
    }
};
