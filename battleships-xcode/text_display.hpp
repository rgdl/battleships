#ifndef TEXT_DISPLAY_H
#define TEXT_DISPLAY_H

#include "display.hpp"

class TextDisplay : public Display {
public:
    TextDisplay(int _height, int _width);
    ~TextDisplay();
    void draw(CELL_STATES states[]);
    int height;
    int width;
};

#endif
