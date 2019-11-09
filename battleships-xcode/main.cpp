#include "ncurses.h"

#include "board.hpp"
#include "text_display.hpp"

#include <iostream>

#include "consts.hpp"

int HEIGHT = 8;
int WIDTH = 5;

int main() {
    TextDisplay display(HEIGHT, WIDTH);
    Board board(HEIGHT, WIDTH, &display);
    display.draw(board.states);
    while (true) {}
    return 0;
}
