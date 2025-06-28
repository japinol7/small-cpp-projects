#include "count_coins.hpp"
#include <iostream>

int main() {
    const char* app_name = "Count coins";
    std::cout << "Start app " << app_name << std::endl;

    const CountCoins cc;
    const int result = cc.changes(100);

    std::cout << "How many ways are there to make change for a dollar" << std::endl;
    std::cout << "using these common coins? (1 dollar = 100 cents)" << std::endl;
    std::cout << "Result: " << result << std::endl;

    std::cout << "End app " << app_name << std::endl;

    return 0;
}
