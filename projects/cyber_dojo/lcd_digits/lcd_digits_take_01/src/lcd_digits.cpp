#include "lcd_digits.hpp"
#include "lcd_digit_cell.hpp"

#include <sstream>
#include <vector>
#include <memory>
#include <cstdio>
#include <array>

namespace LcdDisplay {

std::optional<std::string> LcdDigits::Generate(
    const int number, const std::string& separator
) const {
    if (number < 0) {
        lastError_ = "Number must be non-negative";
        return std::nullopt;
    }

    // Handle the single digit case
    if (number <= 9) {
        return GenerateSingleDigit(number);
    }

    // Handle the multi-digit case
    return GenerateMultipleDigits(number, separator);
}

std::string LcdDigits::GetLastError() const {
    return lastError_;
}

std::optional<std::string> LcdDigits::GenerateSingleDigit(const int digit) const {
    constexpr size_t BUFFER_SIZE = 1024;
    std::array<char, BUFFER_SIZE> buffer{};

    const int result = std::snprintf(
        buffer.data(), buffer.size(),
        NUM_TO_LCD_DIGIT_MAPPING[digit], "\n", "\n", "\n");

    if (result < 0 || static_cast<size_t>(result) >= buffer.size()) {
        lastError_ = "Buffer overflow when generating single digit";
        return std::nullopt;
    }

    return std::string(buffer.data());
}

std::optional<std::string> LcdDigits::GenerateMultipleDigits(
    const int number, const std::string& separator
) const {
    // Convert number to string
    const std::string numStr = std::to_string(number);
    const size_t numLen = numStr.length();

    // Vectors to hold the three parts of the digits
    std::vector<std::string> digitsTop(numLen);
    std::vector<std::string> digitsMid(numLen);
    std::vector<std::string> digitsBottom(numLen);

    // Buffer for formatting parts
    constexpr size_t PART_SIZE = 32;
    std::array<char, PART_SIZE> buffer{};

    // Generate each part of each digit
    for (size_t i = 0; i < numLen; ++i) {
        const int digit = numStr[i] - '0';
        const std::string currentSeparator = (i < numLen - 1) ? separator : "\n";

        const char* digitTemplate = NUM_TO_LCD_DIGIT_MAPPING[digit];

        // Create each part with the correct separator
        int result = std::snprintf(
            buffer.data(), buffer.size(), "%.3s%s",
                  digitTemplate, currentSeparator.c_str());
        if (result < 0 || static_cast<size_t>(result) >= buffer.size()) {
            lastError_ = "Buffer overflow when generating top part";
            return std::nullopt;
        }
        digitsTop[i] = buffer.data();

        result = std::snprintf(
            buffer.data(), buffer.size(), "%.3s%s",
                  digitTemplate + 5, currentSeparator.c_str());

        if (result < 0 || static_cast<size_t>(result) >= buffer.size()) {
            lastError_ = "Buffer overflow when generating middle part";
            return std::nullopt;
        }
        digitsMid[i] = buffer.data();

        result = std::snprintf(buffer.data(), buffer.size(), "%.3s%s",
                               digitTemplate + 10, currentSeparator.c_str());

        if (result < 0 || static_cast<size_t>(result) >= buffer.size()) {
            lastError_ = "Buffer overflow when generating bottom part";
            return std::nullopt;
        }
        digitsBottom[i] = buffer.data();
    }

    // Combine all parts into the output string
    std::ostringstream outputStream;

    for (const auto& part : digitsTop) {
        outputStream << part;
    }

    for (const auto& part : digitsMid) {
        outputStream << part;
    }

    for (const auto& part : digitsBottom) {
        outputStream << part;
    }

    return outputStream.str();
}

} // namespace LcdDisplay
