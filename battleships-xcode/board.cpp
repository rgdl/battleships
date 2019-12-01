#include "board.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "consts.hpp"
#include "ship.hpp"


Board::Board(int _height, int _width) {
    height = _height;
    width = _width;
    shots_taken_count = 0;
    for (int i = 0; i < height * width; i++) {
        this->states.push_back(EMPTY);
    }
}

int Board::xy_to_index(int x, int y) {
    // x-axis changes most rapidly
    return this->width * y + x;
}

int *Board::index_to_xy(int index) {
    static int xy[2];
    xy[0] = index % this->width;
    xy[1] = index / this->width;
    return xy;
}

bool Board::is_ship_overlapping(int x, int y, bool is_vertical, int ship_size) {
    CELL_STATES current_cell;
    for (int ship_cell_index = 0; ship_cell_index < ship_size; ship_cell_index++) {
        current_cell = this->states[this->xy_to_index(x, y)];
        if (current_cell != EMPTY) {
            return true;
        }
        if (is_vertical) {
            y++;
        } else {
            x++;
        }
    }
    return false;
}

void Board::add_ship_to_board(int x, int y, bool is_vertical, int ship_size) {
    std::vector<int> indices;
    
    for (int ship_cell_index = 0; ship_cell_index < ship_size; ship_cell_index++) {
        int index = this->xy_to_index(x, y);
        indices.push_back(index);
        this->states[index] = HIDDEN_SHIP;
        if (is_vertical) {
            y++;
        } else {
            x++;
        }
    }
    
    Ship ship(indices);
    
    this->ships.push_back(ship);
    
    
}

void Board::place_ships(int * ship_sizes, int n_ships) {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int ship_size, max_x, max_y, x, y;
    bool is_vertical;
    for (int ship_index = 0; ship_index < n_ships; ship_index++) {
        ship_size = ship_sizes[ship_index];
        
        // Choose random ship position that doesn't overlap an existing ship
        do {
            is_vertical = std::rand() % 2;
            if (is_vertical) {
                max_x = this->width;
                max_y = this->height - ship_size;
            } else {
                max_x = this->width - ship_size;
                max_y = this->height;
            }
            x = max_x == 0 ? 0 : std::rand() % max_x;
            y = max_y == 0 ? 0 : std::rand() % max_y;
        } while (this->is_ship_overlapping(x, y, is_vertical, ship_size));
        
        this->add_ship_to_board(x, y, is_vertical, ship_size);
    }
};

void Board::record_shot(int * coords) {
    this->shots_taken_count++;
    int index = this->xy_to_index(coords[0], coords[1]);
    if (this->states[index] == HIDDEN_SHIP) {
        this->states[index] = HIT;

        // Find which ship was hit and set its cells to sunk if need be
        for (int i = 0; i < this->ships.size(); i++) {
            this->ships[i].try_shot(index);
            if (this->ships[i].is_sunk) {
                for (int j = 0; j < this->ships[i].indices.size(); j++) {
                    this->states[this->ships[i].indices[j]] = SUNK_SHIP;
                }
            }
        }
        
    }
    if (this->states[index] == EMPTY) {
        this->states[index] = MISS;
    }
};

bool Board::game_is_over() {
    for (int i = 0; i < this->width * this->height; i++) {
        if (this->states[i] == HIDDEN_SHIP) {
            return false;
        }
    }
    return true;
}
