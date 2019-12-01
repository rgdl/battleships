#ifndef DISPLAY_H
#define DISPLAY_H

#include "board.hpp"

#include <vector>

/*
 * The board will have numbers on one border and letters on another to indicate the co-ordinates of squares.
 * Within this it will have a grid of cells, each of which has one of 4 states
 */

class Display {
public:
    Display(int _height, int _width);
    ~Display();
    virtual void draw(Board board);
    virtual void game_over(Board board, int display_seconds);
    virtual int *get_shot();
    int height;
    int width;
};

void pause(int seconds);

#endif
