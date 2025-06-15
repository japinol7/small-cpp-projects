#include "leap_year.hpp"

// Determines if a given year is a leap year
bool isLeapYear(const int year) {
    // Invalid years are not leap years
    if (year < 1) {
        return false;
    }

    // Years divisible by 400 are leap years
    if (year % 400 == 0) {
        return true;
    }

    // Years divisible by 4 are leap years unless they're divisible by 100
    if (year % 4 == 0) {
        return year % 100 != 0;
    }

    return false;
}
