#include <gtest/gtest.h>

#include "../../../../projects/cyber_dojo/fizzbuzz/fizzbuzz_take_01/src/fizzbuzz.hpp"
#include "../../../../projects/cyber_dojo/fizzbuzz/fizzbuzz_take_01/src/utils/utils.hpp"

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
        SingleNumberTestCase{13, "13"},
        SingleNumberTestCase{15, "FizzBuzz"},
        SingleNumberTestCase{52, "52"}
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
            "1\n2\nFizz\n4\nBuzz\nFizz\n7\n8\nFizz\nBuzz\n11\nFizz\n13\n14\nFizzBuzz"}
    ),
    RangeTestCase::GetTestName
);

TEST(FizzbuzzTest, RangeUntilOneHundred) {
    constexpr int n = 100;
    const auto range_result = fizzbuzz_range(n);

    std::string expected;
    expected += "1\n2\nFizz\n4\nBuzz\nFizz\n7\n8\nFizz\nBuzz\n11\nFizz\n13\n14\n";
    expected += "FizzBuzz\n16\n17\nFizz\n19\nBuzz\nFizz\n22\n23\nFizz\nBuzz\n26\n";
    expected += "Fizz\n28\n29\nFizzBuzz\n31\n32\nFizz\n34\nBuzz\nFizz\n37\n38\nFizz\n";
    expected += "Buzz\n41\nFizz\n43\n44\nFizzBuzz\n46\n47\nFizz\n49\nBuzz\nFizz\n";
    expected += "52\n53\nFizz\nBuzz\n56\nFizz\n58\n59\nFizzBuzz\n61\n62\nFizz\n64\n";
    expected += "Buzz\nFizz\n67\n68\nFizz\nBuzz\n71\nFizz\n73\n74\nFizzBuzz\n76\n";
    expected += "77\nFizz\n79\nBuzz\nFizz\n82\n83\nFizz\nBuzz\n86\nFizz\n88\n89\n";
    expected += "FizzBuzz\n91\n92\nFizz\n94\nBuzz\nFizz\n97\n98\nFizz\nBuzz";

    const std::string joined = string_join(range_result);
    EXPECT_EQ(joined, expected) << "FizzbuzzRange(100) produced incorrect result";
}
