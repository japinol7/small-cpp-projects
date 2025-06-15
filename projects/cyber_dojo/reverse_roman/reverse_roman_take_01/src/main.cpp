#include "reverse_roman.hpp"
#include <iostream>
#include <vector>
#include <string>

int main() {
    const std::string appName = "Roman Numerals Full";

    std::cout << "Start app: " << appName << std::endl;

    // Examples of Roman numeral to number conversion
    const std::vector<std::string> ReverseRoman = {
        "I", "IV", "IX", "XIV", "XLII", "LXXIII", "XCIX", "MMXXIII"
    };

    std::cout << "\nConverting Roman numerals to numbers:" << std::endl;
    for (const auto& roman : ReverseRoman) {
        int result = 0;
        if (ReverseRoman::Converter::fromRoman(roman, result)) {
            std::cout << roman << " -> " << result << std::endl;
        } else {
            std::cout << "Error converting " << roman << std::endl;
        }
    }

    std::cout << "\nEnd app: " << appName << std::endl;
    return 0;
}
