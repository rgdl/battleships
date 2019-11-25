#ifndef TEXT_DISPLAY_H
#define TEXT_DISPLAY_H

#include "board.hpp"
#include "display.hpp"

#include <vector>

class TextDisplay : public Display {
public:
    TextDisplay(int _height, int _width);
    ~TextDisplay();
    void draw(Board board);
    virtual void game_over(Board board, int display_seconds);
    int *get_shot();
    int height;
    int width;
};

#endif
