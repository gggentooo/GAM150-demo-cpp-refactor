/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "library.h"

struct Player {
	Player();
	~Player();

	void move(double dt);
	void check_shape_mass_collision(std::vector<Shape_mass>);
	void update(double dt, std::vector<Shape_mass> shapes);
	void draw();

private:
	Math::vec2 position = { 100,100 };

	static constexpr int max_speed = 500;
	static constexpr int min_brake_speed = 10;
	static constexpr int acceleration = 20;
	static constexpr int brake_margin = 30;
	Math::vec2 velocity = { 0, 0 };

	static constexpr int size = 40;

};

#endif
