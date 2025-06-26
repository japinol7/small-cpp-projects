#include <gtest/gtest.h>

#include "../../../../projects/cyber_dojo/fizzbuzz_plus/fizzbuzz_plus_take_01/src/fizzbuzz_plus.hpp"
#include "../../../../projects/cyber_dojo/fizzbuzz_plus/fizzbuzz_plus_take_01/src/utils/utils.hpp"

using namespace ::testing;

struct SingleNumberTestCase {
    int input;
    std::string expected;

    static std::string GetTestName(
        const TestParamInfo<SingleNumberTestCase>& info
    ) {
        return "Input_" + std::to_string(info.param.input);
    }
};

class FizzbuzzSingleTest : public TestWithParam<SingleNumberTestCase> {
};

TEST_P(FizzbuzzSingleTest, CheckSingleNumber) {
    const auto& [input, expected] = GetParam();
    const std::string result = fizzbuzz(input);
    EXPECT_EQ(result, expected)
        << "Fizzbuzz(" << input << ") = "
        << result << ", want " << expected;
}

INSTANTIATE_TEST_SUITE_P(
    FizzbuzzTests,
    FizzbuzzSingleTest,
    testing::Values(
        SingleNumberTestCase{1, "1"},
        SingleNumberTestCase{2, "2"},
        SingleNumberTestCase{3, "Fizz"},
        SingleNumberTestCase{4, "4"},
        SingleNumberTestCase{5, "Buzz"},
        SingleNumberTestCase{6, "Fizz"},
        SingleNumberTestCase{10, "Buzz"},
        SingleNumberTestCase{12, "Fizz"},
        SingleNumberTestCase{13, "Fizz"},
        SingleNumberTestCase{15, "FizzBuzz"},
        SingleNumberTestCase{52, "Buzz"}
    ),
    SingleNumberTestCase::GetTestName
);

struct RangeTestCase {
    int input;
    std::string expected;

    static std::string GetTestName(
        const TestParamInfo<RangeTestCase>& info
    ) {
        return "Range_" + std::to_string(info.param.input);
    }
};

class FizzbuzzRangeTest : public TestWithParam<RangeTestCase> {
};

TEST_P(FizzbuzzRangeTest, CheckRange) {
    const auto& [input, expected] = GetParam();
    const auto range_result = fizzbuzz_range(input);
    const std::string joined = string_join(range_result);

    EXPECT_EQ(joined, expected)
        << "string_join(fizzbuzz_range(" << input << ")) = "
        << joined << ", want " << expected;
}

INSTANTIATE_TEST_SUITE_P(
    FizzbuzzTests,
    FizzbuzzRangeTest,
    testing::Values(
        RangeTestCase{1, "1"},
        RangeTestCase{2, "1\n2"},
        RangeTestCase{15,
            "1\n2\nFizz\n4\nBuzz\nFizz\n7\n8\nFizz\nBuzz\n11\nFizz\nFizz\n14\nFizzBuzz"}
    ),
    RangeTestCase::GetTestName
);

TEST(FizzbuzzTest, RangeUntilOneHundred) {
    constexpr int n = 100;
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

    const std::string joined = string_join(range_result);
    EXPECT_EQ(joined, expected) << "FizzbuzzRange(100) produced incorrect result";
}