/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include "footprint.h"

Footprint::Footprint(Math::vec2 position, enum LightColors color) : position(position), color(color) {
	switch (color) {
	case WHITE:
		doodlecolor = { 255,255,255,80 };
		break;
	case RED:
		doodlecolor = { 255,0,120,80 };
		break;
	case GREEN:
		doodlecolor = { 120,255,0,80 };
		break;
	case BLUE:
		doodlecolor = { 0,120,255,80 };
		break;
	}
}

Footprint::~Footprint() {

}
void Footprint::draw() {
	if (is_visible == true)
	{
		doodle::push_settings();
		doodle::set_outline_color(255, 255, 255, 255);
		doodle::set_fill_color(doodlecolor);
		doodle::draw_ellipse(position.x, position.y, size, size);
		doodle::pop_settings();
	}
}

void Footprint::set_is_visible(bool value)
{
	is_visible = value;
}