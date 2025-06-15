#include "print_diamond.hpp"
#include <iostream>
#include <vector>
#include <string>

int main() {
    const std::string appName = "Print Diamond";
    std::cout << "Start app " << appName << std::endl;

    // Examples of diamond patterns
    const std::vector<char> letters = {'A', 'B', 'C', 'D', 'E'};

    for (const char letter : letters) {
        std::cout << "\nDiamond for letter "
                  << letter << ":" << std::endl;

        // Create diamond object
        Diamond diamond(letter);

        // Print the diamond pattern
        std::cout << diamond.toString() << std::endl;
    }

    std::cout << "\nEnd app " << appName << std::endl;
    return 0;
}
