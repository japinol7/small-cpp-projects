#ifndef COUNT_COINS_HPP
#define COUNT_COINS_HPP

#include <vector>

// CountCoins class representing a coin counter
class CountCoins {
public:
    // Constructor with default coin denominations
    CountCoins();

    // Constructor with custom coin denominations
    explicit CountCoins(const std::vector<int>& coin_values);

    // Calculate the number of ways to make change for a given amount
    [[nodiscard]] int changes(int amount) const;

private:
    // Coin values in cents
    std::vector<int> coin_values;
};

#endif // COUNT_COINS_HPP
