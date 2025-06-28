#ifndef MINE_FIELD_HPP
#define MINE_FIELD_HPP

#include <string>
#include <vector>

// MineField class representing a field with mines
class MineField {
private:
    int nRows{};
    int nColumns{};
    std::vector<std::vector<char>> board;

    // Count the number of mine neighbors for a given cell
    [[nodiscard]] int countNeighbours(int nRow, int nColumn) const;

    // Cell types
    static constexpr char EMPTY = '.';
    static constexpr char MINE = '*';

public:
    // Create a new minefield from a board string
    // Format: "nRows nColumns\n<board rows>"
    // Throws std::invalid_argument if the input is invalid
    explicit MineField(const std::string& board);

    // Calculate the hint field based on the minefield
    [[nodiscard]] std::string resolve() const;
};

#endif // MINE_FIELD_HPP
