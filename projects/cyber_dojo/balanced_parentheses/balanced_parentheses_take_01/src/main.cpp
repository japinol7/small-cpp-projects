#include <iostream>
#include <string>
#include "balanced_parentheses.hpp"

int main() {
    std::cout << "Start app Balanced Parentheses" << std::endl;

    std::string inputStr = "((()))";
    bool res = areParenthesesBalanced(inputStr);
    std::cout << "Are parentheses balanced for : '" << inputStr << "' ? "
              << (res ? "true" : "false") << std::endl;

    inputStr = "(()))";
    res = areParenthesesBalanced(inputStr);
    std::cout << "Are parentheses balanced for : '" << inputStr << "' ? "
              << (res ? "true" : "false") << std::endl;

    std::cout << "End app Balanced Parentheses" << std::endl;

    return 0;
}
