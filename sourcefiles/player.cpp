/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include <doodle/doodle.hpp>
#include "player.h"
#include "collision.h"

Player::Player() {}

Player::~Player() {}

void Player::move(double dt) {

	double dx = doodle::get_mouse_x() - position.x;
	double dy = doodle::get_mouse_y() - position.y;

	if (dx >= brake_margin && velocity.x <= max_speed) {
		velocity.x += acceleration;
	}
	if (dx <= brake_margin && velocity.x >= min_brake_speed) {
		velocity.x -= acceleration;
	}
	if (dx <= -brake_margin && velocity.x >= -max_speed) {
		velocity.x -= acceleration;
	}
	if (dx >= -brake_margin && velocity.x <= -min_brake_speed) {
		velocity.x += acceleration;
	}
	if (dy >= brake_margin && velocity.y <= max_speed) {
		velocity.y += acceleration;
	}
	if (dy <= brake_margin && velocity.y >= min_brake_speed) {
		velocity.y -= acceleration;
	}
	if (dy <= -brake_margin && velocity.y >= -max_speed) {
		velocity.y -= acceleration;
	}
	if (dy >= -brake_margin && velocity.y <= -min_brake_speed) {
		velocity.y += acceleration;
	}

	position += velocity * dt;

}

void Player::check_shape_mass_collision(std::vector<Shape_mass>* shapes, std::vector<Point>* collide_points) {

	// iterate through shapes
	// check for collision
	// collide_points.push_back(points where player and line intersect)

	for (int s = 0; s < shapes->size(); ++s) {

		for (int p = 0; p < (*shapes)[s].return_points_count() - 1; ++p) {

			if (Collide::CircleLine(&position, size, 
				&((*shapes)[s].return_points_in_shape()[p].position), &((*shapes)[s].return_points_in_shape()[p + 1].position))
				|| Collide::CircleLine(&position, size, // last point - first point
					&((*shapes)[s].return_points_in_shape()[0].position), 
					&((*shapes)[s].return_points_in_shape()[(*shapes)[s].return_points_count() - 1].position))) {

				colliding = true;

			}

		}

	}

	//Math::vec2 point1 = { 12, 8 };
	//Math::vec2 point2 = { 8, 15 };

	//if (Collide::CircleLine(&position, size, &point1, &point2)) {
	//	colliding = true;
	//}

	//for (int s = 0; s < shapes.size(); ++s) { // iterate through shape masses

	//	std::vector<Point> current_shape_points = shapes[s].return_points_in_shape();

	//	for (int p = 0; p < shapes[s].return_points_count() - 1; ++p) { // iterate through points, in the shape mass

	//		if (Collide::CircleLine(position, size,
	//			current_shape_points[p].position, current_shape_points[p + 1].position)) {
	//			// is colliding!
	//			puts("Collide!");
	//			colliding = true;

	//		}

	//	}

	//}

}

void Player::update(double dt, std::vector<Shape_mass>* shapes, std::vector<Point>* collide_points) {

	colliding = false;
	check_shape_mass_collision(shapes, collide_points);
	if (colliding) {
		color = { 255, 0, 0, 255 };
	}
	else {
		color = { 0, 0, 255, 255 };
	}

	move(dt);
	// puts("Updated - player");

}

void Player::draw() {

	doodle::push_settings();
	doodle::set_outline_width(4);
	doodle::set_fill_color(color);
	doodle::set_outline_color({ 255, 255, 255, 255 });
	doodle::draw_ellipse(position.x, position.y, size, size);
	doodle::pop_settings();

}