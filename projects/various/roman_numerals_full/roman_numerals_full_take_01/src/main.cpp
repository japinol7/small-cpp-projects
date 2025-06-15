#include "roman_numerals_full.hpp"
#include <iostream>
#include <vector>
#include <string>

int main() {
    const std::string appName = "Roman Numerals Full";

    std::cout << "Start app: " << appName << std::endl;

    // Examples of number to Roman numeral conversion
    const std::vector<int> numbers = {1, 4, 9, 14, 42, 73, 99, 2023};

    std::cout << "\nConverting numbers to Roman numerals:" << std::endl;
    for (const auto& num : numbers) {
        std::string roman = RomanNumeralsFull::Converter::toRoman(num);
        if (!roman.empty()) {
            std::cout << num << " -> " << roman << std::endl;
        } else {
            std::cout << "Error converting " << num << std::endl;
        }
    }

    // Examples of Roman numeral to number conversion
    const std::vector<std::string> RomanNumeralsFull = {
        "I", "IV", "IX", "XIV", "XLII", "LXXIII", "XCIX", "MMXXIII"
    };

    std::cout << "\nConverting Roman numerals to numbers:" << std::endl;
    for (const auto& roman : RomanNumeralsFull) {
        int result = 0;
        if (RomanNumeralsFull::Converter::fromRoman(roman, result)) {
            std::cout << roman << " -> " << result << std::endl;
        } else {
            std::cout << "Error converting " << roman << std::endl;
        }
    }

    std::cout << "\nEnd app: " << appName << std::endl;
    return 0;
}
