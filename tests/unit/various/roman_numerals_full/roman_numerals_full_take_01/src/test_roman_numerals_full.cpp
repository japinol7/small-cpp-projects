#include <gtest/gtest.h>
#include <string>
#include "../../../../projects/various/roman_numerals_full/roman_numerals_full_take_01/src/roman_numerals_full.hpp"

using namespace ::testing;
using namespace RomanNumeralsFull;

// Test class for Roman numeral conversions
class RomanNumeralsFullTest : public Test {
protected:
    struct ToRomanTestCase {
        int number;
        std::string expected;
        bool shouldSucceed;
    };

    struct FromRomanTestCase {
        std::string roman;
        int expected;
        bool shouldSucceed;
    };
};

// Test toRoman conversion
TEST_F(RomanNumeralsFullTest, ToRoman) {
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

// Test fromRoman conversion
TEST_F(RomanNumeralsFullTest, FromRoman) {
    const std::vector<FromRomanTestCase> testCases = {
        {"I", 1, true},
        {"II", 2, true},
        {"III", 3, true},
        {"IV", 4, true},
        {"V", 5, true},
        {"IX", 9, true},
        {"X", 10, true},
        {"XL", 40, true},
        {"L", 50, true},
        {"LXXIII", 73, true},
        {"XC", 90, true},
        {"XCIII", 93, true},
        {"C", 100, true},
        {"CD", 400, true},
        {"D", 500, true},
        {"CM", 900, true},
        {"M", 1000, true},
        {"MCMLXXXIV", 1984, true},
        {"MMXXIII", 2023, true},
        {"MMMCMXCIX", 3999, true},
        {"", 0, false}, // Error case
        {"MMMM", 0, false}, // Error case (4000)
        {"ABC", 0, false}, // Error case (invalid chars)
        {"MMMCMXCIY", 0, false} // Error case (invalid char Y)
    };

    for (const auto& [roman, expected, shouldSucceed] : testCases) {
        int result = 0;
        bool success = Converter::fromRoman(roman, result);

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
}

// Test round-trip conversion
TEST_F(RomanNumeralsFullTest, RoundTrip) {
    // Test every 100 numbers to keep test runtime reasonable
    for (int i = 1; i <= 3999; i += 100) {
        // Convert int to Roman
        std::string roman = Converter::toRoman(i);
        ASSERT_FALSE(roman.empty()) << "toRoman(" << i << ") failed";

        // Convert Roman back to int
        int result = 0;
        bool success = Converter::fromRoman(roman, result);
        ASSERT_TRUE(success) << "fromRoman(" << roman << ") failed";

        // Verify the round trip conversion
        EXPECT_EQ(i, result)
                << "Round trip failed: " << i << " -> "
                << roman << " -> " << result;
    }
}
