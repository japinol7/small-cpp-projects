#include <gtest/gtest.h>

#include "../../../../projects/cyber_dojo/print_diamond/print_diamond_take_01/src/print_diamond.hpp"

class PrintDiamondTest : public testing::Test {
protected:
    // Test case structure for parameterized tests
    struct TestCase {
        char letter;
        std::string expected;
    };
};

struct EmptyInputTestCase {
    char input;
    std::string expected;

    static std::string GetTestName(
        const testing::TestParamInfo<EmptyInputTestCase>& info
    ) {
        if (info.param.input == '\0') {
            return "EmptyInput";
        }
        if (info.param.input == ' ') {
            return "SpaceCharacter";
        }
        return "NonAlphabetic_" + std::to_string(info.param.input);
    }
};

class PrintDiamondEmptyInputTest : public testing::TestWithParam<
    EmptyInputTestCase> {
};

TEST_P(PrintDiamondEmptyInputTest, CheckInvalidInput) {
    const auto& [input, expected] = GetParam();
    const Diamond diamond(input);
    EXPECT_EQ(diamond.toString(), expected)
        << "For input: '" << (input == '\0' ? '0' : input) << "'";
}

INSTANTIATE_TEST_SUITE_P(
    EmptyOrInvalidInputTests,
    PrintDiamondEmptyInputTest,
    testing::Values(
        EmptyInputTestCase{'\0', ""},   // Empty input
        EmptyInputTestCase{' ', ""},    // Space character
        EmptyInputTestCase{'0', ""}     // Non-alphabetic character
    ),
    EmptyInputTestCase::GetTestName
);

// Test cases for empty or invalid input
TEST_F(PrintDiamondTest, EmptyOrInvalidInput) {
    const std::vector<TestCase> testCases = {
        {'\0', ""},   // Empty input
        {' ', ""},    // Space character
        {'0', ""}     // Non-alphabetic character
    };

    for (const auto& test : testCases) {
        // Create diamond
        Diamond diamond(test.letter);

        // Check the result
        EXPECT_EQ(diamond.toString(), test.expected)
            << "For input: '" << test.letter << "'";
    }
}

// Test case for letter A
TEST_F(PrintDiamondTest, LetterA) {
    const std::string expected = "A";

    // Create diamond
    const Diamond diamond('A');

    // Check the result
    EXPECT_EQ(diamond.toString(), expected);
}

// Test case for letter B
TEST_F(PrintDiamondTest, LetterB) {
    const std::string expected = ""
        " A \n"
        "B B\n"
        " A ";

    // Create diamond
    const Diamond diamond('B');

    // Check the result
    EXPECT_EQ(diamond.toString(), expected);
}

// Test case for letter C
TEST_F(PrintDiamondTest, LetterC) {
    const std::string expected = ""
        "  A  \n"
        " B B \n"
        "C   C\n"
        " B B \n"
        "  A  ";

    // Create diamond
    const Diamond diamond('C');

    // Check the result
    EXPECT_EQ(diamond.toString(), expected);
}

// Test case for letter D
TEST_F(PrintDiamondTest, LetterD) {
    const std::string expected = ""
        "   A   \n"
        "  B B  \n"
        " C   C \n"
        "D     D\n"
        " C   C \n"
        "  B B  \n"
        "   A   ";

    // Create diamond
    const Diamond diamond('D');

    // Check the result
    EXPECT_EQ(diamond.toString(), expected);
}

// Test case for letter F
TEST_F(PrintDiamondTest, LetterF) {
    const std::string expected = ""
        "     A     \n"
        "    B B    \n"
        "   C   C   \n"
        "  D     D  \n"
        " E       E \n"
        "F         F\n"
        " E       E \n"
        "  D     D  \n"
        "   C   C   \n"
        "    B B    \n"
        "     A     ";

    // Create diamond
    const Diamond diamond('F');

    // Check the result
    EXPECT_EQ(diamond.toString(), expected);
}

// Test case for letter E with output
TEST_F(PrintDiamondTest, LetterEWithOutput) {
    const std::string expected = ""
        "    A    \n"
        "   B B   \n"
        "  C   C  \n"
        " D     D \n"
        "E       E\n"
        " D     D \n"
        "  C   C  \n"
        "   B B   \n"
        "    A    ";

    // Create diamond
    const Diamond diamond('E');

    // Check the result
    EXPECT_EQ(diamond.toString(), expected);

    // Print output for visual inspection
    std::cout << "\nOutput:\n" << diamond.toString() << std::endl;
}

// Test for lowercase letter conversion
TEST_F(PrintDiamondTest, LowercaseLetterConversion) {
    // Expected output for 'C' (same as for uppercase 'C')
    const std::string expected = ""
        "  A  \n"
        " B B \n"
        "C   C\n"
        " B B \n"
        "  A  ";

    // Create diamond with lowercase 'c'
    const Diamond diamond('c');

    // Check that it produces the same output as uppercase 'C'
    EXPECT_EQ(diamond.toString(), expected);
}

// Test for pattern consistency
TEST_F(PrintDiamondTest, PatternConsistency) {
    const Diamond diamond('D');

    // Get the pattern vector
    const auto& pattern = diamond.getPattern();

    // Check the size (for 'D' we should have 7 lines)
    EXPECT_EQ(pattern.size(), 7);

    // Check symmetry - first and last lines should be the same
    EXPECT_EQ(pattern[0], pattern[6]);
    EXPECT_EQ(pattern[1], pattern[5]);
    EXPECT_EQ(pattern[2], pattern[4]);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
