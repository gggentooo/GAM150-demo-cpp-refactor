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

}


void Game::update() 
{
	input.Update();
	stage0->update();
}

void Game::draw() 
{
	stage0->draw();
}