/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include "title.h"
#include <doodle/input.hpp>
#include <doodle/drawing.hpp>

Title::Title()
{
	doodle::no_outline();
	doodle::set_fill_color(255, 255, 255, 255);
	doodle::set_font_size(20);
}

Title::~Title() {}

void Title::update()
{
	if (doodle::MouseIsPressed)
		move_on = true;
}

void Title::draw()
{
	doodle::clear_background(0);
	doodle::draw_text("Maritime Lights playtest demo\nGAM150 Spring 2023\nGuyot\n\nInstructions:\nUse your mouse to move around\nHold right click to open the color wheel and change your light color\nSee how different things on the screen act under your light\n\nClick to start\n"
		, 0, 600);
}