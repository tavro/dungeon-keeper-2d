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
	Tile* map[16][16];
	bool selection_map[16][16];

	void fill_map() {
		for(int y = 0; y < 16; y++)
			for(int x = 0; x < 16; x++)
				map[x][y] = new Tile(x, y, "./gold.png");
	}

	void draw_map() {
		for(int y = 0; y < 16; y++)
			for(int x = 0; x < 16; x++)
				draw_sprite(map[x][y]->get_x_pos()*16, map[x][y]->get_y_pos()*16, new engine::Sprite(map[x][y]->sprite_path), 1, 0);
	}

	void draw_selection() {
		for(int y = 0; y < 16; y++)
			for(int x = 0; x < 16; x++)
				if(selection_map[x][y])
					draw_sprite(x*16, y*16, new engine::Sprite("./selected.png"), 1, 0);
	}

	bool on_create() override {
		fill_map();
		return true;
	}

	bool on_update(float elapsed_time) override {
		draw_map();
		draw_selection();

		int x = (get_mouse_x()/16)*16;
		int y = (get_mouse_y()/16)*16;
		draw_sprite(x, y, new engine::Sprite("./selection.png"), 1, 0);

		if(get_key(engine::Key::SPACE).pressed) {
			selection_map[x/16][y/16] = !selection_map[x/16][y/16];
		}


		return true;
	}
};

int main() {
    Engine2D demo;

    if(demo.construct(256, 240, 4, 4))
        demo.start();

    return 0;
}