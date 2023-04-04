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
#include "../mapdata/Points1.h"

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
	Points1 points1;

	// temp hardcoded points
	std::vector<Point> all_shape_points = {
		points1._00, points1._01, points1._02,
		points1._03, points1._04, points1._05	
	};

	std::vector<Math::vec2> collide_points;
	std::vector<Shape_mass> shape_masses;

	bool did_read_map_file = false;

private:
	int shape_count = 1; // also temp hardcoded value

};

#endif