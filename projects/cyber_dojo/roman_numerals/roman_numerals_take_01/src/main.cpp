#include "roman_numerals.hpp"
#include <iostream>
#include <vector>
#include <string>

int main() {
    const std::string appName = "Roman Numerals";

    std::cout << "Start app: " << appName << std::endl;

    // Examples of number to Roman numeral conversion
    const std::vector<int> numbers = {1, 4, 9, 14, 42, 73, 99, 2023};

    std::cout << "\nConverting numbers to Roman numerals:" << std::endl;
    for (const auto& num : numbers) {
        std::string roman = RomanNumerals::Converter::toRoman(num);
        if (!roman.empty()) {
            std::cout << num << " -> " << roman << std::endl;
        } else {
            std::cout << "Error converting " << num << std::endl;
        }
    }

    std::cout << "\nEnd app: " << appName << std::endl;
    return 0;
}
