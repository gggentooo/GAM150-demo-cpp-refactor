/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include "light.h"
#include <doodle/drawing.hpp>

void Light::check_shape_mass_collision(std::vector<Shape_mass>*, std::vector<Point>* collide_points) {

}

void Light::update(Math::vec2 pos, std::vector<Shape_mass>* shapes, std::vector<Point>* collide_points) {

	position = pos;

}

void Light::draw() {

	doodle::push_settings();
	doodle::set_outline_color(255, 255, 255, 255);
	doodle::set_fill_color(color);
	doodle::draw_ellipse(position.x, position.y, size, size);
	doodle::pop_settings();

}