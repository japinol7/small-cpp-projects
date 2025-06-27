#include <gtest/gtest.h>

#include "../../../../projects/cyber_dojo/reverse_roman/reverse_roman_take_01/src/reverse_roman.hpp"

using namespace ReverseRoman;

struct RomanConversionTestCase {
    std::string roman;
    int expected;
    bool shouldSucceed;

    static std::string GetTestName(
        const testing::TestParamInfo<RomanConversionTestCase>& info
    ) {
        if (info.param.roman.empty()) {
            return "Empty_String";
        }
        return "Roman_" + info.param.roman
               + "_Expected_" + std::to_string(info.param.expected);
    }
};

class RomanConversionTest : public testing::TestWithParam<
    RomanConversionTestCase> {
};

TEST_P(RomanConversionTest, FromRoman) {
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
    RomanConversionTest,
    testing::Values(
        // Valid cases - single numerals
        RomanConversionTestCase{"I", 1, true},
        RomanConversionTestCase{"V", 5, true},
        RomanConversionTestCase{"X", 10, true},
        RomanConversionTestCase{"L", 50, true},
        RomanConversionTestCase{"C", 100, true},
        RomanConversionTestCase{"D", 500, true},
        RomanConversionTestCase{"M", 1000, true},

        // Valid cases - common combinations
        RomanConversionTestCase{"II", 2, true},
        RomanConversionTestCase{"III", 3, true},
        RomanConversionTestCase{"IV", 4, true},
        RomanConversionTestCase{"IX", 9, true},
        RomanConversionTestCase{"XL", 40, true},
        RomanConversionTestCase{"LXXIII", 73, true},
        RomanConversionTestCase{"XC", 90, true},
        RomanConversionTestCase{"XCIII", 93, true},
        RomanConversionTestCase{"CD", 400, true},
        RomanConversionTestCase{"CM", 900, true},

        // Valid cases - large numbers
        RomanConversionTestCase{"MCMLXXXIV", 1984, true},
        RomanConversionTestCase{"MMXXIII", 2023, true},
        RomanConversionTestCase{"MMMCMXCIX", 3999, true},

        // Error cases
        RomanConversionTestCase{"", 0, false},
        RomanConversionTestCase{"MMMM", 0, false}, // Error case (4000)
        RomanConversionTestCase{"ABC", 0, false}, // Invalid chars
        RomanConversionTestCase{"MMMCMXCIY", 0, false} // Invalid char Y
    ),
    RomanConversionTestCase::GetTestName
);

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
