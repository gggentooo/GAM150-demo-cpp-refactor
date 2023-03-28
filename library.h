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

iVec2 point_map[WINDOW_WIDTH / POINT_DISTANCE][WINDOW_HEIGHT / POINT_DISTANCE];

struct Point_map {
	Point_map();
	void draw();

private:

};

#endif