#include <gtest/gtest.h>

#include "../../../../projects/cyber_dojo/leap_year/leap_year_take_01/src/leap_year.hpp"

struct LeapYearTestCase {
    int year;
    bool expected;
    std::string category;

    static std::string GetTestName(
        const testing::TestParamInfo<LeapYearTestCase>& info
    ) {
        // Replace invalid filename characters with underscores
        std::string name = std::to_string(info.param.year);
        std::replace(name.begin(), name.end(), '-', '_');
        return std::to_string(info.index) + "_Year_" + name;
    }
};

class LeapYearTest : public testing::TestWithParam<LeapYearTestCase> {
};

TEST_P(LeapYearTest, CheckYear) {
    const auto& [year, expected, category] = GetParam();
    const bool result = isLeapYear(year);
    EXPECT_EQ(result, expected)
        << "isLeapYear(" << year << ") = "
        << (result ? "true" : "false") << "; want "
        << (expected ? "true" : "false");
}

INSTANTIATE_TEST_SUITE_P(
    LeapYears,
    LeapYearTest,
    testing::Values(
        // Regular years (not divisible by 4)
        LeapYearTestCase{2001, false, "Regular"},
        LeapYearTestCase{2023, false, "Regular"},
        
        // Years divisible by 4 but not by 100
        LeapYearTestCase{1996, true, "DivisibleBy4"},
        LeapYearTestCase{2024, true, "DivisibleBy4"},
        
        // Years divisible by 100 but not by 400
        LeapYearTestCase{1900, false, "DivisibleBy100"},
        LeapYearTestCase{1800, false, "DivisibleBy100"},
        
        // Years divisible by 400
        LeapYearTestCase{2000, true, "DivisibleBy400"},
        LeapYearTestCase{1600, true, "DivisibleBy400"},
        
        // Invalid years
        LeapYearTestCase{0, false, "Invalid"},
        LeapYearTestCase{-1, false, "Invalid"}
    ),
    LeapYearTestCase::GetTestName
);
