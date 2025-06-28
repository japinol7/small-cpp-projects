#include <gtest/gtest.h>

#include "../../../../projects/cyber_dojo/count_coins/count_coins_take_01/src/count_coins.hpp"

// Test case structure for parameterized tests
struct CountCoinsTestCase {
    int input;
    int expected;

    static std::string GetTestName(
        const testing::TestParamInfo<CountCoinsTestCase>& info
    ) {
        return "Amount_" + std::to_string(info.param.input) +
               "_Expected_" + std::to_string(info.param.expected);
    }
};

// Parameterized test class
class CountCoinsParameterizedTest
    : public testing::TestWithParam<CountCoinsTestCase> {
protected:
    CountCoins cc;
};

// Single parameterized test that runs for each test case
TEST_P(CountCoinsParameterizedTest, ChangeCalculation) {
    const auto& [input, expected] = GetParam();
    const int result = cc.changes(input);

    EXPECT_EQ(expected, result)
        << "cc.changes(" << input << ") = "
        << result << ", expected " << expected;
}

// Instantiate the test suite with all test cases
INSTANTIATE_TEST_SUITE_P(
    CountCoinsTests,
    CountCoinsParameterizedTest,
    testing::Values(
        CountCoinsTestCase{0, 0},
        CountCoinsTestCase{15, 6},
        CountCoinsTestCase{20, 9},
        CountCoinsTestCase{25, 13},
        CountCoinsTestCase{30, 18},
        CountCoinsTestCase{53, 49},
        CountCoinsTestCase{100, 242}
    ),
    CountCoinsTestCase::GetTestName
);

// Special test for 100 cents with additional output
TEST(CountCoinsSpecialTest, Changes100Cents) {
    const CountCoins cc;
    const int result = cc.changes(100);
    constexpr int expected = 242;

    EXPECT_EQ(expected, result);

    // Print output for visual inspection
    std::cout << "Output: " << std::endl;
    std::cout << "How many ways are there to make change for a dollar " << std::endl;
    std::cout << "using these common coins? (1 dollar = 100 cents) " << std::endl;
    std::cout << "Result: " << result << std::endl;
}

// Custom coin values test
class CustomCoinsTest : public testing::Test {
protected:
    // Using a different set of coins to test custom configurations
    CountCoins custom_cc{std::vector<int>{50, 25, 10, 5, 1}};
};

TEST_F(CustomCoinsTest, CustomCoinSet) {
    // Test with a custom set
    EXPECT_EQ(50, custom_cc.changes(50));
    EXPECT_EQ(292, custom_cc.changes(100));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
