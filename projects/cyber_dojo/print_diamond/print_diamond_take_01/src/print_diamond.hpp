#ifndef PRINT_DIAMOND_HPP
#define PRINT_DIAMOND_HPP

#include <string>
#include <vector>

// Class representing a diamond pattern
class Diamond {
public:
    // Create a new diamond pattern for the given letter
    explicit Diamond(char letter);

    // Default constructor creates an empty diamond
    Diamond() = default;

    // Get the string representation of the diamond
    std::string toString() const;

    // Get the letter used to create this diamond
    char getLetter() const { return letter_; }

    // Get the pattern as a vector of strings
    const std::vector<std::string>& getPattern() const { return pattern_; }

private:
    // Constants
    static constexpr char START_LETTER = 'A';

    // Check if the input letter is valid for creating a diamond
    static bool isInputValid(char letter);

    // Centers a string within a given width
    static std::string centerString(const std::string& str, int width);

    // Create the diamond pattern
    void createDiamondPattern();

    // Add lines to the diamond pattern from A to the specified letter
    void addLinesUntilMiddleOfDiamond(int width, int lenToStartLetter);

    char letter_ = 0;
    std::vector<std::string> pattern_;
};

#endif // PRINT_DIAMOND_HPP
