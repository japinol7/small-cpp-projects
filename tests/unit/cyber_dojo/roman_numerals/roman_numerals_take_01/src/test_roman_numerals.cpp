#include <gtest/gtest.h>

#include "../../../../projects/cyber_dojo/roman_numerals/roman_numerals_take_01/src/roman_numerals.hpp"

using namespace RomanNumerals;

struct RomanNumeralTestCase {
    int number;
    std::string expected;
    bool shouldSucceed;

    static std::string GetTestName(
        const testing::TestParamInfo<RomanNumeralTestCase>& info
    ) {
        // Replace invalid filename characters with underscores
        std::string name = std::to_string(info.param.number);
        std::replace(name.begin(), name.end(), '-', '_');
        return "Number_" + name
               + "_Expected_" + info.param.expected;
    }
};

class RomanNumeralsTest : public testing::TestWithParam<
    RomanNumeralTestCase> {
};

TEST_P(RomanNumeralsTest, ToRoman) {
    const auto& [number, expected, shouldSucceed] = GetParam();
    const std::string result = Converter::toRoman(number);

    if (shouldSucceed) {
        EXPECT_FALSE(result.empty()) << "toRoman(" << number << ") should succeed";
        EXPECT_EQ(result, expected)
            << "toRoman(" << number << ") = " << result
            << ", expected " << expected;
    } else {
        EXPECT_TRUE(result.empty())
            << "toRoman(" << number << ") should return empty string for error";
    }
}

INSTANTIATE_TEST_SUITE_P(
    RomanNumeralTests,
    RomanNumeralsTest,
    testing::Values(
        RomanNumeralTestCase{1, "I", true},
        RomanNumeralTestCase{2, "II", true},
        RomanNumeralTestCase{3, "III", true},
        RomanNumeralTestCase{4, "IV", true},
        RomanNumeralTestCase{5, "V", true},
        RomanNumeralTestCase{9, "IX", true},
        RomanNumeralTestCase{10, "X", true},
        RomanNumeralTestCase{40, "XL", true},
        RomanNumeralTestCase{50, "L", true},
        RomanNumeralTestCase{73, "LXXIII", true},
        RomanNumeralTestCase{90, "XC", true},
        RomanNumeralTestCase{93, "XCIII", true},
        RomanNumeralTestCase{100, "C", true},
        RomanNumeralTestCase{400, "CD", true},
        RomanNumeralTestCase{500, "D", true},
        RomanNumeralTestCase{900, "CM", true},
        RomanNumeralTestCase{1000, "M", true},
        RomanNumeralTestCase{1984, "MCMLXXXIV", true},
        RomanNumeralTestCase{2023, "MMXXIII", true},
        RomanNumeralTestCase{3999, "MMMCMXCIX", true},
        RomanNumeralTestCase{0, "", false}, // Error case
        RomanNumeralTestCase{4000, "", false}, // Error case
        RomanNumeralTestCase{-1, "", false} // Error case
    ),
    RomanNumeralTestCase::GetTestName
);

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
