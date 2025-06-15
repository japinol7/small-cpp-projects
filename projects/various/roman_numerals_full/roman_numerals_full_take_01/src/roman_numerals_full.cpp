#include "roman_numerals_full.hpp"
#include <map>
#include <vector>

namespace RomanNumeralsFull {

std::string Converter::toRoman(int num) {
    // Check if num is within valid range
    if (num <= 0 || num > 3999) {
        return ""; // Error: number out of range
    }

    // Define Roman numeral symbols and their values
    const std::vector<std::pair<int, std::string>> romanNumerals = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    // Build Roman numeral
    std::string result;
    for (const auto& [value, symbol] : romanNumerals) {
        while (num >= value) {
            result += symbol;
            num -= value;
        }
    }

    return result;
}

bool Converter::fromRoman(const std::string& roman, int& result) {
    if (roman.empty()) {
        return false; // Error: invalid input
    }

    // Map for Roman numeral symbols to values
    const std::map<char, int> romanValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int total = 0;
    int prevValue = 0;

    // Process from right to left
    for (auto it = roman.rbegin(); it != roman.rend(); ++it) {
        const char ch = *it;

        // Find the value for this symbol
        auto valueIt = romanValues.find(ch);
        if (valueIt == romanValues.end()) {
            return false; // Error: invalid Roman numeral character
        }

        int value = valueIt->second;

        // Add or subtract based on position
        if (value >= prevValue) {
            total += value;
        } else {
            total -= value;
        }
        prevValue = value;
    }

    // Check if the result is within the valid range for Roman numerals
    if (total <= 0 || total > 3999) {
        return false; // Error: number out of range
    }

    result = total;
    return true; // Success
}

} // namespace RomanNumeralsFull
