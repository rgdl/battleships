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
    int *get_shot();
    int height;
    int width;
};

#endif
