/*
	GAM150 prototype
	Guyot
	Hankyung Lee
	@brief	Vec2, Point & point map, shape mass, point in shape mass
*/

#include <doodle/doodle.hpp>
#include "Vec2.h"

#define WINDOW_TITLE	"GAM150 Guyot prototype"
#define WINDOW_WIDTH	1280
#define WINDOW_HEIGHT	720
#define POINT_DISTANCE	1

#ifndef LIBRARY_H
#define LIBRARY_H

struct Point {
	int shape_no;
	int point_no;
	Math::vec2 position;
};

struct Point_map {

	Point_map();
	void draw();
	static constexpr int return_width_point_count() {
		return width_point_count;
	}
	static constexpr int return_height_point_count() {
		return height_point_count;
	}

private:
	static constexpr int width_point_count = WINDOW_WIDTH / POINT_DISTANCE;
	static constexpr int height_point_count = WINDOW_HEIGHT / POINT_DISTANCE;
	// Math::ivec2 point_map[width_point_count][height_point_count]; // 27x18, no padding 

};

struct Shape_mass {

	Shape_mass(std::vector<Point> points, int pointcount, int shapeno);
	void draw();
	int return_points_count() { return points_count; }
	int return_shape_no() { return shape_no; }
	std::vector<Point> return_points_in_shape() { return points_in_shape; }

private:
	const int points_count;
	const int shape_no;
	std::vector<Point> points_in_shape;

};

#endif