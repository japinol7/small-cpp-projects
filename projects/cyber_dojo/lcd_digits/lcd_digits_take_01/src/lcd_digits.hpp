#ifndef LCD_DIGITS_HPP
#define LCD_DIGITS_HPP

#include <string>
#include <optional>

namespace LcdDisplay {
// LcdDigits class generates LCD-style digit representations
class LcdDigits {
public:
    // Generates an LCD representation of a number
    // Returns the LCD representation string
    std::optional<std::string> Generate(
        int number, const std::string& separator = " ") const;

    // Error message when an error occurs
    std::string GetLastError() const;

private:
    mutable std::string lastError_;

    // Helper methods
    std::optional<std::string> GenerateSingleDigit(int digit) const;
    std::optional<std::string> GenerateMultipleDigits(
        int number, const std::string& separator) const;
};
} // namespace LcdDisplay

#endif // LCD_DIGITS_HPP
