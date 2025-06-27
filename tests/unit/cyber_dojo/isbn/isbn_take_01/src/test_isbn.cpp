#include <gtest/gtest.h>

#include "../../../../projects/cyber_dojo/isbn/isbn_take_01/src/isbn.hpp"

struct IsbnTestCase {
    std::string input_isbn;
    std::string expected;

    static std::string GetTestName(
        const testing::TestParamInfo<IsbnTestCase>& info
    ) {
        // Replace invalid filename characters with underscores
        std::string name = info.param.input_isbn;
        std::replace(name.begin(), name.end(), ' ', '_');
        std::replace(name.begin(), name.end(), '-', '_');
        std::replace(name.begin(), name.end(), '*', '_');
        return std::to_string(info.index) + "_" + "ISBN_" + name;
    }
};

class IsbnValidationTest : public testing::TestWithParam<
    IsbnTestCase> {
};

TEST_P(IsbnValidationTest, ValidateISBN) {
    const auto& [input_isbn, expected] = GetParam();
    const auto result = ISBN::validate(input_isbn);
    ASSERT_TRUE(result.has_value());
    EXPECT_EQ(result.value(), expected)
        << "ISBN::validate(\"" << input_isbn << "\") = \""
        << result.value() << "\", want \"" << expected << "\"";
}

INSTANTIATE_TEST_SUITE_P(
    ISBN13Tests,
    IsbnValidationTest,
    testing::Values(
        IsbnTestCase{"9780470059029", "true"},
        IsbnTestCase{"978 0 471 48648 0", "true"},
        IsbnTestCase{"978-0596809485", "true"},
        IsbnTestCase{"978-0-13-149505-0", "true"},
        IsbnTestCase{"978-0-262-13472-9", "true"},
        IsbnTestCase{"978-0-262-13472-1", "false"},
        IsbnTestCase{"978-0-262-13472-2", "false"},
        IsbnTestCase{"978 0 A 471 48648 0", "false"},
        IsbnTestCase{"978 0 * 471 48648 0", "false"},
        IsbnTestCase{"978-0-262-13472-X", "false"},
        IsbnTestCase{"978-13472-2", "false"},
        IsbnTestCase{"978-0-A62-13472-1", "false"}
    ),
    IsbnTestCase::GetTestName
);

INSTANTIATE_TEST_SUITE_P(
    ISBN10Tests,
    IsbnValidationTest,
    testing::Values(
        IsbnTestCase{"0471958697", "true"},
        IsbnTestCase{"0 471 60695 2", "true"},
        IsbnTestCase{"0-470-84525-2", "true"},
        IsbnTestCase{"0-321-14653-0", "true"},
        IsbnTestCase{"0-8044-2957-X", "true"},
        IsbnTestCase{"0-9752298-0-X", "true"},
        IsbnTestCase{"0-8044-2957-D", "false"},
        IsbnTestCase{"0-470-84525-3", "false"},
        IsbnTestCase{"0-4A0-84525-2", "false"},
        IsbnTestCase{"0-470-*4525-2", "false"},
        IsbnTestCase{"0-470-8425-2", "false"}
    ),
    IsbnTestCase::GetTestName
);

TEST(IsbnTest, EdgeCases) {
    // Empty string
    const auto emptyResult = ISBN::validate("");
    ASSERT_TRUE(emptyResult.has_value());
    EXPECT_EQ(emptyResult.value(), "false");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
