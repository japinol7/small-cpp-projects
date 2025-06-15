#include "fizzbuzz_plus.hpp"
#include <string>

bool contains_digit(int number, const int digit) {
    while (number > 0) {
        if (number % 10 == digit) {
            return true;
        }
        number /= 10;
    }
    return false;
}

std::string fizzbuzz(const int n) {
    std::string result;

    if (n % 3 == 0 || contains_digit(n, 3)) {
        result += "Fizz";
    }

    if (n % 5 == 0 || contains_digit(n, 5)) {
        result += "Buzz";
    }

    // If not divisible by 3 or 5 and doesn't contain 3 or 5, use the number itself
    if (result.empty()) {
        result = std::to_string(n);
    }

    return result;
}

std::vector<std::string> fizzbuzz_range(const int n) {
    // Return empty vector for invalid input
    if (n <= 0) {
        return {};
    }

    std::vector<std::string> result;
    result.reserve(n); // Pre-allocate memory for efficiency

    for (int i = 1; i <= n; ++i) {
        result.push_back(fizzbuzz(i));
    }

    return result;
}
