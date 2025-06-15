#ifndef ROMAN_NUMERALS_FULL_HPP
#define ROMAN_NUMERALS_FULL_HPP

#include <string>

namespace RomanNumeralsFull {

// Class for Roman numeral conversions
class Converter {
public:
    // Converts an integer to a Roman numeral string
    // @param num The integer to convert (must be between 1 and 3999 inclusive)
    // @return Roman numeral string on success, empty string on error
    static std::string toRoman(int num);

    // Converts a Roman numeral string to an integer
    // @param roman The Roman numeral string to convert
    // @param result Reference to store the resulting integer value
    // @return true on success, false on error
    static bool fromRoman(const std::string& roman, int& result);
};

} // namespace RomanNumeralsFull

#endif // ROMAN_NUMERALS_FULL_HPP
