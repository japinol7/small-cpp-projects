#include <iostream>
#include <string>
#include <vector>
#include "leap_year.hpp"

int main() {
    const std::string appName = "Leap Year";
    std::cout << "Start app: " << appName << std::endl;

    const std::vector<int> exampleYears = {
        2001, 1996, 1900, 2000, 2023, 2024
    };

    for (const auto& year : exampleYears) {
        const bool result = isLeapYear(year);
        std::cout << "Is " << year << " a leap year: "
                  << (result ? "true" : "false") << std::endl;
    }

    std::cout << "End app: " << appName << std::endl;
    return 0;
}
