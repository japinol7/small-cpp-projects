#include <gtest/gtest.h>
#include <string>
#include "../../../../projects/cyber_dojo/reverse_roman/reverse_roman_take_01/src/reverse_roman.hpp"

using namespace ::testing;
using namespace ReverseRoman;

// Test class for Roman numeral conversions
class ReverseRomanTest : public Test {
protected:
    struct FromRomanTestCase {
        std::string roman;
        int expected;
        bool shouldSucceed;
    };
};

// Test fromRoman conversion
TEST_F(ReverseRomanTest, FromRoman) {
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
