#include "display.hpp"

#include <vector>

Display::Display(int _height, int _width) {
    height = _height;
    width = _width;
}

Display::~Display() {}

void Display::draw(std::vector<CELL_STATES> states) {}
