#ifndef LCD_DIGIT_CELL_HPP
#define LCD_DIGIT_CELL_HPP

#include <array>
#include <string_view>

namespace LcdDisplay {

// Chars used to display LCD digits
constexpr char CELL_H = '_'; // Horizontal segment
constexpr char CELL_V = '|'; // Vertical segment
constexpr char CELL_O = '.'; // Off segment
constexpr std::string_view SEPARATOR = " "; // Default separator

// Mapping of digits to their LCD representation with placeholders
extern const std::array<const char*, 10> NUM_TO_LCD_DIGIT_MAPPING;

} // namespace LcdDisplay

#endif // LCD_DIGIT_CELL_HPP
