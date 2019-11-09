#include "board.hpp"

#include "display.hpp"

#include <iostream>

Board::Board(int _height, int _width, Display * _display) {
    height = _height;
    width = _width;
    display = _display;
    CELL_STATES states[height * width];
    this->set_ship_positions(this->states);
}

void Board::set_ship_positions(CELL_STATES states[]) {
    for (int i = 0; i < height * width; i++) {
        this->states[i] = EMPTY;
    }
};

void Board::draw() {
    std::cout << "display height: " << this->display->height << std::endl;
    this->display->draw(states);
}
