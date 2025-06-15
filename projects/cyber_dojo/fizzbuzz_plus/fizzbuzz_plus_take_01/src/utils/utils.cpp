#include "utils.hpp"

std::string string_join(const std::vector<std::string>& items) {
    // Return empty string for empty input
    if (items.empty()) {
        return "";
    }

    std::string result = items[0];

    // Add each item with a newline separator
    for (size_t i = 1; i < items.size(); ++i) {
        result += "\n" + items[i];
    }

    return result;
}
