#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <optional>
#include "../../../../projects/cyber_dojo/isbn/isbn_take_01/src/isbn.hpp"

using namespace ::testing;

class IsbnTest : public Test {
protected:
    // Test case structure
    struct TestCase {
        std::string input_isbn;
        std::string expected;
    };
};

TEST_F(IsbnTest, ValidateISBN13) {
    const std::vector<TestCase> tests = {
        {"9780470059029", "true"},
        {"978 0 471 48648 0", "true"},
        {"978-0596809485", "true"},
        {"978-0-13-149505-0", "true"},
        {"978-0-262-13472-9", "true"},
        {"978-0-262-13472-1", "false"},
        {"978-0-262-13472-2", "false"},
        {"978 0 A 471 48648 0", "false"},
        {"978 0 * 471 48648 0", "false"},
        {"978-0-262-13472-X", "false"},
        {"978-13472-2", "false"},
        {"978-0-A62-13472-1", "false"},
    };

    for (const auto& [input_isbn, expected] : tests) {
        auto result = ISBN::validate(input_isbn);
        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(result.value(), expected)
            << "ISBN::validate(\"" << input_isbn << "\") = \""
            << result.value() << "\", want \"" << expected << "\"";
    }
}

TEST_F(IsbnTest, ValidateISBN10) {
    const std::vector<TestCase> tests = {
        {"0471958697", "true"},
        {"0 471 60695 2", "true"},
        {"0-470-84525-2", "true"},
        {"0-321-14653-0", "true"},
        {"0-8044-2957-X", "true"},
        {"0-9752298-0-X", "true"},
        {"0-8044-2957-D", "false"},
        {"0-470-84525-3", "false"},
        {"0-4A0-84525-2", "false"},
        {"0-470-*4525-2", "false"},
        {"0-470-8425-2", "false"},
    };

    for (const auto& test : tests) {
        auto result = ISBN::validate(test.input_isbn);
        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(result.value(), test.expected) 
            << "ISBN::validate(\"" << test.input_isbn << "\") = \"" 
            << result.value() << "\", want \"" << test.expected << "\"";
    }
}

TEST_F(IsbnTest, EdgeCases) {
    // Empty string
    const auto emptyResult = ISBN::validate("");
    ASSERT_TRUE(emptyResult.has_value());
    EXPECT_EQ(emptyResult.value(), "false");
}
