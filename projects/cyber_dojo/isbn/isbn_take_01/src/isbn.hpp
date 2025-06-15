#ifndef ISBN_HPP
#define ISBN_HPP

#include <string>
#include <optional>
#include <vector>

class ISBN {
public:
    // Validates if a given string is a valid ISBN-13 or ISBN-10 code
    // Returns "true" or "false" as a string
    static std::optional<std::string> validate(const std::string& isbn);

private:
    // We represent the char X as -1
    static constexpr int X_CHAR_INT_VALUE = -1;

    // Validates if a given string is a valid ISBN-13 code
    static bool validateISBN13(const std::vector<int>& isbnDigits);

    // Validates if a given string is a valid ISBN-10 code
    static bool validateISBN10(const std::vector<int>& isbnDigits);
};

#endif // ISBN_HPP
