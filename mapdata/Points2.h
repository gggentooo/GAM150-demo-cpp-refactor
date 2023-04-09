/*
	GAM150 prototype
	Guyot
	Jimin Lim
*/

#ifndef POINTS1_H
#define POINTS1_H

#include "../sourcefiles/library.h"

struct Points1 {

	int pointcount = 62;
	int shapecount = 9;

	double x = 800;
	double y = 200;
	Point _00 = { 0, 0, {x , 0} };
	Point _01 = { 0, 1, {x - 20 , y} };
	Point _02 = { 0, 2, {x + 20 , y + 20} };
	Point _03 = { 0, 3, {x , y + 60} };
	Point _04 = { 0, 4, {x + 60 , y + 75} };
	Point _05 = { 0, 5, {x + 70 , y + 75} };
	Point _06 = { 0, 6, {x + 75, y + 70} };
	Point _07 = { 0, 7, {x + 70, y + 45 } };
	Point _08 = { 0, 8, {x + 75 , y + 30} };
	Point _09 = { 0, 9, {x + 70 , 0} };

	double q = 1280;
	double p = 400;
	Point _10 = { 1, 10, {q , p} };
	Point _11 = { 1, 11, {q - 150, p - 20} };
	Point _12 = { 1, 12, {q - 275 , p - 30} };
	Point _13 = { 1, 13, {q - 280 , p - 45} };
	Point _14 = { 1, 14, {q - 300 , p - 70} };
	Point _15 = { 1, 15, {q - 280 , p - 80} };
	Point _16 = { 1, 16, {q - 240 , p - 70} };
	Point _17 = { 1, 17, {q - 220 , p - 80} };
	Point _18 = { 1, 18, {q , p - 75} };

	double z = 900;
	double w = 300;
	Point _19 = { 2, 19, {x + 75 , y + 30} };
	Point _20 = { 2, 20, {z + 30 , w + 10} };
	Point _21 = { 2, 21, {z + 50 , w + 20} };
	Point _22 = { 2, 22, {q - 280 , p - 80} };
	Point _23 = { 2, 23, {q - 300 , p - 70} };
	Point _24 = { 2, 24, {z + 40 , w + 30} };
	Point _25 = { 2, 25, {z + 20 , w + 30} };
	Point _26 = { 2, 26, {x + 75, y + 70} };
	Point _27 = { 2, 26, {x + 70, y + 45} };

	double i = 0;
	double j = 0;
	Point _28 = { 3, 28, { i , j} };
	Point _29 = { 3, 29, { i + 50 , j + 100} };
	Point _30 = { 3, 30, { i + 80 , j + 120} };
	Point _31 = { 3, 31, { i + 90 , j + 140 } };
	Point _32 = { 3, 32, { i + 100, j + 150} };
	Point _33 = { 3, 33, { i + 150, j + 100} };
	Point _34 = { 3, 34, { i + 160 ,j + 105 } };
	Point _35 = { 3, 35, { i + 200 ,j } };

	double a = 200;
	Point _36 = { 4, 36, { a , j} };
	Point _37 = { 4, 37, { a + 100, j + 50} };
	Point _38 = { 4, 38, { a + 140, j + 130} };
	Point _39 = { 4, 39, { a + 160, j + 150} };
	Point _40 = { 4, 40, { a + 220, j + 90} };
	Point _41 = { 4, 41, { a + 250, j} };

	double b = 450;
	Point _42 = { 5, 42 ,{ b , i } };
	Point _43 = { 5, 43 ,{ b + 130 , i + 30 } };
	Point _44 = { 5, 44 ,{ b + 150 , i + 50 } };
	Point _45 = { 5, 45 ,{ b + 180, i + 70 } };
	Point _46 = { 5, 46 ,{ b + 200, i + 90} };
	Point _47 = { 5, 47 ,{ 800, i } };

	Point _48 = { 6, 48 ,{ 0 , 400 } };
	Point _49 = { 6, 49 ,{ 0 , 720} };
	Point _50 = { 6, 50 ,{ 500 ,720} };
	Point _51 = { 6, 51 ,{ 200 , 650} };

	Point _52 = { 7, 52 ,{ 800 , 720 } };
	Point _53 = { 7, 53 ,{ 840 , 650 } };
	Point _54 = { 7, 54 ,{ 1000, 580} };
	Point _55 = { 7, 55 ,{ 1200 , 500} };
	Point _56 = { 7, 56 ,{ 1280, 400 } };
	Point _57 = { 7, 57,{ 1280 , 720 } };

	Point _58 = { 8, 58,{ 870 , 0 } };
	Point _59 = { 8, 59,{ 1200 , 50} };
	Point _60 = { 8, 60,{ 1280 , 325 } };
	Point _61 = { 8, 61,{ 1280 , 0 } };

};


#endif