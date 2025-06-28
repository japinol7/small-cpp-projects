#include <gtest/gtest.h>

#include "../../../../projects/cyber_dojo/mine_field/mine_field_take_01/src/mine_field.hpp"

class MineFieldTest : public ::testing::Test {
    // No setup or teardown needed
};

TEST_F(MineFieldTest, TestResolve1) {
    const std::string board = "3 4\n"
        "*...\n"
        "..*.\n"
        "....";
    const std::string expected = ""
        "*211\n"
        "12*1\n"
        "0111";

    const MineField mf(board);
    const std::string result = mf.resolve();
    EXPECT_EQ(result, expected);
}

TEST_F(MineFieldTest, TestResolve2) {
    const std::string board = "5 4\n"
        "*...\n"
        "..*.\n"
        "...* \n"
        "....\n"
        ".*.."; 
    const std::string expected = ""
        "*211\n"
        "12*2\n"
        "012*\n"
        "1121\n"
        "1*10";

    const MineField mf(board);
    const std::string result = mf.resolve();
    EXPECT_EQ(result, expected);
}

TEST_F(MineFieldTest, TestInvalidInput) {
    const std::string invalidBoard = "invalid";

    EXPECT_THROW({
        MineField mf(invalidBoard);
    }, std::invalid_argument);
}

TEST_F(MineFieldTest, TestEmptyInput) {
    const std::string emptyBoard;

    EXPECT_THROW({
        MineField mf(emptyBoard);
    }, std::invalid_argument);
}

TEST_F(MineFieldTest, TestInvalidDimensions) {
    const std::string invalidDimensions = "0 4\n"
        "*...\n"
        "..*.\n"
        "....";

    EXPECT_THROW({
        MineField mf(invalidDimensions);
    }, std::invalid_argument);
}

TEST_F(MineFieldTest, TestInvalidCharacter) {
    const std::string invalidChar = "3 4\n"
        "*...\n"
        ".X*.\n"
        "....";

    EXPECT_THROW({
        MineField mf(invalidChar);
    }, std::invalid_argument);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
