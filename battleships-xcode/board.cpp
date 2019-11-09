#include "board.hpp"

#include "display.hpp"

#include <iostream>

Board::Board(int _height, int _width, Display * _display) {
    height = _height;
    width = _width;
    display = _display;
    CELL_STATES states[height * width];
    for (int i = 0; i < height * width; i++) {
        states[i] = EMPTY;
    }
}

void Board::draw() {
    std::cout << "display height: " << this->display->height << std::endl;
    this->display->draw(states);
}
