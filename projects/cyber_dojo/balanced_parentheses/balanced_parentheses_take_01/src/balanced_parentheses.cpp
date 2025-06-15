#include "balanced_parentheses.hpp"
#include <stack>
#include <unordered_map>

// Define opening and closing marks maps
namespace {
    const std::unordered_map<char, char> parenthesesMap = {
        {'(', ')'},
        {'{', '}'},
        {'[', ']'}
    };
}

// Checks if the input string has balanced parentheses, brackets, and braces.
bool areParenthesesBalanced(const std::string& str) {
    // Stack to keep track of opening marks
    std::stack<char> charStack;

    for (char ch : str) {
        // Check if it's an opening mark
        auto it = parenthesesMap.find(ch);
        if (it != parenthesesMap.end()) {
            // Push the corresponding closing mark to the stack
            charStack.push(it->second);
        } else {
            // Check if it's a closing mark
            bool isClosingMark = false;
            for (const auto& pair : parenthesesMap) {
                if (ch == pair.second) {
                    isClosingMark = true;
                    // If stack is empty or top doesn't match, not balanced
                    if (charStack.empty() || ch != charStack.top()) {
                        return false;
                    }
                    // Pop from stack
                    charStack.pop();
                    break;
                }
            }
        }
    }

    // Stack should be empty for balanced parentheses
    return charStack.empty();
}
