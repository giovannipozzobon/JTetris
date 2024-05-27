#ifndef GRID_HPP
#define GRID_HPP

#include "costant.hpp"
#include "shape.hpp"
#include "graphic.hpp"
#include "util.hpp"
#include "console.hpp"
#include "score.hpp"


class Grid {

private:
    Graphic graphic;
    Util util;
    Console console;
    Score score;

    unsigned char grid[HEIGHT][WIDTH] = {0};
    unsigned char tmpGrid[HEIGHT][WIDTH] = {0};
    unsigned char map[3+WIDTH*HEIGHT] = {0};


    void DrawGrid(Shape *shape);
    char strText [10];

public:
    Grid();
    void WriteToGrid(Shape *shape);
    void DeleteRows(); // return count of rows to calculate the score
    void ManipulateCurrent(uint8_t key, Shape *shape);
    uint8_t CheckPosition(Form * shape);
    void DrawBoardText(char * str);
    
    //Grid and Map Function
    void EraseMap();
    void EraseTmpGrid();
    void EraseGrid();
    void DeleteShapedFromGrid(Form *form);
    

};

#endif //GRID_HPP