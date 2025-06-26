#include <gtest/gtest.h>
#include <string>
#include "../../../../projects/various/roman_numerals_full/roman_numerals_full_take_01/src/roman_numerals_full.hpp"

using namespace ::testing;
using namespace RomanNumeralsFull;

// Test case structure for toRoman conversion
struct ToRomanTestCase {
    int number;
    std::string expected;
    bool shouldSucceed;

    static std::string GetTestName(
        const TestParamInfo<ToRomanTestCase>& info
    ) {
        // Replace invalid filename characters with underscores
        std::string name = std::to_string(info.param.number);
        std::replace(name.begin(), name.end(), '-', '_');
        return "Number_" + name;
    }
};

// Test case structure for fromRoman conversion
struct FromRomanTestCase {
    std::string roman;
    int expected;
    bool shouldSucceed;

    static std::string GetTestName(
        const TestParamInfo<FromRomanTestCase>& info
    ) {
        return info.param.roman.empty() ? "Empty" : "Roman_" + info.param.roman;
    }
};

// Parameterized test class for toRoman conversion
class ToRomanTest : public TestWithParam<ToRomanTestCase> {};

// Parameterized test class for fromRoman conversion
class FromRomanTest : public TestWithParam<FromRomanTestCase> {};

TEST_P(ToRomanTest, ConvertToRoman) {
    const auto& [number, expected, shouldSucceed] = GetParam();
    const std::string result = Converter::toRoman(number);

    if (shouldSucceed) {
        EXPECT_FALSE(result.empty()) << "toRoman(" << number << ") should succeed";
        EXPECT_EQ(expected, result)
            << "toRoman(" << number << ") = " << result
            << ", expected " << expected;
    } else {
        EXPECT_TRUE(result.empty())
            << "toRoman(" << number << ") should return empty string for error";
    }
}

TEST_P(FromRomanTest, ConvertFromRoman) {
    const auto& [roman, expected, shouldSucceed] = GetParam();
    int result = 0;
    const bool success = Converter::fromRoman(roman, result);

    if (shouldSucceed) {
        EXPECT_TRUE(success) << "fromRoman(" << roman << ") should succeed";
        EXPECT_EQ(expected, result)
            << "fromRoman(" << roman << ") = " << result
            << ", expected " << expected;
    } else {
        EXPECT_FALSE(success)
            << "fromRoman(" << roman << ") should return false for error";
    }
}

INSTANTIATE_TEST_SUITE_P(
    RomanNumerals,
    ToRomanTest,
    Values(
        ToRomanTestCase{1, "I", true},
        ToRomanTestCase{2, "II", true},
        ToRomanTestCase{3, "III", true},
        ToRomanTestCase{4, "IV", true},
        ToRomanTestCase{5, "V", true},
        ToRomanTestCase{9, "IX", true},
        ToRomanTestCase{10, "X", true},
        ToRomanTestCase{40, "XL", true},
        ToRomanTestCase{50, "L", true},
        ToRomanTestCase{73, "LXXIII", true},
        ToRomanTestCase{90, "XC", true},
        ToRomanTestCase{93, "XCIII", true},
        ToRomanTestCase{100, "C", true},
        ToRomanTestCase{400, "CD", true},
        ToRomanTestCase{500, "D", true},
        ToRomanTestCase{900, "CM", true},
        ToRomanTestCase{1000, "M", true},
        ToRomanTestCase{1984, "MCMLXXXIV", true},
        ToRomanTestCase{2023, "MMXXIII", true},
        ToRomanTestCase{3999, "MMMCMXCIX", true},
        ToRomanTestCase{0, "", false}, // Error case
        ToRomanTestCase{4000, "", false}, // Error case
        ToRomanTestCase{-1, "", false} // Error case
    ),
    ToRomanTestCase::GetTestName
);

INSTANTIATE_TEST_SUITE_P(
    RomanNumerals,
    FromRomanTest,
    Values(
        // Valid cases - single numerals
        FromRomanTestCase{"I", 1, true},
        FromRomanTestCase{"V", 5, true},
        FromRomanTestCase{"X", 10, true},
        FromRomanTestCase{"L", 50, true},
        FromRomanTestCase{"C", 100, true},
        FromRomanTestCase{"D", 500, true},
        FromRomanTestCase{"M", 1000, true},

        // Valid cases - common combinations
        FromRomanTestCase{"II", 2, true},
        FromRomanTestCase{"III", 3, true},
        FromRomanTestCase{"IV", 4, true},
        FromRomanTestCase{"IX", 9, true},
        FromRomanTestCase{"XL", 40, true},
        FromRomanTestCase{"LXXIII", 73, true},
        FromRomanTestCase{"XC", 90, true},
        FromRomanTestCase{"XCIII", 93, true},
        FromRomanTestCase{"CD", 400, true},
        FromRomanTestCase{"CM", 900, true},

        // Valid cases - large numbers
        FromRomanTestCase{"MCMLXXXIV", 1984, true},
        FromRomanTestCase{"MMXXIII", 2023, true},
        FromRomanTestCase{"MMMCMXCIX", 3999, true},

        // Error cases
        FromRomanTestCase{"", 0, false},
        FromRomanTestCase{"MMMM", 0, false}, // Error case (4000)
        FromRomanTestCase{"ABC", 0, false}, // Invalid chars
        FromRomanTestCase{"MMMCMXCIY", 0, false} // Invalid char Y
    ),
    FromRomanTestCase::GetTestName
);

// Test round-trip conversion with parameterized test
class RoundTripTest : public TestWithParam<int> {};

TEST_P(RoundTripTest, ConvertBothWays) {
    const int input = GetParam();
    
    // Convert int to Roman
    const std::string roman = Converter::toRoman(input);
    ASSERT_FALSE(roman.empty()) << "toRoman(" << input << ") failed";

    // Convert Roman back to int
    int result = 0;
    bool success = Converter::fromRoman(roman, result);
    ASSERT_TRUE(success) << "fromRoman(" << roman << ") failed";

    // Verify the round trip conversion
    EXPECT_EQ(input, result)
            << "Round trip failed: " << input << " -> "
            << roman << " -> " << result;
}

INSTANTIATE_TEST_SUITE_P(
    RomanNumerals,
    RoundTripTest,
    Range(1, 4000, 100)
);
