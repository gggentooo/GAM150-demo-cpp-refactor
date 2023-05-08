/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef FOOTPRINT_H
#define FOOTPRINT_H

#include <doodle/drawing.hpp>
#include "Vec2.h"
#include "library.h"

class Footprint
{
public:
	Footprint(Math::vec2 position, enum LightColors color);
	~Footprint();
	void draw();
	enum LightColors* return_color() { return &color; }
	Math::vec2* return_position() { return &position; }
	void set_is_visible(bool value);

private:
	bool is_visible;
	Math::vec2 position;
	enum LightColors color;
	doodle::Color doodlecolor;
	int size = 10;

};

#endif
