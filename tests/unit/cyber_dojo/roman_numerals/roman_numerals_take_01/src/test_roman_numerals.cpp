#include <gtest/gtest.h>
#include <string>
#include "../../../../projects/cyber_dojo/roman_numerals/roman_numerals_take_01/src/roman_numerals.hpp"

using namespace ::testing;
using namespace RomanNumerals;

// Test class for Roman numeral conversions
class RomanNumeralsTest : public Test {
protected:
    struct ToRomanTestCase {
        int number;
        std::string expected;
        bool shouldSucceed;
    };
};

// Test toRoman conversion
TEST_F(RomanNumeralsTest, ToRoman) {
    const std::vector<ToRomanTestCase> testCases = {
        {1, "I", true},
        {2, "II", true},
        {3, "III", true},
        {4, "IV", true},
        {5, "V", true},
        {9, "IX", true},
        {10, "X", true},
        {40, "XL", true},
        {50, "L", true},
        {73, "LXXIII", true},
        {90, "XC", true},
        {93, "XCIII", true},
        {100, "C", true},
        {400, "CD", true},
        {500, "D", true},
        {900, "CM", true},
        {1000, "M", true},
        {1984, "MCMLXXXIV", true},
        {2023, "MMXXIII", true},
        {3999, "MMMCMXCIX", true},
        {0, "", false}, // Error case
        {4000, "", false}, // Error case
        {-1, "", false} // Error case
    };

    for (const auto& [number, expected, shouldSucceed] : testCases) {
        std::string result = Converter::toRoman(number);

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
}
