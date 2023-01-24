#define APPLICATION_DEF
#include "engine.h"
#include "tile.h"

using namespace std;

class Engine2D : public engine::Engine {
public:
    Engine2D() {
        app_name = "dungeon keeper 2d";
    }

private:
public:
	void fill_map(Tile[16][16]& map) {
		for(int y = 0; y < 16; y++)
			for(int x = 0; x < 16; x++)
				map[x][y] = new Tile(x, y, "/");
	}
	Tile[16][16] selection_map;
	Tile[16][16] ground_map;
	Tile[16][16] collision_map;

	bool on_create() override {
		fill_map();
		fill_map();
		fill_map();
		return true;
	}

	bool on_update(float elapsed_time) override {
		for(int y = 0; y < screen_height(); y+=16) {
			for(int x = 0; x < screen_width(); x+=16) {
				draw_sprite(x, y, new engine::Sprite("./gold.png"), 1, 0);
			}
		}

		int x = (get_mouse_x()/16)*16;
		int y = (get_mouse_y()/16)*16;
		draw_sprite(x, y, new engine::Sprite("./selection.png"), 1, 0);

		return true;
	}
};

int main() {
    Engine2D demo;

    if(demo.construct(256, 240, 4, 4))
        demo.start();

    return 0;
}