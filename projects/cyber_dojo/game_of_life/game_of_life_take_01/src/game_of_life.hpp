#ifndef GAME_OF_LIFE_HPP
#define GAME_OF_LIFE_HPP

#include <string>
#include <vector>

class GameOfLife {
public:
    static constexpr char DEFAULT_CELL_ALIVE = '*';
    static constexpr char DEFAULT_CELL_EMPTY = '.';
    static constexpr const char* DEFAULT_SEPARATOR = "";

    // Constructors
    GameOfLife(int rows, int cols);
    GameOfLife(int height, int width, const std::vector<std::string>& gridStr);

    // Destructor not needed (RAII handles cleanup)

    // Cell representation methods
    bool setCellRepresentation(
        const std::string& alive, const std::string& empty, const std::string& separator);

    // Cell state methods
    void setCell(int x, int y, bool state);
    [[nodiscard]] bool getCell(int x, int y) const;
    [[nodiscard]] int countNeighbors(int x, int y) const;

    // Game progression
    void calcNextGeneration();

    // Output
    [[nodiscard]] std::string toString() const;

private:
    int rows_n;
    int cols_n;
    std::vector<std::vector<bool>> grid;
    std::vector<std::string> initialPattern;
    bool isInitialGeneration;
    std::string cellAlive;
    std::string cellEmpty;
    std::string separator;
};

#endif // GAME_OF_LIFE_HPP
