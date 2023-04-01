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
#define POINT_DISTANCE	40

#ifndef LIBRARY_H
#define LIBRARY_H

//struct Vec2 {
//	double x;
//	double y;
//};
//
//struct iVec2 {
//	int x;
//	int y;
//};

struct Point {
	int shape_no;
	int point_no;
	int x;
	int y;
};

struct Point_map {

	Point_map();
	void draw();
	int return_width_point_count() {
		return width_point_count;
	}
	int return_height_point_count() {
		return height_point_count;
	}

private:
	static constexpr int width_point_count = WINDOW_WIDTH / POINT_DISTANCE + 2;
	static constexpr int height_point_count = WINDOW_HEIGHT / POINT_DISTANCE + 2;
	Math::ivec2 point_map[width_point_count][height_point_count]; // 27x18 + padding 1 line each

};

struct Shape_mass {

	Shape_mass(std::vector<Point> points, int pointcount, int shapeno);
	void draw();

private:
	int points_count;
	int shape_no;
	std::vector<Point> points_in_shape;

};

#endif