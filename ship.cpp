#include "ship.hpp"

#include <vector>

Ship::Ship(std::vector<int> _indices) {
    indices = _indices;
    for (int i = 0; i < _indices.size(); i++) {
        this->indices_hit.push_back(false);
    }
}

void Ship::try_shot(int index) {
    bool set_sunk = true;
    
    // If the index is in the ship, set it as hit
    for (int i = 0; i < this->indices.size(); i++) {
        if (this->indices[i] == index) {
            this->indices_hit[i] = true;
        }
        set_sunk = set_sunk && this->indices_hit[i];
    }

    // If all are hit, that ship is now sunk
    this->is_sunk = set_sunk;
}
