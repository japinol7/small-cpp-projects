#include <gtest/gtest.h>
#include <string>
#include <map>
#include <vector>
#include <optional>
#include <array>

#include "../../../../projects/cyber_dojo/filename_range/filename_range_take_01/src/filename_range.hpp"

// Test class for the filename_range function
class FilenameRangeTest : public ::testing::Test {
protected:
    // Define a map of test cases with expected results
    std::map<std::string, std::vector<int>> test_cases;

    void SetUp() override {
        // Initialize all test cases
        test_cases = {
            {"src/Hiker_spec.re", {4, 9}},
            {"test/hiker_test.exs", {5, 10}},
            {"wibble/test/hiker_spec.rb", {12, 17}},
            {"hiker_steps.rb", {0, 5}},
            {"hiker_spec.rb", {0, 5}},
            {"test_hiker.rb", {5, 10}},
            {"test_hiker.py", {5, 10}},
            {"test_hiker.sh", {5, 10}},
            {"tests_hiker.sh", {6, 11}},
            {"test_hiker.coffee", {5, 10}},
            {"hiker_spec.coffee", {0, 5}},
            {"hikerTest.chpl", {0, 5}},
            {"hiker.tests.c", {0, 5}},
            {"hiker_tests.c", {0, 5}},
            {"hiker_test.c", {0, 5}},
            {"hiker_Test.c", {0, 5}},
            {"HikerTests.cpp", {0, 5}},
            {"hikerTests.cpp", {0, 5}},
            {"HikerTest.cs", {0, 5}},
            {"HikerTest.java", {0, 5}},
            {"DiamondTest.kt", {0, 7}},
            {"HikerTest.php", {0, 5}},
            {"hikerTest.js", {0, 5}},
            {"hiker-test.js", {0, 5}},
            {"hiker-spec.js", {0, 5}},
            {"hiker.test.js", {0, 5}},
            {"hiker.tests.ts", {0, 5}},
            {"hiker_tests.erl", {0, 5}},
            {"hiker_test.clj", {0, 5}},
            {"fizzBuzz_test.d", {0, 8}},
            {"hiker_test.go", {0, 5}},
            {"hiker.tests.R", {0, 5}},
            {"hikertests.swift", {0, 5}},
            {"HikerSpec.groovy", {0, 5}},
            {"hikerSpec.feature", {0, 5}},
            {"hiker.feature", {0, 5}},
            {"hiker.fun", {0, 5}},
            {"hiker.t", {0, 5}},
            {"hiker.plt", {0, 5}},
            {"prj/src/Hiker_bike_spec.re.bak", {8, 18}},
            {"src\\Hiker_spec.re", {4, 9}},
            {"hiker", {0, 5}},
            {"", {}}
        };
    }

    // Helper method to verify a single test case
    static void verify_single_case(
        const std::string& filename, const std::vector<int>& expected
    ) {
        const auto result = filename_range(filename);

        if (expected.empty()) {
            // For empty filename, we expect std::nullopt
            EXPECT_FALSE(result.has_value()) << "For empty filename '" << filename << "'";
        } else {
            // For valid filenames, we expect a valid array
            ASSERT_TRUE(result.has_value()) << "For filename '" << filename << "'";
            EXPECT_EQ((*result)[0], expected[0]) << "Start index mismatch for '" << filename << "'";
            EXPECT_EQ((*result)[1], expected[1]) << "End index mismatch for '" << filename << "'";
        }
    }
};

// Test all filename cases using the helper method
TEST_F(FilenameRangeTest, AllFilenameCases) {
    for (const auto& [fst, snd] : test_cases) {
        verify_single_case(fst, snd);
    }
}

// Test empty filename
TEST_F(FilenameRangeTest, EmptyFilename) {
    const auto result = filename_range("");
    EXPECT_FALSE(result.has_value()) << "For empty filename";
}

// Individual tests for specific cases
TEST_F(FilenameRangeTest, RegularFilename) {
    const auto result = filename_range("hiker.cpp");
    ASSERT_TRUE(result.has_value());
    EXPECT_EQ((*result)[0], 0);
    EXPECT_EQ((*result)[1], 5);
}

TEST_F(FilenameRangeTest, TestFilename) {
    const auto result = filename_range("test_hiker.rb");
    ASSERT_TRUE(result.has_value());
    EXPECT_EQ((*result)[0], 5);
    EXPECT_EQ((*result)[1], 10);
}

TEST_F(FilenameRangeTest, PathWithTestFilename) {
    const auto result = filename_range("wibble/test/hiker_spec.rb");
    ASSERT_TRUE(result.has_value());
    EXPECT_EQ((*result)[0], 12);
    EXPECT_EQ((*result)[1], 17);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
