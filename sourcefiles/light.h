/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef LIGHT_H
#define LIGHT_H

#include "library.h"
#include <doodle/drawing.hpp>

enum LightColor {
	White,
	Red,
	Green,
	Blue
};

struct Light {

	void check_shape_mass_collision(std::vector<Shape_mass>*, std::vector<Point>* collide_points);
	void update(Math::vec2 pos, std::vector<Shape_mass>* shapes, std::vector<Point>* collide_points);
	void draw();

private:
	Math::vec2 position;
	static constexpr int size = 100;
	enum LightColor lightcolor = White;
	doodle::Color color = {255, 255, 255, 80};

};

#endif