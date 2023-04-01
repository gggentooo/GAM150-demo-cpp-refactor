/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include "player.h"
#include <doodle/doodle.hpp>

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

void Player::update(double dt) {

	move(dt);
	puts("Updated - player");

}

void Player::draw() {

	doodle::push_settings();
	doodle::set_fill_color(0xFFFFFFFF);
	doodle::set_outline_color(0x00FFFFFF);
	doodle::draw_ellipse(position.x, position.y, size, size);
	doodle::pop_settings();

}