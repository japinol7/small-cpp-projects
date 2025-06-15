#ifndef REVERSE_ROMAN_HPP
#define REVERSE_ROMAN_HPP
#include <string>

namespace ReverseRoman {

// Class for Roman numeral conversions
class Converter {
public:
    // Converts a Roman numeral string to an integer
    // @param roman The Roman numeral string to convert
    // @param result Reference to store the resulting integer value
    // @return true on success, false on error
    static bool fromRoman(const std::string& roman, int& result);
};

} // namespace ReverseRoman

#endif // REVERSE_ROMAN_HPP
