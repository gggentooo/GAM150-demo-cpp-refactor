/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include "Vec2.h"
#include "light.h"
#include <doodle/drawing.hpp>
#include <doodle/input.hpp>
#include "collision.h"
#include "game.h"

Light::Light(Math::vec2 initial_position) : position(initial_position) {

}

void Light::update_color(CS230::Input* gameinput, Camera* camera)
{
	if ((*gameinput).MouseButtonDown(1)) {
		is_updating_color = true;
		// printf("is_updating_color: %d\n", is_updating_color);

		double dx = doodle::get_mouse_x() + camera->GetPosition().x - position.x;
		double dy = doodle::get_mouse_y() + camera->GetPosition().y - position.y;
		Math::vec2 vec_pos_mouse = { dx, dy };
		double angle = Math::angle_between(angle_zero, vec_pos_mouse);
		if (position.y < doodle::get_mouse_y())
			angle = doodle::TWO_PI - angle;

		if (angle > doodle::PI / 6 && angle < doodle::PI / 6 * 5) {
			lightcolor = GREEN;
			color = { 80, 255, 80, 40 };
		}
		if (angle > doodle::PI / 6 * 5 && angle < doodle::PI * 4 / 3) {
			lightcolor = BLUE;
			color = { 80, 80, 255, 40 };
		}
		if (angle > doodle::PI * 4 / 3 || angle < doodle::PI / 6) {
			lightcolor = RED;
			color = { 255, 80, 80, 40 };
		}
		double distance = sqrt(pow(dx, 2) + pow(dy, 2));
		if (distance >= lightwheel_size) {
			lightcolor = WHITE;
			color = { 255, 255, 255, 40 };
		}
		return;
	}
	else if (!(*gameinput).MouseButtonDown(1)) {
		//puts("right button not pressed");
		is_updating_color = false;
	}
}

void Light::check_shape_mass_collision(std::vector<Shape_mass>* shapes, std::vector<Math::vec2>* collide_points) {

	for (int s = 0; s < shapes->size(); ++s) {
		for (int p = 0; p < (*shapes)[s].return_points_count() - 1; ++p) {
			if (Collide::CircleLine(	&position, 
										size,
										&((*shapes)[s].return_points_in_shape()[p].position), 
										&((*shapes)[s].return_points_in_shape()[p + 1].position),
										collide_points)
				|| Collide::CircleLine(	&position, 
										size, // last point - first point
										&((*shapes)[s].return_points_in_shape()[0].position),
										&((*shapes)[s].return_points_in_shape()[(*shapes)[s].return_points_count() - 1].position),
										collide_points)) {
				colliding = true;
			}
		}
	}

}

void Light::check_points_in_light_pie(std::vector<Point>* allpoints, std::vector<Math::vec2>* collide_points)
{
	for (int i = 0; i < (*allpoints).size(); ++i) {
		double dx = position.x - (*allpoints)[i].position.x;
		double dy = position.y - (*allpoints)[i].position.y;
		double distance = sqrt(pow(dx, 2) + pow(dy, 2));
		if (distance <= size / 2) {
			collide_points->push_back((*allpoints)[i].position);
		} // why does CirclePoint not work but this????? 

		//if (Collide::CirclePoint(&position, size, &(*allpoints)[i].position)) {
		//	collide_points->push_back((*allpoints)[i].position);
		//}
	} // collide_points now contain every point within light perimiter

	// figure out angle between angle_zero and each of the point (vectors)
	for (int i = 0; i < (*collide_points).size(); ++i) {
		Math::vec2 vec_center_point = (*collide_points)[i] - position;
		double angle_center_point = Math::angle_between(angle_zero, vec_center_point);
		angles.push_back(angle_center_point);
	}

	// run everything below only if there are any points at all in angles! 
	if (angles.size() > 0) {
		// sort angles in ascending order
		std::sort(angles.begin(), angles.end());

		// create and save pizza slices
		pizza_slices.push_back(angles[0]);
		for (int i = 1; i < angles.size(); ++i) {
			pizza_slices.push_back(angles[i] - angles[i - 1]);
		}

		//// figure out which pizza slices' middle line intersect with any of the shapes' lines
		//// do that for 0th pizza slice here @todo
		//for (int i = 1; i < pizza_slices.size(); ++i) {
		//	// endpoint of middle line
		//	double pizza_middle_angle = angles[i - 1] + pizza_slices[i] / 2;
		//	Math::vec2 endpoint = {cos(pizza_middle_angle)* size / 2, sin(pizza_middle_angle)* size / 2};
		//	endpoint += position;
		//	// collision check line from (position to endpoint) with all the shapes lines

		//}

	}
}

void Light::update(	Math::vec2 pos, 
					std::vector<Shape_mass>* shapes, 
					std::vector<Point>* allpoints, 
					std::vector<Math::vec2>* light_pie_points,
					std::vector<Math::vec2>* collide_points,
					Camera* camera) 
{
	colliding = false;
	check_shape_mass_collision(shapes, collide_points);
	check_points_in_light_pie(allpoints, collide_points);
	position = pos;
}

void Light::draw(std::vector<Math::vec2>* collide_points) 
{
	doodle::push_settings();

	doodle::set_outline_color(255, 255, 255, 255);
	doodle::set_fill_color(color);
	doodle::draw_ellipse(position.x, position.y, size, size);

	doodle::set_outline_color(255, 255, 0, 80);
	for (int i = 0; i < (*collide_points).size(); ++i) {
		doodle::draw_line(position.x, position.y, (*collide_points)[i].x, (*collide_points)[i].y);
	}

	if (is_updating_color)
		draw_wheel();

	doodle::pop_settings();
}

void Light::draw_wheel()
{
	doodle::no_outline();
	//red
	doodle::set_fill_color({ 255, 80, 80, 160 });
	doodle::draw_quad(position.x, position.y,
		position.x, position.y + lightwheel_size,
		position.x + lightwheel_size * cos(doodle::PI / 6), position.y + lightwheel_size * sin(doodle::PI / 6),
		position.x + lightwheel_size * cos(doodle::PI / 6), position.y - lightwheel_size * sin(doodle::PI / 6));
	//green
	doodle::set_fill_color({ 80, 255, 80, 160 });
	doodle::draw_quad(position.x, position.y,
		position.x + lightwheel_size * cos(doodle::PI / 6), position.y - lightwheel_size * sin(doodle::PI / 6),
		position.x, position.y - lightwheel_size,
		position.x - lightwheel_size * cos(doodle::PI / 6), position.y - lightwheel_size * sin(doodle::PI / 6));
	//blue
	doodle::set_fill_color({ 80, 80, 255, 160 });
	doodle::draw_quad(position.x, position.y,
		position.x, position.y + lightwheel_size,
		position.x - lightwheel_size * cos(doodle::PI / 6), position.y + lightwheel_size * sin(doodle::PI / 6),
		position.x - lightwheel_size * cos(doodle::PI / 6), position.y - lightwheel_size * sin(doodle::PI / 6));
}