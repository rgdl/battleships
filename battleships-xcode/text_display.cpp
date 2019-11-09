#include "text_display.hpp"

#include <cmath>
#include <iostream>
#include <string>

#include "ncurses.h"

#include "consts.hpp"
#include "display.hpp"

#define WATER_PAIR 1
#define HIT_PAIR 2
#define MISS_PAIR 3
#define BOARD_PAIR 4

#define WATER '~'
#define SHOT 'X'
#define HORIZONTAL_LINE '-'
#define VERTICAL_LINE '|'

TextDisplay::TextDisplay(int _height, int _width) : Display(_height, _width) {
    height = _height;
    width = _width;
    std::cout << "constructor: height: " << this->height << " width: " << this->width << std::endl;
    initscr();
    start_color();
    init_pair(WATER_PAIR, COLOR_CYAN, COLOR_BLUE);
    init_pair(HIT_PAIR, COLOR_RED, COLOR_WHITE);
    init_pair(MISS_PAIR, COLOR_RED, COLOR_BLUE);
    init_pair(BOARD_PAIR, COLOR_WHITE, COLOR_BLACK);
}

TextDisplay::~TextDisplay() {
    endwin();
}

void TextDisplay::draw(CELL_STATES states[]) {
    // Each "row" or "column" in the data will actually be multiple "rows" or "columns" in the output text, due to padding etc.
    // These values will probably come from the board object
    
    // TODO: why are height and width always 1 here?
    std::cout << "inside draw: " << "height: " << this->height << " width: " << this->width << " address: " << &*this << std::endl;
    
    int left_margin = 2;
    int top_margin = 2;
    
    // Draw top margin
    attron(COLOR_PAIR(BOARD_PAIR));
    mvhline(0, 1, VERTICAL_LINE, 1);
    char coord = 'A';
    for (int x = 0; x < this->width; x++) {
        mvhline(0, x + left_margin, coord++, 1);
    }
    for (int x = 0; x < this->width + left_margin; x++) {
        mvhline(1, x, HORIZONTAL_LINE, 1);
    }
    
    // Draw left margin
    for (int y = 0; y < this->height; y++) {
        mvhline(y + top_margin, 0, std::to_string(y + 1).c_str()[0], 1);
        mvhline(y + top_margin, 1, VERTICAL_LINE, 1);
    }
    attroff(COLOR_PAIR(BOARD_PAIR));
    
    int state_counter = 0;
    for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
            switch (states[state_counter++]) {
                case HIT:
                    attron(COLOR_PAIR(HIT_PAIR));
                    mvhline(y + top_margin, x + left_margin, SHOT, 1);
                    attroff(COLOR_PAIR(HIT_PAIR));
                    break;
                case MISS:
                    attron(COLOR_PAIR(MISS_PAIR));
                    mvhline(y + top_margin, x + left_margin, SHOT, 1);
                    attroff(COLOR_PAIR(MISS_PAIR));
                    break;
                default:
                    attron(COLOR_PAIR(WATER_PAIR));
                    mvhline(y + top_margin, x + left_margin, WATER, 1);
                    attroff(COLOR_PAIR(WATER_PAIR));
            }
        }
    }
    refresh();
}
