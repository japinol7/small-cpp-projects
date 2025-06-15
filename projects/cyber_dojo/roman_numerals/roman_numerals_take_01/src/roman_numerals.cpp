#include "roman_numerals.hpp"
#include <vector>

namespace RomanNumerals {

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

} // namespace RomanNumerals
