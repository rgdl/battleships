#ifndef ship_hpp
#define ship_hpp

#include <vector>

class Ship {
public:
    Ship(std::vector<int> _indices);
    std::vector<int> indices;
    bool is_sunk;
    void try_shot(int index);
private:
    std::vector<bool> indices_hit;
};

#endif
