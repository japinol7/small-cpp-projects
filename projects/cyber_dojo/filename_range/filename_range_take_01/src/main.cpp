#include "filename_range.hpp"
#include <iostream>
#include <string>

int main() {
    const std::string app_name = "Filename Range";
    std::cout << "Start app " << app_name << std::endl;

    const std::string filename = "wibble/test/hiker_spec.rb";
    const auto range_result = filename_range(filename);

    if (range_result) {
        // Extract the relevant part of the filename
        const auto& range = *range_result;
        const size_t len = range[1] - range[0];
        std::string wanted_name = filename.substr(range[0], len);

        std::cout << filename << " -> [" << range[0] << ", " << range[1]
            << "] -> " << wanted_name << std::endl;
    }
    else {
        std::cout << filename << " -> Invalid range" << std::endl;
    }

    std::cout << "End app " << app_name << std::endl;
    return 0;
}
