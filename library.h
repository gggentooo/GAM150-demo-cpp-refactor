/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include <doodle/doodle.hpp>

#define WINDOW_TITLE	"GAM150 Guyot prototype"
#define WINDOW_WIDTH	1080
#define WINDOW_HEIGHT	720
#define POINT_DISTANCE	40

#ifndef LIBRARY_H
#define LIBRARY_H

struct Vec2 {
	double x;
	double y;
};

struct iVec2 {
	int x;
	int y;
};

struct Point {
	int shape_no;
	int point_no;
	int x;
	int y;
};

struct Point_map {

	Point_map();
	void draw();

private:
	static constexpr int width_point_count = WINDOW_WIDTH / POINT_DISTANCE + 2;
	static constexpr int height_point_count = WINDOW_HEIGHT / POINT_DISTANCE + 2;
	iVec2 point_map[width_point_count][height_point_count]; // 27x18 + padding 1 line each

};

struct Point_in_shape_mass {

	Point_in_shape_mass(int shape_no, int point_no, int x, int y);
	Point return_numbers();

private:
	Point point;

};

struct Shape_mass {

	Shape_mass();
	void draw();

private:
	static constexpr int points_count = 6;
	Point points_in_shape[points_count];

};

#endif