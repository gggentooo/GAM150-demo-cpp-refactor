/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef WALL_H
#define WALL_H

#include "Vec2.h"
#include "library.h"

class Wall 
{
public:
	Wall(Math::vec2 point1, Math::vec2 point2, enum LightColors color);
	~Wall();
	bool return_is_active() { return is_active; }
	Math::vec2 return_point1() { return point1; }
	Math::vec2 return_point2() { return point2; }
	void set_is_active(bool value);
	void draw();

private:
	Math::vec2 point1;
	Math::vec2 point2;
	bool is_active = true;
	enum LightColors color = WHITE;
	doodle::Color doodlecolor = { 255, 255, 255, 255 };
	int width = 12;

};

#endif