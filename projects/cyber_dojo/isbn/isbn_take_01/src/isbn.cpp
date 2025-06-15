#include "isbn.hpp"
#include <cctype>
#include <vector>

bool ISBN::validateISBN13(const std::vector<int>& isbnDigits) {
    // Get all digits except check digit
    const auto& digits = isbnDigits;
    const int checkDigit = digits.back();

    // Multiply each digit alternately by 1 or 3 and sum the results
    int sum = 0;
    for (int i = 0; i < 12; ++i) {
        sum += digits[i] * ((i + 1) % 2 == 0 ? 3 : 1);
    }

    const int calculatedCheckDigit = (10 - (sum % 10)) % 10;
    return calculatedCheckDigit == checkDigit;
}

bool ISBN::validateISBN10(const std::vector<int>& isbnDigits) {
    // Get all digits except check digit
    const auto& digits = isbnDigits;
    int checkDigit = digits.back();

    // Convert X to 10 for check digit
    if (checkDigit == X_CHAR_INT_VALUE) {
        checkDigit = 10;
    }

    // Multiply each digit by its position number and sum the results
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        sum += digits[i] * (i + 1);
    }

    return (sum % 11) == checkDigit;
}

std::optional<std::string> ISBN::validate(const std::string& isbn) {
    // Handle edge cases
    if (isbn.empty()) {
        return "false";
    }

    // Check if all chars except the last one are numeric, '-', or space
    if (isbn.length() > 1) {
        for (size_t i = 0; i < isbn.length() - 1; ++i) {
            char ch = isbn[i];
            if (!std::isdigit(static_cast<unsigned char>(ch))
                    && ch != '-' && ch != ' ') {
                return "false";
            }
        }
    }

    // Extract digits for validation
    // If the char is an X, extract it according to X_CHAR_INT_VALUE
    std::vector<int> isbnDigits;
    isbnDigits.reserve(13); // Max 13 digits for ISBN-13

    for (const char ch : isbn) {
        if (std::isdigit(static_cast<unsigned char>(ch))) {
            isbnDigits.push_back(ch - '0');
        } else if (ch == 'X' || ch == 'x') {
            isbnDigits.push_back(X_CHAR_INT_VALUE);
        }

        // Stop if we've collected more than 13 digits
        if (isbnDigits.size() > 13) {
            return "false";
        }
    }

    // Validate based on the number of digits
    if (isbnDigits.size() == 13) {
        return validateISBN13(isbnDigits) ? "true" : "false";
    }
    if (isbnDigits.size() == 10) {
        return validateISBN10(isbnDigits) ? "true" : "false";
    }

    return "false";
}
