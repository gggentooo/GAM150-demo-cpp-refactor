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
	// Filereader filereader;
	Point_map point_map_0;
	Points1 points1;

	// temp hardcoded points
	std::vector<Point> all_shape_points = { /*{0, 0, {0, 0} }, { 0, 1, {point_map_0.return_width_point_count(), 0} },
											{0, 2, {point_map_0.return_width_point_count(), point_map_0.return_height_point_count()} },
											{0, 3, {point_map_0.return_width_point_count() - 4, point_map_0.return_height_point_count() - 4} },
											{0, 4, {22, 8} }, {0, 5,{ 10, 4} }
											{1, 0, 12, 8}, {1, 1, 16, 10}, {1, 2, 18, 12},
											{1, 3, 19, 13}, {1, 4, 16, 12}, {1, 5, 8, 15},
											{2, 0, 0, 0}, {2, 1, 0, point_map_0.return_height_point_count()},
											{2, 2, 7, point_map_0.return_height_point_count()},
											{2, 3, 5, 15}, {2, 4, 4, 8}*/
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