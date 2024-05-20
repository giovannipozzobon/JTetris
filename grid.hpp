#ifndef GRID_HPP
#define GRID_HPP

#include "costant.hpp"
#include "shape.hpp"
#include "graphic.hpp"
#include "util.hpp"
#include "console.hpp"


class Grid {

private:
    Graphic graphic;
    Util util;
    Console console;

    char grid[COLS*ROWS+3] = {0};
    void DrawGrid();
    char strText [10];

public:
    Grid();
    void WriteToGrid(Form form);
    uint8_t DeleteRows(); // return count of rows to calculate the score
    void ManipulateCurrent(uint8_t key, Shape shape);
    int CheckPosition(Form shape);
    void DrawBoardText(char * str);
};

#endif //GRID_HPP