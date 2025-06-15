#ifndef FIZZBUZZ_PLUS_H
#define FIZZBUZZ_PLUS_H

#include <string>
#include <vector>

// Converts a number to its FizzBuzz string representation
// Returns the resulting string
std::string fizzbuzz(int n);

// Generates FizzBuzz strings for numbers from 1 to n
// Returns a vector of FizzBuzz strings
std::vector<std::string> fizzbuzz_range(int n);

#endif // FIZZBUZZ_PLUS_H
