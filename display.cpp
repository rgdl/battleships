#include "display.hpp"
#include "board.hpp"

#include <ctime>
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

void pause(int seconds) {
    long int t0, t1;
    t0 = time(0);
    while (true) {
        t1 = time(0);
        if (t1 - t0 > seconds) {
            return;
        }
    }
}
