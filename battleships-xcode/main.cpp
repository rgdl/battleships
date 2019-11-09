#include "ncurses.h"

#include "board.hpp"
#include "text_display.hpp"

#include <iostream>

#include "consts.hpp"

int main() {
    TextDisplay display(8, 5);
    Board board(8, 5, &display);
    std::cout << "display in main: " << "height: " << display.height << " width: " << display.width << " address: " << &display << std::endl;
    std::cout << "board display in main: " << "height: " << board.display->height << " width: " << board.display->width << " address: " << &*board.display << std::endl;
    display.draw(board.states);
    while (true) {}
}
