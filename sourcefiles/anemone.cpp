/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include "anemone.h"

Anemone::Anemone(Math::vec2 position, enum LightColors color) : position(position), color(color) {
	switch (color) {
	case WHITE:
		doodlecolor = { 255,255,255,80 };
		break;
	case RED:
		doodlecolor = { 255, 0, 255, 80 };
		break;
	case GREEN:
		doodlecolor = { 120,255,0,80 };
		break;
	case BLUE:
		doodlecolor = { 0,255,255,80 };
		break;
	}
}

Anemone::~Anemone() {

}

void Anemone::set_has_nemo(bool value) {
	has_nemo = value;
	doodlecolor.alpha = 160;
}

void Anemone::draw() {
	doodle::push_settings();
	doodle::set_outline_color(255, 255, 255, 255);
	doodle::set_fill_color(doodlecolor);
	doodle::draw_ellipse(position.x, position.y, size, size);
	doodle::pop_settings();
}