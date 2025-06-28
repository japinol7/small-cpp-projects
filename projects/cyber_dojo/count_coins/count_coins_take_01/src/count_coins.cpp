#include "count_coins.hpp"
#include <vector>

// Constructor with default coin denominations
CountCoins::CountCoins() : coin_values{
    25, // quarters
    10, // dimes
    5, // nickels
    1, // pennies
} {
}

// Constructor with custom coin denominations
CountCoins::CountCoins(const std::vector<int>& coin_values)
    : coin_values(coin_values) {
}

// Calculate the number of ways to make change for a given amount
int CountCoins::changes(const int amount) const {
    // Handle invalid input
    if (amount < 1) {
        return 0;
    }

    // Allocate array to store number of ways for each amount
    std::vector<int> ways(amount + 1, 0);

    // Base case: there's 1 way to make change for 0 cents: using no coins
    ways[0] = 1;

    // For each coin type
    for (const int coin : coin_values) {
        // For each amount from coin value to target amount
        for (int j = coin; j <= amount; j++) {
            ways[j] += ways[j - coin];
        }
    }

    return ways[amount];
}
