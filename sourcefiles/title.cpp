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
	doodle::draw_text("Maritime Lights - Playtest #2 Demo\nGAM150 Spring 2023\nGuyot\n\nInstructions:\n\Move around using your mouse\nChange your light's color by pressing right click and opening the Color Wheel.\nDifferent paths will be visible under different colored light!\nReach the end of the maze to move on.\n\nClick to start\n"
		, 0, 600);
}