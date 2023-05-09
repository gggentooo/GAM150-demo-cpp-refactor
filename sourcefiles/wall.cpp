/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include "wall.h"
#include <doodle/drawing.hpp>

Wall::Wall(Math::vec2 point1, Math::vec2 point2, enum LightColors color) : point1(point1), point2(point2), color(color)
{
	switch (color) {
	case WHITE:
		doodlecolor = { 255,255,255, 0 };
		break;
	case RED:
		doodlecolor = { 255, 0, 255, 255 };
		break;
	case GREEN:
		doodlecolor = { 120,255,0,255 };
		break;
	case BLUE:
		doodlecolor = { 0,255,255,255 };
		break;
	}
}

Wall::~Wall() {}

void Wall::set_is_active(bool value)
{
	is_active = value;
	if (is_active == false)
	{
		doodlecolor.alpha = 80;
		puts("wall not active");
	}
}

void Wall::draw()
{
	doodle::push_settings();
	doodle::set_outline_color(doodlecolor);
	doodle::set_outline_width(width);
	doodle::draw_line(point1.x, point1.y, point2.x, point2.y);
	doodle::pop_settings();
}