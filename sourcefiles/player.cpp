/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include "player.h"
#include <doodle/doodle.hpp>

Player::Player() {}

Player::~Player() {}

void Player::update(double dt) {

	puts("Updated - player");
	if (doodle::KeyIsPressed && (doodle::Key == (doodle::KeyboardButtons::Right))) {
		velocity.x = speed;
	}
	else {
		velocity.x = 0;
	}
	if (doodle::KeyIsPressed && (doodle::Key == (doodle::KeyboardButtons::Left))) {
		velocity.x = -speed;
	}
	else {
		velocity.x = 0;
	}
	if (doodle::KeyIsPressed && (doodle::Key == (doodle::KeyboardButtons::Up))) {
		velocity.y = speed;
	}
	else {
		velocity.y = 0;
	}
	if (doodle::KeyIsPressed && (doodle::Key == (doodle::KeyboardButtons::Down))) {
		velocity.y = -speed;
	}
	else {
		velocity.y = 0;
	}
	position.x += velocity.x * dt;
	position.y += velocity.y * dt;

}

void Player::draw() {

	doodle::push_settings();
	doodle::set_fill_color(0xFFFFFFFF);
	doodle::set_outline_color(0x00FFFFFF);
	doodle::draw_ellipse(position.x, position.y, size, size);
	doodle::pop_settings();

}