/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "library.h"
#include "light.h"

struct Player {
	Player();
	~Player();
	
	void move(double dt, std::vector<Shape_mass>* shapes, std::vector<Math::vec2>* collide_points);
	void check_shape_mass_collision(std::vector<Shape_mass>* shapes, std::vector<Math::vec2>* collide_points);
	void update(double dt, std::vector<Shape_mass>* shapes, std::vector<Math::vec2>* collide_points);
	void draw();
	Math::vec2 getposition() { return position; }

private:
	doodle::Color color = {0, 0, 255, 255};

	bool colliding = false;

	Math::vec2 position = { 100,100 };
	Math::vec2 prev_position = { 100,100 };

	static constexpr int max_speed = 500;
	static constexpr int min_brake_speed = 10;
	static constexpr int acceleration = 20;
	static constexpr int brake_margin = 30;
	Math::vec2 velocity = { 0, 0 };

	static constexpr int size = 40;

};

#endif
