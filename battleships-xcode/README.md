# Battleships

To begin with, this will be implemented with textual display, using `ncurses`.

Implement display to an interface so that openGL or similar can be substituted later.

First step, get basic board display with some test code.

What's missing?

* refactor strategy pattern so that the display has a renderer (text or graphics)
* A "shots taken" counter. Pass whole board to `display.draw`, not just cell states (it can get height, width, and shots taken this ways)
* The ability to end the game, with a "game over" and shots taken screen
* clear text input after making a shot
* dedicate 3x3 characters to each display unit
* implement graphical display
