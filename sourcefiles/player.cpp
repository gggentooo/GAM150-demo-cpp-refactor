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

void Player::check_shape_mass_collision(std::vector<Shape_mass>* shapes, std::vector<Math::vec2>* collide_points) {

	for (int s = 0; s < shapes->size(); ++s) {
		for (int p = 0; p < (*shapes)[s].return_points_count() - 1; ++p) {
			if (	Collide::CircleLine(&position, 
										size, 
										&((*shapes)[s].return_points_in_shape()[p].position), 
										&((*shapes)[s].return_points_in_shape()[p + 1].position),
										collide_points)
				 ||	Collide::CircleLine(&position,
										size, // last point - first point
										&((*shapes)[s].return_points_in_shape()[0].position), 
										&((*shapes)[s].return_points_in_shape()[(*shapes)[s].return_points_count() - 1].position),
										collide_points)
				) {

				colliding = true;
			}
		}
	}
}

void Player::update(double dt, std::vector<Shape_mass>* shapes, std::vector<Math::vec2>* collide_points) {

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