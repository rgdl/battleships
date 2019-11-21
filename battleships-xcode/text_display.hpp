#ifndef TEXT_DISPLAY_H
#define TEXT_DISPLAY_H

#include "display.hpp"

#include <vector>

class TextDisplay : public Display {
public:
    TextDisplay(int _height, int _width);
    ~TextDisplay();
    void draw(std::vector<CELL_STATES>);
    int *get_shot();
    int height;
    int width;
};

#endif
