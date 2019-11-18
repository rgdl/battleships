#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "consts.hpp"
#include "display.hpp"

class Board {
public:
    Board(int _height, int _width);
    int height;
    int width;
    void record_shot(char * coords);
    void place_ships(int * ship_sizes, int n_ships);
    std::vector<CELL_STATES> states;
    int xy_to_index(int x, int y);
    int *index_to_xy(int index);
private:
    bool is_ship_overlapping(int x, int y, bool is_vertical, int ship_size);
    void add_ship_to_board(int x, int y, bool is_vertical, int ship_size);
};

#endif
