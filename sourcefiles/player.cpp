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
	
}

void Player::draw() {
	doodle::push_settings();
	doodle::set_fill_color(0xFFFFFFFF);
	doodle::set_outline_color(0x00FFFFFF);
	doodle::draw_ellipse(position.x, position.y, size, size);
	doodle::pop_settings();
}