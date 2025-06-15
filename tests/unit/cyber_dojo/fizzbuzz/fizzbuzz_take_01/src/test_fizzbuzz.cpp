#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../../../../projects/cyber_dojo/fizzbuzz/fizzbuzz_take_01/src/fizzbuzz.hpp"
#include "../../../../projects/cyber_dojo/fizzbuzz/fizzbuzz_take_01/src/utils/utils.hpp"

using namespace ::testing;

class FizzbuzzTest : public Test {
};

TEST_F(FizzbuzzTest, SingleNumbers) {
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
        {13, "13"},
        {15, "FizzBuzz"},
        {52, "52"}
    };

    for (const auto& [input, expected] : tests) {
        std::string result = fizzbuzz(input);
        EXPECT_EQ(result, expected)
            << "Fizzbuzz(" << input << ") = "
            << result << ", want " << expected;
    }
}

TEST_F(FizzbuzzTest, Range) {
    struct TestCase {
        int input;
        std::string expected;
    };

    const std::vector<TestCase> tests = {
        {1, "1"},
        {2, "1\n2"},
        {15, "1\n2\nFizz\n4\nBuzz\nFizz\n7\n8\nFizz\nBuzz\n11\nFizz\n13\n14\nFizzBuzz"}
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

TEST_F(FizzbuzzTest, RangeUntilOneHundred) {
    constexpr int n = 100;

    // Generate FizzBuzz range
    const auto range_result = fizzbuzz_range(n);

    // Create expected string for 1-100 FizzBuzz sequence
    std::string expected;
    expected += "1\n2\nFizz\n4\nBuzz\nFizz\n7\n8\nFizz\nBuzz\n11\nFizz\n13\n14\n";
    expected += "FizzBuzz\n16\n17\nFizz\n19\nBuzz\nFizz\n22\n23\nFizz\nBuzz\n26\n";
    expected += "Fizz\n28\n29\nFizzBuzz\n31\n32\nFizz\n34\nBuzz\nFizz\n37\n38\nFizz\n";
    expected += "Buzz\n41\nFizz\n43\n44\nFizzBuzz\n46\n47\nFizz\n49\nBuzz\nFizz\n";
    expected += "52\n53\nFizz\nBuzz\n56\nFizz\n58\n59\nFizzBuzz\n61\n62\nFizz\n64\n";
    expected += "Buzz\nFizz\n67\n68\nFizz\nBuzz\n71\nFizz\n73\n74\nFizzBuzz\n76\n";
    expected += "77\nFizz\n79\nBuzz\nFizz\n82\n83\nFizz\nBuzz\n86\nFizz\n88\n89\n";
    expected += "FizzBuzz\n91\n92\nFizz\n94\nBuzz\nFizz\n97\n98\nFizz\nBuzz";

    // Join the results
    const std::string joined = string_join(range_result);

    EXPECT_EQ(joined, expected) << "FizzbuzzRange(100) produced incorrect result";
}
