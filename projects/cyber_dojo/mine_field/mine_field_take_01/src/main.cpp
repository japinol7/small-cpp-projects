#include "mine_field.hpp"
#include <iostream>

int main() {
    const std::string app_name = "Mine Field";
    std::cout << "Start app " << app_name << std::endl;

    const std::string board = "3 4\n"
        "*...\n"
        "..*.\n"
        "....";

    try {
        const MineField mf(board);
        const std::string result = mf.resolve();

        std::cout << "Input:\n" << board
                  << "\n\nOutput:\n" << result << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cout << "End app " << app_name << std::endl;
        return 1;
    }

    std::cout << "End app " << app_name << std::endl;
    return 0;
}
