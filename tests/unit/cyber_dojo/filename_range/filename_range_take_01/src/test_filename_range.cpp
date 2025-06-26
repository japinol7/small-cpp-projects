#include <gtest/gtest.h>

#include "../../../../projects/cyber_dojo/filename_range/filename_range_take_01/src/filename_range.hpp"

using namespace ::testing;

struct FilenameTestCase {
    std::string filename;
    std::vector<int> expected;

    static std::string GetTestName(
        const TestParamInfo<FilenameTestCase>& info
    ) {
        if (info.param.filename.empty()) {
            return std::to_string(info.index) + "_" + "Empty";
        }
        // Replace potentially problematic characters in the filename
        std::string name = info.param.filename;
        std::replace(name.begin(), name.end(), '/', '_');
        std::replace(name.begin(), name.end(), '\\', '_');
        std::replace(name.begin(), name.end(), '.', '_');
        std::replace(name.begin(), name.end(), '-', '_');
        std::replace(name.begin(), name.end(), ' ', '_');
        return std::to_string(info.index) + "_" + name;
    }
};

class FilenameRangeTest : public TestWithParam<FilenameTestCase> {
};

TEST_P(FilenameRangeTest, CheckRange) {
    const auto& [filename, expected] = GetParam();
    const auto result = filename_range(filename);

    if (expected.empty()) {
        EXPECT_FALSE(result.has_value()) 
            << "For filename '" << filename << "' expected no value, but got one";
    } else {
        ASSERT_TRUE(result.has_value()) 
            << "For filename '" << filename << "' expected a value, but got none";
        EXPECT_EQ((*result)[0], expected[0]) 
            << "Start index mismatch for '" << filename << "'";
        EXPECT_EQ((*result)[1], expected[1]) 
            << "End index mismatch for '" << filename << "'";
    }
}

INSTANTIATE_TEST_SUITE_P(
    FilenameTests,
    FilenameRangeTest,
    testing::Values(
        FilenameTestCase{"src/Hiker_spec.re", {4, 9}},
        FilenameTestCase{"test/hiker_test.exs", {5, 10}},
        FilenameTestCase{"wibble/test/hiker_spec.rb", {12, 17}},
        FilenameTestCase{"hiker_steps.rb", {0, 5}},
        FilenameTestCase{"hiker_spec.rb", {0, 5}},
        FilenameTestCase{"test_hiker.rb", {5, 10}},
        FilenameTestCase{"test_hiker.py", {5, 10}},
        FilenameTestCase{"test_hiker.sh", {5, 10}},
        FilenameTestCase{"tests_hiker.sh", {6, 11}},
        FilenameTestCase{"test_hiker.coffee", {5, 10}},
        FilenameTestCase{"hiker_spec.coffee", {0, 5}},
        FilenameTestCase{"hikerTest.chpl", {0, 5}},
        FilenameTestCase{"hiker.tests.c", {0, 5}},
        FilenameTestCase{"hiker_tests.c", {0, 5}},
        FilenameTestCase{"hiker_test.c", {0, 5}},
        FilenameTestCase{"hiker_Test.c", {0, 5}},
        FilenameTestCase{"HikerTests.cpp", {0, 5}},
        FilenameTestCase{"hikerTests.cpp", {0, 5}},
        FilenameTestCase{"HikerTest.cs", {0, 5}},
        FilenameTestCase{"HikerTest.java", {0, 5}},
        FilenameTestCase{"DiamondTest.kt", {0, 7}},
        FilenameTestCase{"HikerTest.php", {0, 5}},
        FilenameTestCase{"hikerTest.js", {0, 5}},
        FilenameTestCase{"hiker-test.js", {0, 5}},
        FilenameTestCase{"hiker-spec.js", {0, 5}},
        FilenameTestCase{"hiker.test.js", {0, 5}},
        FilenameTestCase{"hiker.tests.ts", {0, 5}},
        FilenameTestCase{"hiker_tests.erl", {0, 5}},
        FilenameTestCase{"hiker_test.clj", {0, 5}},
        FilenameTestCase{"fizzBuzz_test.d", {0, 8}},
        FilenameTestCase{"hiker_test.go", {0, 5}},
        FilenameTestCase{"hiker.tests.R", {0, 5}},
        FilenameTestCase{"hikertests.swift", {0, 5}},
        FilenameTestCase{"HikerSpec.groovy", {0, 5}},
        FilenameTestCase{"hikerSpec.feature", {0, 5}},
        FilenameTestCase{"hiker.feature", {0, 5}},
        FilenameTestCase{"hiker.fun", {0, 5}},
        FilenameTestCase{"hiker.t", {0, 5}},
        FilenameTestCase{"hiker.plt", {0, 5}},
        FilenameTestCase{"prj/src/Hiker_bike_spec.re.bak", {8, 18}},
        FilenameTestCase{"src\\Hiker_spec.re", {4, 9}},
        FilenameTestCase{"hiker", {0, 5}},
        FilenameTestCase{"", {}}
    ),
    FilenameTestCase::GetTestName
);

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}