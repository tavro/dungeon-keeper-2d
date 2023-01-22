#define APPLICATION_DEF
#include "engine.h"

using namespace std;

class Engine2D : public engine::Engine {
public:
    Engine2D() {
        app_name = "dungeon keeper 2d";
    }

private:

public:
	bool on_create() override {
		
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