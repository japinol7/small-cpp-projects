#include "game_of_life.hpp"
#include <sstream>

// Constructor with empty grid
GameOfLife::GameOfLife(int rows, int cols) :
    rows_n(rows),
    cols_n(cols),
    grid(rows, std::vector<bool>(cols, false)),
    initialPattern(rows, std::string(cols, DEFAULT_CELL_EMPTY)),
    isInitialGeneration(true),
    cellAlive(1, DEFAULT_CELL_ALIVE),
    cellEmpty(1, DEFAULT_CELL_EMPTY),
    separator(DEFAULT_SEPARATOR) {
}

// Constructor from string grid representation
GameOfLife::GameOfLife(int height, int width, const std::vector<std::string>& gridStr) :
    rows_n(height),
    cols_n(width),
    grid(height, std::vector<bool>(width, false)),
    initialPattern(height),
    isInitialGeneration(true),
    cellAlive(1, DEFAULT_CELL_ALIVE),
    cellEmpty(1, DEFAULT_CELL_EMPTY),
    separator(DEFAULT_SEPARATOR) {
    // Copy the initial pattern and set grid based on pattern
    for (int i = 0; i < height; ++i) {
        // Copy pattern with proper size
        initialPattern[i] = gridStr[i].substr(0, width);

        // Set grid based on pattern
        for (int j = 0; j < width && j < gridStr[i].length(); ++j) {
            if (gridStr[i][j] == DEFAULT_CELL_ALIVE) {
                grid[i][j] = true;
            }
        }
    }
}


// Set custom cell representation
bool GameOfLife::setCellRepresentation(
    const std::string& alive, const std::string& empty,
    const std::string& separator
) {
    // Check if we're in the initial generation
    if (!isInitialGeneration) {
        // Error: cell representation can only be set in the initial generation
        return false;
    }

    // Check that cell representations are single characters
    if (alive.length() > 1 || empty.length() > 1) {
        return false;
    }

    // Set new representations
    cellAlive = alive;
    cellEmpty = empty;
    this->separator = separator;

    // Recreate grid using custom cell representation
    for (int i = 0; i < rows_n; ++i) {
        for (int j = 0; j < cols_n; ++j) {
            if (initialPattern[i][j] == alive[0]) {
                grid[i][j] = true;
            } else {
                grid[i][j] = false;
            }
        }
    }

    return true; // Success
}

// Set the state of a cell
void GameOfLife::setCell(const int x, const int y, const bool state) {
    if (x >= 0 && x < cols_n && y >= 0 && y < rows_n) {
        grid[y][x] = state;
    }
}

// Get the state of a cell
bool GameOfLife::getCell(const int x, const int y) const {
    if (x >= 0 && x < cols_n && y >= 0 && y < rows_n) {
        return grid[y][x];
    }
    // Out of bounds cells are considered dead
    return false;
}

// Count the number of live neighbors for a cell
int GameOfLife::countNeighbors(const int x, const int y) const {
    int count = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // Skip the cell itself

            const int nx = x + j;
            const int ny = y + i;

            if (nx >= 0 && nx < cols_n && ny >= 0 && ny < rows_n) {
                count += grid[ny][nx] ? 1 : 0;
            }
        }
    }

    return count;
}

// Calculate the next generation
void GameOfLife::calcNextGeneration() {
    std::vector<std::vector<bool>> newGrid(
        rows_n, std::vector<bool>(cols_n, false));

    // Apply Game of Life rules
    for (int y = 0; y < rows_n; ++y) {
        for (int x = 0; x < cols_n; ++x) {
            const int neighbors = countNeighbors(x, y);

            if (grid[y][x]) {
                // Cell is alive
                if (neighbors < 2 || neighbors > 3) {
                    // Cell dies by isolation or by overpopulation
                    newGrid[y][x] = false;
                } else {
                    // Cell survives
                    newGrid[y][x] = true;
                }
            }
            else {
                // Cell is dead
                if (neighbors == 3) {
                    // Cell becomes alive
                    newGrid[y][x] = true;
                } else {
                    // Cell stays dead
                    newGrid[y][x] = false;
                }
            }
        }
    }

    // Replace the old grid with the new one
    grid = std::move(newGrid);

    // Mark that we're no longer in the initial generation
    isInitialGeneration = false;
}

// Generate a string representation of the current grid state
std::string GameOfLife::toString() const {
    std::ostringstream result;

    for (int y = 0; y < rows_n; ++y) {
        for (int x = 0; x < cols_n; ++x) {
            result << (grid[y][x] ? cellAlive : cellEmpty) << separator;
        }
        result << '\n';
    }

    return result.str();
}
