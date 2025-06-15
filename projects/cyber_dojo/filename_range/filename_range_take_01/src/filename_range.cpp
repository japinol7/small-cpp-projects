#include "filename_range.hpp"
#include <algorithm>
#include <cctype>
#include <string>
#include <array>
#include <vector>

namespace {
    // Characters to exclude from the left (directory separators)
    bool is_char_to_exclude_left(const char ch) {
        return ch == '\\' || ch == '/';
    }

    // Words to keep in the filename (test-related words)
    const std::vector<std::string> words_to_keep = {
        "tests", "test", "spec", "step"
    };

    // Separator characters
    bool is_separator(const char ch) {
        return ch == '-' || ch == '_' || ch == '.';
    }

    // Adjusts the right mark if the word to keep is found to the right of the left mark
    int keep_word_on_the_right(
        const std::string& text, const std::string& word_to_keep,
        int right_mark
    ) {
        const size_t found_pos = text.find(word_to_keep);
        if (found_pos != std::string::npos) {
            const int word_idx = static_cast<int>(found_pos);
            if (0 < word_idx && word_idx < right_mark) {
                right_mark = word_idx;
                if (right_mark > 0 && is_separator(text[right_mark - 1])) {
                    right_mark--;
                }
            }
        }
        return right_mark;
    }

    // Adjusts the left mark if the word to keep is found to the left of the right mark
    int keep_word_on_the_left(
        const std::string& text, const std::string& word_to_keep, int left_mark
    ) {
        const size_t found_pos = text.find(word_to_keep);
        if (found_pos != std::string::npos) {
            const int word_idx = static_cast<int>(found_pos);
            if (word_idx >= left_mark) {
                left_mark = word_idx + static_cast<int>(word_to_keep.length());
                if (left_mark < static_cast<int>(text.length()) && is_separator(text[left_mark])) {
                    left_mark++;
                }
            }
        }
        return left_mark;
    }
}

std::optional<std::array<int, 2>> filename_range(const std::string& filename) {
    // Check for empty filename
    if (filename.empty()) {
        return std::nullopt; // Empty result for empty input
    }

    // Create a lowercase copy of the filename for case-insensitive operations
    std::string name = filename;
    std::ranges::transform(
        name, name.begin(), [](const unsigned char c) { return std::tolower(c); }
    );

    // Remove chars from the left to the last char to exclude
    int left_mark = 0;
    for (int i = static_cast<int>(name.length()) - 1; i >= 0; i--) {
        if (is_char_to_exclude_left(name[i])) {
            left_mark = i + 1;
            break;
        }
    }

    // Remove chars from the right of the first dot char
    int right_mark = static_cast<int>(name.length());
    const size_t dot_pos = name.find('.');
    if (dot_pos != std::string::npos) {
        right_mark = static_cast<int>(dot_pos);
    }

    // Remove words to keep on the right and their separators
    const std::string name_tp = name.substr(left_mark);
    int relative_right_mark = right_mark - left_mark;
    for (const auto& word : words_to_keep) {
        relative_right_mark = keep_word_on_the_right(
            name_tp, word, relative_right_mark);
    }
    right_mark = left_mark + relative_right_mark;

    // Remove words to keep on the left and their separators
    const std::string name_tp_left = name.substr(0, right_mark);
    for (const auto& word : words_to_keep) {
        left_mark = keep_word_on_the_left(name_tp_left, word, left_mark);
    }

    // Return the range array
    return std::array<int, 2>{left_mark, right_mark};
}
