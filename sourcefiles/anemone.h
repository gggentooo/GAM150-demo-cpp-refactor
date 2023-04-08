/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef ANEMONE_H
#define ANEMONE_H

#include <doodle/drawing.hpp>
#include "Vec2.h"
#include "library.h"

class Anemone 
{
public:
	Anemone(Math::vec2 position, enum LightColors color);
	~Anemone();
	void set_has_nemo(bool value);
	void draw();
	Math::vec2 return_position() { return position; }

private:
	Math::vec2 position;
	bool has_nemo = false;
	enum LightColors color;
	doodle::Color doodlecolor;
	int size = 50;

};

#endif
