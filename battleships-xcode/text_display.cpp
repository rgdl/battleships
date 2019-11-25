#include "text_display.hpp"

#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "ncurses.h"

#include "consts.hpp"
#include "display.hpp"

#define WATER_PAIR 1
#define HIT_PAIR 2
#define MISS_PAIR 3
#define BOARD_PAIR 4
#define RED_TEXT_PAIR 5

#define WATER '~'
#define SHOT 'X'
#define HORIZONTAL_LINE '-'
#define VERTICAL_LINE '|'

#define MAX_INPUT_CHARS 5
#define CELL_SIZE 1

TextDisplay::TextDisplay(int _height, int _width) : Display(_height, _width) {
    height = _height;
    width = _width;
    initscr();
    start_color();
    init_pair(WATER_PAIR, COLOR_CYAN, COLOR_BLUE);
    init_pair(HIT_PAIR, COLOR_RED, COLOR_WHITE);
    init_pair(MISS_PAIR, COLOR_RED, COLOR_BLUE);
    init_pair(BOARD_PAIR, COLOR_WHITE, COLOR_BLACK);
    init_pair(RED_TEXT_PAIR, COLOR_RED, COLOR_BLACK);
}

TextDisplay::~TextDisplay() {
    endwin();
}

void TextDisplay::draw(Board board) {
    // Each "row" or "column" in the data will actually be multiple "rows" or "columns" in the output text, due to padding etc.
    // These values will probably come from the board object
    
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
    
    // Draw shots counter
    attron(COLOR_PAIR(RED_TEXT_PAIR));
    mvprintw(2, 3 + CELL_SIZE * this->width, "%d shots taken", board.shots_taken_count);
    attroff(COLOR_PAIR(RED_TEXT_PAIR));
    
    int state_counter = 0;
    for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
            switch (board.states[state_counter++]) {
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
}

int *TextDisplay::get_shot() {
    char input[MAX_INPUT_CHARS];
    static int xy[2];
    int prompt_position = 3 + CELL_SIZE * this->height;

    // Prompt user for input
    mvprintw(prompt_position, 0, "Enter coordinates:\n");
    while (true) {
        getstr(input);
        
        // Convert letter to x coordinate
        for (int i = 0; i < this->width; i++) {
            if (input[0] == 'a' + i || input[0] == 'A' + i) {
                xy[0] = i;
                break;
            }
        }
        
        // Get rid of letter and convert remainder into y coordinate
        for (int i = 1; i < MAX_INPUT_CHARS; i++) {
            input[i - 1] = input[i];
            if (input[i] == '\0') {
                break;
            }
        }
        // Index from 0, not 1
        xy[1] = atoi(input) - 1;
        
        if (xy[0] >= 0 && xy[1] >= 0) {
            break;
        }
        
        mvprintw(prompt_position, 0, "%s", "Try again. Coordinates must have format like 'a1'\n");
    }
    move(prompt_position + 1, 0);
    clrtoeol();
    refresh();
    return xy;
}

void TextDisplay::game_over(Board board, int display_seconds) {
    clear();
    attron(COLOR_PAIR(RED_TEXT_PAIR));
    mvprintw(0, 0, "GAME OVER!", board.shots_taken_count);
    attroff(COLOR_PAIR(RED_TEXT_PAIR));
    attron(COLOR_PAIR(BOARD_PAIR));
    mvprintw(2, 0, "%d shots taken", board.shots_taken_count);
    attroff(COLOR_PAIR(BOARD_PAIR));

    // Make cursor invisible
    curs_set(0);

    refresh();
    long int t0, t1;
    t0 = time(0);
    while (true) {
        t1 = time(0);
        if (t1 - t0 > display_seconds) {
            return;
        }
    }
}
