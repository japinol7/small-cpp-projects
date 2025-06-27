#include <gtest/gtest.h>

#include "../../../../projects/cyber_dojo/balanced_parentheses/balanced_parentheses_take_01/src/balanced_parentheses.hpp"

// Test class for balanced parentheses checking
class BalancedParenthesesTest : public testing::Test {
protected:
    // Setup method (empty for this test class)
    void SetUp() override {}

    // Test cases for balanced parentheses
    static void testBalanced(const std::string& input) {
        EXPECT_TRUE(areParenthesesBalanced(input));
    }

    // Test cases for unbalanced parentheses
    static void testUnbalanced(const std::string& input) {
        EXPECT_FALSE(areParenthesesBalanced(input));
    }
};

TEST_F(BalancedParenthesesTest, EmptyString) {
    testBalanced("");
}

TEST_F(BalancedParenthesesTest, SimpleParentheses) {
    testBalanced("()");
}

TEST_F(BalancedParenthesesTest, SimpleBraces) {
    testBalanced("{}");
}

TEST_F(BalancedParenthesesTest, NestedBracesAndParentheses) {
    testBalanced("{()}");
}

TEST_F(BalancedParenthesesTest, ComplexNested) {
    testBalanced("{[()]}");
}

TEST_F(BalancedParenthesesTest, AlternativeNesting) {
    testBalanced("[({})]");
}

TEST_F(BalancedParenthesesTest, MultiplePairs) {
    testBalanced("{}([])");
}

TEST_F(BalancedParenthesesTest, ComplexValid) {
    testBalanced("{()}[[{}]]");
}

TEST_F(BalancedParenthesesTest, UnbalancedClose) {
    testUnbalanced("[]]");
}

TEST_F(BalancedParenthesesTest, IncorrectlyNested) {
    testUnbalanced("{{})(}");
}

TEST_F(BalancedParenthesesTest, Mismatched) {
    testUnbalanced("({)}");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
