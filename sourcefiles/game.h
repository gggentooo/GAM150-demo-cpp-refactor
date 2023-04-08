/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef GAME_H
#define GAME_H

#define MAX_SHAPE_MASS_COUNT	99

#include "Input.h"
#include "library.h"
#include "player.h"
#include "nemo.h"
#include "anemone.h"
#include "../mapdata/Points0.h"

class Game {
public:
	Game();
	~Game();
	void initialize();
	void load_shape_masses();
	void update();
	void draw();

	static Game& instance() {
		static Game instance;
		return instance;
	}

	Player player;
	Light light;
	CS230::Input input;
	Points0 points0;
	std::vector<Nemo*> nemos;
	std::vector<Anemone*> anemones;

	static Player& get_player() { return instance().player; }
	static Light& get_light() { return instance().light; }
	static Points0& get_points0() { return instance().points0; }
	static CS230::Input& get_input() { return instance().input; }

	// temp hardcoded points
	std::vector<Point> all_shape_points = {
		points0._00, points0._01, points0._02,
		points0._03, points0._04, points0._05
	};

	std::vector<Math::vec2> collide_points;
	std::vector<Math::vec2> light_pie_points;
	std::vector<Shape_mass> shape_masses;

	bool did_read_map_file = false;

private:

	int shape_count = 1; // also temp hardcoded value

};

#endif