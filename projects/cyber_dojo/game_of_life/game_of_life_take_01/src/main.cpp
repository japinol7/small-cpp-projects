#include "game_of_life.hpp"
#include <iostream>
#include <vector>
#include <string>

int main() {
    const std::string app_name = "Game of Life";
    std::cout << "Start app " << app_name << std::endl;

    const std::vector<std::string> grid_pattern = {
        "........",
        "....*...",
        "...**...",
        ".....*.."
    };

    // Create game from pattern
    try {
        GameOfLife game(4, 8, grid_pattern);

        // Set cell representation
        bool result = game.setCellRepresentation("*", ".", "");
        if (!result) {
            std::cerr << "Error: Failed to set cell representation" << std::endl;
            std::cout << "End app " << app_name << std::endl;
            return 1;
        }

        // Run some generations
        constexpr int generations_to_run = 4;
        for (int i = 0; i < generations_to_run; ++i) {
            std::cout << "\nGeneration " << (i + 1) << std::endl;

            // Get and print the current state
            std::cout << game.toString();

            // Calculate next generation (except for the last iteration)
            if (i < generations_to_run - 1) {
                game.calcNextGeneration();
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cout << "End app " << app_name << std::endl;
        return 1;
    }

    std::cout << "End app " << app_name << std::endl;
    return 0;
}
