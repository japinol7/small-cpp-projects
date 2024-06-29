#include <iostream>

using std::cout;
using std::endl;

const int NUM_BASE = 3;
const int NUM_EXPONENT = 2;

int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    cout << "power " << NUM_BASE << " to " << NUM_EXPONENT
        << " = " << power(NUM_BASE, NUM_EXPONENT) << endl;
    return EXIT_SUCCESS;
}
