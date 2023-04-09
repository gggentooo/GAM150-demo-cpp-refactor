/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef POINTS0_H
#define POINTS0_h

#include "../sourcefiles/library.h"

struct Points0 {
	int pointcount = 6;
	int shapecount = 1;

	std::vector<Point> points
	{
		{ 0, 0, { 480, 320 } },
		{ 0, 1, {640, 400} },
		{ 0, 2, {720, 480} },
		{ 0, 3, {820, 520} },
		{ 0, 4, {640, 560} },
		{ 0, 5, {420, 580} }
	};

	Point _00 = { 0, 0, {480, 320} };
	Point _01 = { 0, 1, {640, 400} };
	Point _02 = { 0, 2, {720, 480} };
	Point _03 = { 0, 3, {820, 520} };
	Point _04 = { 0, 4, {640, 560} };
	Point _05 = { 0, 5, {420, 580} };

	

};

#endif