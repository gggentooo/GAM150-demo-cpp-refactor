/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef GAME_H
#define GAME_H

#define MAX_SHAPE_MASS_COUNT	99

#include "library.h"
#include "filereader.h"

struct Game {

	Game();
	~Game();
	void initialize();
	void load_shape_masses();
	void update();
	void draw();

	Filereader filereader;
	Point_map point_map_0;
	// temp hardcoded points
	std::vector<Point> all_shape_points = { {0, 0, 0, 0}, {0, 1, 3, 2}, {0, 2, 5, 3},
											{0, 3, 5, 5}, {0, 4, 4, 7}, {0, 2, 2, 3},
											{1, 0, 12, 8}, {1, 1, 16, 9}, {1, 2, 24, 12},
											{ 1, 3, 22, 16}, {1, 4, 18, 15}, {1, 5, 14, 12} };
	std::vector<Shape_mass> shape_masses;

	bool did_read_map_file = false;
private:
	int shape_count = 2; // also temp hardcoded value
};

#endif