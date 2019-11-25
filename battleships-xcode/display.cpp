#include "display.hpp"
#include "board.hpp"

#include <vector>

Display::Display(int _height, int _width) {
    height = _height;
    width = _width;
}

Display::~Display() {}

void Display::draw(Board board) {}
void Display::game_over(Board board, int display_seconds) {}
int *Display::get_shot() {
    static int xy[2] = {0, 0};
    return xy;
}
