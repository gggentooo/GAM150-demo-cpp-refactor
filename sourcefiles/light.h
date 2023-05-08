/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef LIGHT_H
#define LIGHT_H

#include "library.h"
#include <doodle/drawing.hpp>
#include "Input.h"

struct Light {

	Light(Math::vec2 initial_position);
	~Light();

	void update_color(CS230::Input* gameinput);
	enum LightColors return_color() { return lightcolor; }

	void check_shape_mass_collision(std::vector<Shape_mass>*, std::vector<Math::vec2>* collide_points);
	void check_points_in_light_pie(std::vector<Point>* allpoints, std::vector<Math::vec2>* light_pie_points);
	void update(Math::vec2 pos, 
				std::vector<Shape_mass>* shapes, 
				std::vector<Point>* allpoints, 
				std::vector<Math::vec2>* light_pie_points,
				std::vector<Math::vec2>* collide_points);
	void draw(std::vector<Math::vec2>* collide_points);
	void draw_wheel();
	bool return_updating_color() { return is_updating_color; }
	int return_size() { return size; }

private:
	// CS230::Input input;

	Math::vec2 position;
	static constexpr int size = LIGHT_SIZE; // defined in library.h (for use in nemo and other stuff)
	static constexpr int lightwheel_size = 120;
	enum LightColors lightcolor = WHITE;
	doodle::Color color = {255, 255, 255, 40};
	bool is_updating_color = false;

	bool colliding = false;

	std::vector<double> angles;
	std::vector<double> pizza_slices;

};

#endif