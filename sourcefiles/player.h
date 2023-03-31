/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include "library.h"

struct Player {
	Player();
	~Player();

	void update(double dt);
	void draw();

private:
	iVec2 position = { 100,100 };
	static constexpr int speed = 10;
	static constexpr int size = 15;

};