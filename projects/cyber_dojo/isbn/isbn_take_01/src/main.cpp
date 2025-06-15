#include "isbn.hpp"
#include <iostream>
#include <string>

int main() {
    const std::string app_name = "Validate ISBN-13 and ISBN-10";
    std::cout << "Start app " << app_name << std::endl;

    // Check valid isbn-13
    const std::string isbn1 = "978-0-262-13472-9";
    const auto result1 = ISBN::validate(isbn1);
    std::cout << "Should be true.  Is '" << isbn1 << "' a valid isbn?: " 
              << result1.value_or("error") << std::endl;

    // Check invalid isbn-13
    const std::string isbn2 = "978-0-262-13472-1";
    const auto result2 = ISBN::validate(isbn2);
    std::cout << "Should be false. Is '" << isbn2 << "' a valid isbn?: " 
              << result2.value_or("error") << std::endl;

    // Check valid isbn-10
    const std::string isbn3 = "0-8044-2957-X";
    const auto result3 = ISBN::validate(isbn3);
    std::cout << "Should be true.  Is '" << isbn3 << "' a valid isbn?: " 
              << result3.value_or("error") << std::endl;

    // Check invalid isbn-10
    const std::string isbn4 = "0-4A0-84525-2";
    const auto result4 = ISBN::validate(isbn4);
    std::cout << "Should be false. Is '" << isbn4 << "' a valid isbn?: " 
              << result4.value_or("error") << std::endl;

    std::cout << "End app " << app_name << std::endl;

    return 0;
}
