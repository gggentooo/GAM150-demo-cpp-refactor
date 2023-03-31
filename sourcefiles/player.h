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

	void update(double dt);
	void draw();

private:
	iVec2 position = { 100,100 };
	static constexpr int speed = 400;
	Vec2 velocity = { 0, 0 };
	static constexpr int size = 40;

};

#endif
