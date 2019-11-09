#ifndef BOARD_H
#define BOARD_H

#include "consts.hpp"
#include "display.hpp"

class Board {
public:
    Board(int _height, int _width, Display * _display);
    int height;
    int width;
    Display * display;
    void record_shot(char * coords);
    void draw();
    CELL_STATES states[];
    
private:
    void set_ship_positions(CELL_STATES states[]);
};

#endif
