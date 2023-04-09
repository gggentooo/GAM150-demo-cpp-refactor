/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include "nemo.h"
#include <doodle/drawing.hpp>
#include "library.h"

Nemo::Nemo(Math::vec2 position, enum LightColors color) : position(position), velocity({0,0}), color(color) {
	switch (color) {
	case WHITE:
		doodlecolor = { 255,255,255,255 };
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

Nemo::~Nemo() {

}

void Nemo::move(double dt, Math::vec2 player_position, enum LightColors lightcolor, std::vector<Anemone*>* anemones)
{
	if (found_anemone) {
		double dx = (*anemones)[anemone_number]->return_position().x - position.x;
		double dy = (*anemones)[anemone_number]->return_position().y - position.y;
		double distance = sqrt(pow(dx, 2) + pow(dy, 2));
		if (distance > 2) {
			//printf("Moving to anemone %d\n", anemone_number);
			velocity = { dx * 3, dy * 3 };
		}
		if (distance < 2) {
			velocity = { 0,0 };
			should_update = false;
			puts("Nemo stop");
		}
	}

	else if (color == lightcolor)
	{
		double dx = player_position.x - position.x;
		double dy = player_position.y - position.y;
		double distance = sqrt(pow(dx, 2) + pow(dy, 2));
		//printf("dx, dy: %lf, %lf\n", dx, dy);

		if (distance < LIGHT_SIZE / 2)
		{
			if (dx >= brake_margin && velocity.x <= max_speed) {
				velocity.x += acceleration;
			}
			if (dx <= brake_margin && velocity.x >= min_brake_speed) {
				velocity.x -= acceleration;
			}
			if (dx <= -brake_margin && velocity.x >= -max_speed) {
				velocity.x -= acceleration;
			}
			if (dx >= -brake_margin && velocity.x <= -min_brake_speed) {
				velocity.x += acceleration;
			}
			if (dy >= brake_margin && velocity.y <= max_speed) {
				velocity.y += acceleration;
			}
			if (dy <= brake_margin && velocity.y >= min_brake_speed) {
				velocity.y -= acceleration;
			}
			if (dy <= -brake_margin && velocity.y >= -max_speed) {
				velocity.y -= acceleration;
			}
			if (dy >= -brake_margin && velocity.y <= -min_brake_speed) {
				velocity.y += acceleration;
			}
		}
		else
		{ // outside of light perimeters; slow down
			if (velocity.x > 0)
				velocity.x -= acceleration;
			else
				velocity.x = 0;

			if (velocity.y > 0)
				velocity.y -= acceleration;
			else
				velocity.y = 0;
		}
	}
	else
	{ // inside wrong color; slow down
		if (velocity.x > 0)
			velocity.x -= acceleration;
		else
			velocity.x = 0;

		if (velocity.y > 0)
			velocity.y -= acceleration;
		else
			velocity.y = 0;
	}

	position += velocity * dt;

	// code for collision
}

void Nemo::search_anemone(std::vector<Anemone*>* anemones) {
	for (int i = 0; i < anemones->size(); ++i) {
		double dx = (*anemones)[i]->return_position().x - position.x;
		double dy = (*anemones)[i]->return_position().y - position.y;
		double distance = sqrt(pow(dx, 2) + pow(dy, 2));
		if (distance < anemone_range && !(*anemones)[i]->return_has_nemo() && (*anemones)[i]->return_color() == color) {
			anemone_number = i;
			// set velocity
			if ((*anemones)[i]->return_position().x > position.x) {
				velocity.x = 100;
			}
			if ((*anemones)[i]->return_position().x < position.x) {
				velocity.x = -100;
			}
			if ((*anemones)[i]->return_position().y > position.y) {
				velocity.y = 100;
			}
			if ((*anemones)[i]->return_position().y < position.y) {
				velocity.y = -100;
			}
			found_anemone = true;
			(*anemones)[i]->set_has_nemo(true);
		}
	}
}

void Nemo::update(double dt, Math::vec2 player_position, enum LightColors lightcolor, std::vector<Anemone*>* anemones)
{
	// puts("Nemo updated");
	if (should_update) {
		move(dt, player_position, lightcolor, anemones);
		if (!found_anemone)
			search_anemone(anemones);
	}
}

void Nemo::draw()
{
	doodle::push_settings();
	doodle::set_outline_color(255, 255, 255, 255);
	doodle::set_fill_color(doodlecolor);
	doodle::draw_ellipse(position.x, position.y, size, size);
	doodle::pop_settings();
}