#ifndef ROMAN_NUMERALS_HPP
#define ROMAN_NUMERALS_HPP

#include <string>

namespace RomanNumerals {

// Class for Roman numeral conversions
class Converter {
public:
    // Converts an integer to a Roman numeral string
    // @param num The integer to convert (must be between 1 and 3999 inclusive)
    // @return Roman numeral string on success, empty string on error
    static std::string toRoman(int num);
};

} // namespace RomanNumerals

#endif // ROMAN_NUMERALS_HPP
