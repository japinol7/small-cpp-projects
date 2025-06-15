#include "print_diamond.hpp"
#include <cctype>
#include <sstream>

// Diamond constructor
Diamond::Diamond(const char letter) : letter_(std::toupper(letter)) {
    if (!isInputValid(letter_)) {
        letter_ = 0;
        return;
    }

    createDiamondPattern();
}

// Check if the input letter is valid for creating a diamond
bool Diamond::isInputValid(const char letter) {
    return letter != 0 && letter >= 'A' && letter <= 'Z';
}

// Centers a string within a given width
std::string Diamond::centerString(const std::string& str, const int width) {
    if (static_cast<int>(str.length()) >= width) {
        return str;
    }

    const int leftPadding = (width - str.length()) / 2;
    const int rightPadding = width - str.length() - leftPadding;

    return std::string(leftPadding, ' ') + str + std::string(rightPadding, ' ');
}

// Add lines to the diamond pattern from A to the specified letter
void Diamond::addLinesUntilMiddleOfDiamond(const int width, const int lenToStartLetter) {
    // Add the first line with just 'A'
    pattern_.push_back(centerString(std::string(1, START_LETTER), width));

    // Add lines from 'B' to the specified letter
    for (int i = 1; i <= lenToStartLetter; ++i) {
        const char ch = START_LETTER + i;
        const int spaces = 2 * i - 1;

        // Create line: char + spaces + char
        std::string line = std::string(1, ch) + std::string(spaces, ' ') + std::string(1, ch);

        // Center the line
        pattern_.push_back(centerString(line, width));
    }
}

// Create the diamond pattern
void Diamond::createDiamondPattern() {
    // Special case for 'A'
    if (letter_ == START_LETTER) {
        pattern_.emplace_back("A");
        return;
    }

    const int lenToStartLetter = letter_ - START_LETTER;
    const int width = 2 * lenToStartLetter + 1;

    // Clear pattern in case it has existing data
    pattern_.clear();

    // Add lines until the middle of the diamond
    addLinesUntilMiddleOfDiamond(width, lenToStartLetter);

    // Add mirrored lines to complete the diamond (excluding the middle line)
    for (int i = lenToStartLetter - 1; i >= 0; --i) {
        pattern_.push_back(pattern_[i]);
    }
}

// Convert diamond to string representation
std::string Diamond::toString() const {
    if (pattern_.empty()) {
        return "";
    }

    std::ostringstream result;

    // Build the string
    for (size_t i = 0; i < pattern_.size(); ++i) {
        result << pattern_[i];
        if (i < pattern_.size() - 1) {
            result << '\n';
        }
    }

    return result.str();
}
