#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../../../../projects/cyber_dojo/fizzbuzz_plus/fizzbuzz_plus_take_01/src/fizzbuzz_plus.hpp"
#include "../../../../projects/cyber_dojo/fizzbuzz_plus/fizzbuzz_plus_take_01/src/utils/utils.hpp"

using namespace ::testing;

class FizzbuzzPlusTest : public Test {
};

TEST_F(FizzbuzzPlusTest, SingleNumbers) {
    struct TestCase {
        int input;
        std::string expected;
    };

    std::vector<TestCase> tests = {
        {1, "1"},
        {2, "2"},
        {3, "Fizz"},
        {4, "4"},
        {5, "Buzz"},
        {6, "Fizz"},
        {10, "Buzz"},
        {12, "Fizz"},
        {13, "Fizz"},
        {15, "FizzBuzz"},
        {52, "Buzz"}
    };

    for (const auto& [input, expected] : tests) {
        std::string result = fizzbuzz(input);
        EXPECT_EQ(result, expected) << "Fizzbuzz(" << input << ") = "
                                         << result << ", want " << expected;
    }
}

TEST_F(FizzbuzzPlusTest, Range) {
    struct TestCase {
        int input;
        std::string expected;
    };

    const std::vector<TestCase> tests = {
        {1, "1"},
        {2, "1\n2"},
        {15, "1\n2\nFizz\n4\nBuzz\nFizz\n7\n8\nFizz\nBuzz\n11\nFizz\nFizz\n14\nFizzBuzz"}
    };

    for (const auto& [input, expected] : tests) {
        // Generate FizzBuzz range
        auto range_result = fizzbuzz_range(input);

        // Join the results
        std::string joined = string_join(range_result);

        EXPECT_EQ(joined, expected) << "string_join(fizzbuzz_range(" << input << ")) = "
                                    << joined << ", want " << expected;
    }
}

TEST_F(FizzbuzzPlusTest, RangeUntilOneHundred) {
    constexpr int n = 100;

    // Generate FizzBuzz range
    const auto range_result = fizzbuzz_range(n);

    // Create expected string for 1-100 FizzBuzz sequence
    std::string expected;
    expected += "1\n2\nFizz\n4\nBuzz\nFizz\n7\n8\nFizz\nBuzz\n11\nFizz\nFizz\n14\n";
    expected += "FizzBuzz\n16\n17\nFizz\n19\nBuzz\nFizz\n22\nFizz\nFizz\nBuzz\n26\n";
    expected += "Fizz\n28\n29\nFizzBuzz\nFizz\nFizz\nFizz\nFizz\nFizzBuzz\nFizz\n";
    expected += "Fizz\nFizz\nFizz\nBuzz\n41\nFizz\nFizz\n44\nFizzBuzz\n46\n47\n";
    expected += "Fizz\n49\nBuzz\nFizzBuzz\nBuzz\nFizzBuzz\nFizzBuzz\nBuzz\nBuzz\n";
    expected += "FizzBuzz\nBuzz\nBuzz\nFizzBuzz\n61\n62\nFizz\n64\n";
    expected += "Buzz\nFizz\n67\n68\nFizz\nBuzz\n71\nFizz\nFizz\n74\nFizzBuzz\n76\n";
    expected += "77\nFizz\n79\nBuzz\nFizz\n82\nFizz\nFizz\nBuzz\n86\nFizz\n88\n89\n";
    expected += "FizzBuzz\n91\n92\nFizz\n94\nBuzz\nFizz\n97\n98\nFizz\nBuzz";

    // Join the results
    const std::string joined = string_join(range_result);

    EXPECT_EQ(joined, expected) << "FizzbuzzRange(100) produced incorrect result";
}
