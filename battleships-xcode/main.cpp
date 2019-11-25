#include "ncurses.h"

#include "board.hpp"
#include "text_display.hpp"

#include <iostream>

#include "consts.hpp"

/* Check out Scott Meyers, 'Effective Modern C++' */

int HEIGHT = 8;
int WIDTH = 5;
int SHIP_SIZES[] = { 2, 3, 5 };
int N_SHIPS = sizeof(SHIP_SIZES) / sizeof(*SHIP_SIZES);

int main() {
    TextDisplay display(HEIGHT, WIDTH);
    Board board(HEIGHT, WIDTH);
    board.place_ships(SHIP_SIZES, N_SHIPS);

    display.draw(board);

    // Main game loop
    while (true) {
        // Get user input
        int *xy = display.get_shot();
        
        // Update state
        board.record_shot(xy);

        // Display
        display.draw(board);
    }
    return 0;
}
