#ifndef GRID_HPP
#define GRID_HPP

#include "costant.hpp"
#include "shape.hpp"

class Grid {

private:
    char grid[COLS][ROWS] = {0};
    void PrintGrid();

public:
    void WriteToGrid(Form form);
    uint8_t DeleteRows(); // return count of rows to calculate the score
    void ManipulateCurrent(uint8_t key, Shape shape, uint8_t currentForm);
    int CheckPosition(Form shape);
};

#endif //GRID_HPP