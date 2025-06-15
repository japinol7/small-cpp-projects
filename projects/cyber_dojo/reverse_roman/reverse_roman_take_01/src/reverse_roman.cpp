#include "reverse_roman.hpp"
#include <map>
#include <vector>

namespace ReverseRoman {

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

} // namespace ReverseRoman
