#include "fizzbuzz.hpp"
#include <string>

std::string fizzbuzz(const int n) {
    std::string result;

    if (n % 3 == 0) {
        result += "Fizz";
    }

    if (n % 5 == 0) {
        result += "Buzz";
    }

    // If not divisible by 3 or 5, use the number itself
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
