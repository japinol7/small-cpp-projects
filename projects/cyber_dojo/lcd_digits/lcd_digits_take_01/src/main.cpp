#include "lcd_digits.hpp"
#include <iostream>

int main() {
    const std::string appName = "LCD Digits";
    std::cout << "Start app " << appName << std::endl;

    constexpr int inputNumber = 1234567890;
    const LcdDisplay::LcdDigits lcd;

    auto result = lcd.Generate(inputNumber);

    if (!result) {
        std::cout << "Error: " << lcd.GetLastError() << std::endl;
    } else {
        std::cout << "LCD Digits for " << inputNumber
                  << std::endl << *result << std::endl;
    }

    std::cout << "End app " << appName << std::endl;
    return 0;
}
