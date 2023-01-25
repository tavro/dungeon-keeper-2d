#include "vector2d.h"

class Tile {
private:
    int_vector_2d pos;
public:
    std::string sprite_path;
    Tile(int x, int y, std::string path) {
        pos.x = x;
        pos.y = y;

        sprite_path = path;
    }

    int_vector_2d get_pos() {
        return pos;
    }

    int get_x_pos() {
        return get_pos().x;
    }

    int get_y_pos() {
        return get_pos().y;
    }
};