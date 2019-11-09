# Battleships

To begin with, this will be implemented with textual display, using `ncurses`.

Implement display to an interface so that openGL or similar can be substituted later.

First step, get basic board display with some test code.


## Classes

### Game
* Has
- A `Board`
- Other game state?
* Does
- Start
- Do rounds
- Finish

### Board
(holds most of game state)
* Has
- height
- width
- Ship positions
- Previous shots [this is inherent in state]
- A `Display`
* Does
- Updates (specifically, updates state to reflect shot taken, then updates the display)

### Display
(initialise in the constructor function)
* Does
- draw (function of game state, passed in from board)
