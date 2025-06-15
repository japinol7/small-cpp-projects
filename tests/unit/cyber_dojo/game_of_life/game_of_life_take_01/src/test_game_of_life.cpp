#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../../../../projects/cyber_dojo/game_of_life/game_of_life_take_01/src/game_of_life.hpp"

using namespace ::testing;

class GameOfLifeTest : public Test {
protected:
    // Helper method to create a game with a specific pattern
    static GameOfLife createGameWithPattern(
        const std::vector<std::string>& pattern, const int height, const int width
    ) {
        GameOfLife game(height, width, pattern);
        game.setCellRepresentation("*", ".", "");
        return game;
    }
};

// Test initialization of game
TEST_F(GameOfLifeTest, Init) {
    const GameOfLife game(5, 5);

    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 5; ++x) {
            EXPECT_FALSE(game.getCell(x, y))
                << "Expected cell (" << x << "," << y << ") to be dead";
        }
    }
}

// Test setting and getting cell state
TEST_F(GameOfLifeTest, SetAndGetCell) {
    GameOfLife game(5, 5);

    game.setCell(1, 2, true);
    EXPECT_TRUE(game.getCell(1, 2))
        << "Expected cell (1,2) to be alive";
}

// Test counting neighbors
TEST_F(GameOfLifeTest, CountNeighbors) {
    GameOfLife game(5, 5);

    game.setCell(1, 1, true);
    game.setCell(2, 1, true);
    game.setCell(1, 2, true);

    const int neighbors1 = game.countNeighbors(1, 1);
    EXPECT_EQ(2, neighbors1)
        << "Expected cell (1,1) to have 2 neighbors, got " << neighbors1;

    const int neighbors2 = game.countNeighbors(2, 2);
    EXPECT_EQ(3, neighbors2)
        << "Expected cell (2,2) to have 3 neighbors, got " << neighbors2;
}

// Test cell dying from underpopulation
TEST_F(GameOfLifeTest, StepUnderpopulation) {
    GameOfLife game(5, 5);

    game.setCell(1, 1, true);

    game.calcNextGeneration();
    game.setCellRepresentation("*", ".", "");

    EXPECT_FALSE(game.getCell(1, 1))
        << "Expected cell (1,1) to die from underpopulation";
}

// Test cell dying from overpopulation
TEST_F(GameOfLifeTest, StepOverpopulation) {
    GameOfLife game(5, 5);

    game.setCell(1, 1, true);
    game.setCell(0, 0, true);
    game.setCell(0, 1, true);
    game.setCell(0, 2, true);
    game.setCell(1, 0, true);

    game.calcNextGeneration();
    game.setCellRepresentation("*", ".", "");

    EXPECT_FALSE(game.getCell(1, 1))
        << "Expected cell (1,1) to die from overpopulation";
}

// Test cell reproduction
TEST_F(GameOfLifeTest, StepReproduction) {
    const std::vector<std::string> input = {
        "**...",
        "*....",
        ".....",
        ".....",
        "....."
    };

    GameOfLife game = createGameWithPattern(input, 5, 5);
    game.calcNextGeneration();

    EXPECT_TRUE(game.getCell(1, 1))
        << "Expected cell (1,1) to become alive from reproduction";
}

// Test next generation calculation from grid pattern 1
TEST_F(GameOfLifeTest, NextGenerationFromGrid1) {
    const std::vector<std::string> input = {
        "........",
        "....*...",
        "...**...",
        ".....*.."
    };

    const std::vector<std::string> expected = {
        "........",
        "...**...",
        "...***..",
        "....*..."
    };

    GameOfLife game = createGameWithPattern(input, 4, 8);
    game.calcNextGeneration();

    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 8; ++x) {
            bool expected_state = (expected[y][x] == '*');
            EXPECT_EQ(expected_state, game.getCell(x, y))
                << "At position (" << x << "," << y << "): expected " << expected_state
                << ", got " << game.getCell(x, y);
        }
    }
}

// Test next generation calculation from grid pattern 2
TEST_F(GameOfLifeTest, NextGenerationFromGrid2) {
    const std::vector<std::string> input = {
        "........",
        "...**...",
        ".*****..",
        "........",
        "........"
    };

    const std::vector<std::string> expected = {
        "........",
        ".....*..",
        "..*..*..",
        "..***...",
        "........"
    };

    GameOfLife game = createGameWithPattern(input, 5, 8);
    game.calcNextGeneration();

    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 8; ++x) {
            bool expected_state = (expected[y][x] == '*');
            EXPECT_EQ(expected_state, game.getCell(x, y))
                << "At position (" << x << "," << y << "): expected " << expected_state
                << ", got " << game.getCell(x, y);
        }
    }
}

// Test with custom cell representation
TEST_F(GameOfLifeTest, NextGenerationFromGridCustomCellRepr) {
    const std::vector<std::string> input = {
        "--------",
        "---@@---",
        "-@@@@@--",
        "--------",
        "--------"
    };

    const std::vector<std::string> expected = {
        "--------",
        "-----@--",
        "--@--@--",
        "--@@@---",
        "--------"
    };

    GameOfLife game(5, 8, input);
    game.setCellRepresentation("@", "-", " ");
    game.calcNextGeneration();

    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 8; ++x) {
            bool expected_state = (expected[y][x] == '@');
            EXPECT_EQ(expected_state, game.getCell(x, y))
                << "At position (" << x << "," << y << "): expected " << expected_state
                << ", got " << game.getCell(x, y);
        }
    }
}

// Test overpopulation with custom cell representation
TEST_F(GameOfLifeTest, StepOverpopulationCustomCellRepr) {
    GameOfLife game(5, 5);

    game.setCell(1, 1, true);
    game.setCell(0, 0, true);
    game.setCell(0, 1, true);
    game.setCell(0, 2, true);
    game.setCell(1, 0, true);

    game.calcNextGeneration();
    game.setCellRepresentation("@", "-", " ");

    EXPECT_FALSE(game.getCell(1, 1))
        << "Expected cell (1,1) to die from overpopulation";
}
