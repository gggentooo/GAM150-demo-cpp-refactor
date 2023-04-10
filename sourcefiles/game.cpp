/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include "game.h"

Game::Game() 
{

}

Game::~Game() {}

void Game::initialize(int stage_no)
{
	if (title_on) {
		return;
	}
	switch (stage_no) {
	case 0:
		stage0->initialize({ 1000, 300 });
		did_initialize = true;
		break;
	case 1:
		stage1->initialize({ 100,400 });
		did_initialize = true;
		break;

	}
}

void Game::update()
{
	if (title_on) {
		title->update();
		if (title->return_move_on())
			title_on = false;
		return;
	}
	if (!did_initialize) {
		initialize(current_stage);
	}
	else {
		input.Update();
		switch (current_stage) {
		case 0:
			stage0->get_light()->update_color(&get_input());
			stage0->update();
			if (stage0->return_cleared()) {
				++current_stage;
				did_initialize = false;
			}
			break;
		case 1:
			stage1->get_light()->update_color(&get_input());
			stage1->update();
			if (stage1->return_cleared()) {
				++current_stage;
				did_initialize = false;
			}
			break;

		}
	}
}

void Game::draw() 
{
	if (title_on) {
		title->draw();
		return;
	}
	if (did_initialize) {
		doodle::clear_background(0);
		switch (current_stage) {
		case 0:
			stage0->draw();
			break;
		case 1:
			stage1->draw();
			break;

		}
	}
}