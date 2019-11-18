#ifndef DISPLAY_H
#define DISPLAY_H

#include "consts.hpp"

#include <vector>

/*
 * The board will have numbers on one border and letters on another to indicate the co-ordinates of squares.
 * Within this it will have a grid of cells, each of which has one of 4 states
 */

class Display {
public:
    Display(int _height, int _width);
    ~Display();
    virtual void draw(std::vector<CELL_STATES> states);
    int height;
    int width;
};

#endif
