#include <gtest/gtest.h>

#include "../../../../projects/cyber_dojo/lcd_digits/lcd_digits_take_01/src/lcd_digits.hpp"

using namespace LcdDisplay;

// LCD digit representations for testing
namespace {
    const std::string DIGITS_REPR_0 = ""
        "._."
        "\n|.|"
        "\n|_|"
        "\n";

    const std::string DIGITS_REPR_1 = ""
        "..."
        "\n..|"
        "\n..|"
        "\n";

    const std::string DIGITS_REPR_2 = ""
        "._."
        "\n._|"
        "\n|_."
        "\n";

    const std::string DIGITS_REPR_3 = ""
        "._."
        "\n._|"
        "\n._|"
        "\n";

    const std::string DIGITS_REPR_4 = ""
        "..."
        "\n|_|"
        "\n..|"
        "\n";

    const std::string DIGITS_REPR_5 = ""
        "._."
        "\n|_."
        "\n._|"
        "\n";

    const std::string DIGITS_REPR_6 = ""
        "._."
        "\n|_."
        "\n|_|"
        "\n";

    const std::string DIGITS_REPR_7 = ""
        "._."
        "\n..|"
        "\n..|"
        "\n";

    const std::string DIGITS_REPR_8 = ""
        "._."
        "\n|_|"
        "\n|_|"
        "\n";

    const std::string DIGITS_REPR_9 = ""
        "._."
        "\n|_|"
        "\n..|"
        "\n";

    const std::string DIGITS_REPR_1234567890 = ""
        "... ._. ._. ... ._. ._. ._. ._. ._. ._."
        "\n..| ._| ._| |_| |_. |_. ..| |_| |_| |.|"
        "\n..| |_. ._| ..| ._| |_| ..| |_| ..| |_|"
        "\n";

    const std::string DIGITS_REPR_1234567890_SEPARATOR_BIG = ""
        "...     ._.     ._.     ...     ._.     ._.     ._.     ._.     ._.     ._."
        "\n..|     ._|     ._|     |_|     |_.     |_.     ..|     |_|     |_|     |.|"
        "\n..|     |_.     ._|     ..|     ._|     |_|     ..|     |_|     ..|     |_|"
        "\n";

    const std::string DIGITS_REPR_910 = ""
        "._. ... ._."
        "\n|_| ..| |.|"
        "\n..| ..| |_|"
        "\n";
}

class LcdDigitsTest : public ::testing::Test {
protected:
    LcdDigits lcd;

    static std::string ProcessResultForComparison(
        const std::string& input
    ) {
        return input;
    }
};

// Test single digits 0-9
TEST_F(LcdDigitsTest, SingleDigits) {
    struct TestCase {
        int input;
        const std::string& expected;
    };

    TestCase tests[] = {
        {0, DIGITS_REPR_0},
        {1, DIGITS_REPR_1},
        {2, DIGITS_REPR_2},
        {3, DIGITS_REPR_3},
        {4, DIGITS_REPR_4},
        {5, DIGITS_REPR_5},
        {6, DIGITS_REPR_6},
        {7, DIGITS_REPR_7},
        {8, DIGITS_REPR_8},
        {9, DIGITS_REPR_9}
    };

    for (const auto& test : tests) {
        auto result = lcd.Generate(test.input);
        ASSERT_TRUE(result.has_value()) << "Failed to generate digit " << test.input;

        std::string processedResult = ProcessResultForComparison(*result);
        EXPECT_EQ(test.expected, processedResult) 
            << "Digit " << test.input << " representation doesn't match";
    }
}

// Test multiple digits
TEST_F(LcdDigitsTest, AllDigits) {
    const auto result = lcd.Generate(1234567890);
    ASSERT_TRUE(result.has_value()) << "Failed to generate all digits";

    std::string processedResult = ProcessResultForComparison(*result);
    EXPECT_EQ(DIGITS_REPR_1234567890, processedResult);
}

// Test 910 specifically
TEST_F(LcdDigitsTest, Digits910) {
    auto result = lcd.Generate(910);
    ASSERT_TRUE(result.has_value()) << "Failed to generate 910";

    std::string processedResult = ProcessResultForComparison(*result);
    EXPECT_EQ(DIGITS_REPR_910, processedResult);
}

// Test custom separator
TEST_F(LcdDigitsTest, CustomSeparator) {
    const std::string separator = "     ";

    const auto result = lcd.Generate(1234567890, separator);
    ASSERT_TRUE(result.has_value()) << "Failed to generate with custom separator";

    const std::string processedResult = ProcessResultForComparison(*result);
    EXPECT_EQ(DIGITS_REPR_1234567890_SEPARATOR_BIG, processedResult);
}

// Test negative number error
TEST_F(LcdDigitsTest, NegativeNumberError) {
    const auto result = lcd.Generate(-1);
    ASSERT_FALSE(result.has_value()) << "Should fail for negative number";
    EXPECT_EQ("Number must be non-negative", lcd.GetLastError());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
