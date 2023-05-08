/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef POINTS0_H
#define POINTS0_H

#include "../sourcefiles/library.h"

struct Points0
{
	int pointcount = 11;
	int shapecount = 1;

	std::vector<Point> points
	{
		{ 0, 0, {0, 0} },
		{ 0, 1, {1280, 0} },
		{ 0, 2, {1280, 720} },
		{ 0, 3, {0, 720} },
		{ 0, 4, {0, 700} },
		{ 0, 5, {600, 600} },
		{ 0, 6, {1200, 550} },
		{ 0, 7, {1180, 100} },
		{ 0, 8, {600, 120} },
		{ 0, 9, {20, 30} },
		{ 0, 10, {0, 20} }
	};
};

#endif