#include "ncurses.h"

#include "board.hpp"
#include "text_display.hpp"

#include <iostream>

#include "consts.hpp"

/* Check out Scott Meyers, 'Effective Modern C++' */

int HEIGHT = 6;
int WIDTH = 8;
int SHIP_SIZES[] = { 2, 3, 5 };
int N_SHIPS = sizeof(SHIP_SIZES) / sizeof(*SHIP_SIZES);
int GAME_OVER_DISPLAY_SECONDS = 5;

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

        if (board.game_is_over()) {
            break;
        }
    }
    display.game_over(board, GAME_OVER_DISPLAY_SECONDS);

    return 0;
}
