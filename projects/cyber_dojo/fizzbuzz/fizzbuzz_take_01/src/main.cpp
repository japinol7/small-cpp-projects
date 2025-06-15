#include <iostream>
#include <string>
#include "fizzbuzz.hpp"
#include "utils/utils.hpp"

int main() {
    const std::string appName = "Fizzbuzz";
    std::cout << "Start app " << appName << std::endl;

    constexpr int n = 15;

    // Generate FizzBuzz strings for numbers 1 to n
    const auto result = fizzbuzz_range(n);

    // Join the results with newlines
    const std::string output = string_join(result);

    // Print the result
    std::cout << output << std::endl;

    std::cout << "\nEnd app " << appName << std::endl;
    return 0;
}
