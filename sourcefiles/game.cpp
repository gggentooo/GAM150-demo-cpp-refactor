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

void Game::initialize()
{
	stage0->initialize({300, 100});
}

void Game::update()
{
	input.Update();
	stage0->get_light()->update_color(&get_input());
	stage0->update();
}

void Game::draw() 
{
	doodle::clear_background(0);
	stage0->draw();
}