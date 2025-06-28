#include "mine_field.hpp"
#include <sstream>

MineField::MineField(const std::string& board) {
    if (board.empty()) {
        throw std::invalid_argument("Empty board string");
    }

    std::istringstream iss(board);

    // Parse dimensions from the first line
    iss >> nRows >> nColumns;
    if (iss.fail() || nRows <= 0 || nColumns <= 0) {
        throw std::invalid_argument("Invalid dimensions");
    }

    // Skip the newline after dimensions
    if (iss.get() != '\n') {
        throw std::invalid_argument("Missing newline after dimensions");
    }

    // Initialize the board
    try {
        if (static_cast<size_t>(nRows) * static_cast<size_t>(nColumns)
                > this->board.max_size()) {
            throw std::invalid_argument("Board dimensions too large");
        }
        this->board.resize(nRows, std::vector<char>(nColumns));
    } catch (const std::bad_alloc&) {
        throw std::runtime_error("Failed to allocate memory for the board");
    }

    // Parse the board rows
    for (int i = 0; i < nRows; ++i) {
        std::string line;
        if (!std::getline(iss, line) || line.length() < nColumns) {
            throw std::invalid_argument("Invalid board row");
        }

        // Copy characters from the line to the board
        for (int j = 0; j < nColumns; ++j) {
            const char c = (j < line.length()) ? line[j] : EMPTY;
            if (c != EMPTY && c != MINE && c != ' ') { // Ignore spaces
                throw std::invalid_argument("Invalid character in board");
            }
            this->board[i][j] = (c == ' ') ? EMPTY : c;
        }
    }
}

int MineField::countNeighbours(const int nRow, const int nColumn) const {
    int count = 0;

    // Define bounds for the grid around the current cell
    const int rowStart = std::max(nRow - 1, 0);
    const int rowEnd = std::min(nRow + 2, nRows);
    const int colStart = std::max(nColumn - 1, 0);
    const int colEnd = std::min(nColumn + 2, nColumns);

    // Count mines in all adjacent cells
    for (int currentRow = rowStart; currentRow < rowEnd; ++currentRow) {
        for (int currentCol = colStart; currentCol < colEnd; ++currentCol) {
            const bool isCurrentCell = (currentCol == nColumn && currentRow == nRow);
            if (!isCurrentCell && board[currentRow][currentCol] == MINE) {
                count++;
            }
        }
    }

    return count;
}

std::string MineField::resolve() const {
    std::vector<std::string> result(nRows);

    // Calculate the hint field
    for (int nRow = 0; nRow < nRows; ++nRow) {
        result[nRow].resize(nColumns);
        for (int nColumn = 0; nColumn < nColumns; ++nColumn) {
            if (board[nRow][nColumn] == MINE) {
                result[nRow][nColumn] = MINE;
            } else {
                const int neighbors = countNeighbours(nRow, nColumn);
                if (neighbors > 8) {
                    throw std::runtime_error("Invalid number of neighbors detected");
                }
                result[nRow][nColumn] = static_cast<char>('0' + neighbors);
            }
        }
    }

    // Join the result into a string
    std::ostringstream res_string_stream;
    for (int i = 0; i < nRows; ++i) {
        res_string_stream << result[i];
        if (i < nRows - 1) {
            res_string_stream << "\n";
        }
    }

    return res_string_stream.str();
}