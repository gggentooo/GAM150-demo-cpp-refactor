/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef GAME_H
#define GAME_H

#define MAX_SHAPE_MASS_COUNT	99

#include "library.h"
// #include "filereader.h"
#include "player.h"
#include "../mapdata/Points0.h"

struct Game {

	Game();
	~Game();
	void initialize();
	void load_shape_masses();
	void update();
	void draw();

	Player player;
	Light light;
	// Filereader filereader;
	// Point_map point_map_0;
	Points0 points0;

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