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

	void check_shape_mass_collision(std::vector<Shape_mass>*, std::vector<Math::vec2>* collide_points);
	void check_points_in_light_pie(std::vector<Point>* allpoints, std::vector<Math::vec2>* light_pie_points);
	void update(Math::vec2 pos, 
				std::vector<Shape_mass>* shapes, 
				std::vector<Point>* allpoints, 
				std::vector<Math::vec2>* light_pie_points,
				std::vector<Math::vec2>* collide_points);
	void draw(std::vector<Math::vec2>* collide_points);

private:
	Math::vec2 position;
	static constexpr int size = 300;
	enum LightColor lightcolor = White;
	doodle::Color color = {255, 255, 255, 40};

	bool colliding = false;

	std::vector<double> angles;
	std::vector<double> pizza_slices;

};

#endif