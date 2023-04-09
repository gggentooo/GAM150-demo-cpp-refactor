/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include "game.h"

Game::Game() {
	nemos.push_back(new Nemo({ 100, 100 }, BLUE));
	nemos.push_back(new Nemo({ 200, 100 }, RED));
	nemos.push_back(new Nemo({ 800, 100 }, RED));
	nemos.push_back(new Nemo({ 300,100 }, GREEN));
	nemos.push_back(new Nemo({ 300,600 }, GREEN));
	anemones.push_back(new Anemone({ 800, 600 }, RED));
	anemones.push_back(new Anemone({ 400, 500 }, GREEN));
	anemones.push_back(new Anemone({ 700,200 }, BLUE));
	walls.push_back(new Wall({ 800, 600 }, { 900, 400 }, RED));
	walls.push_back(new Wall({ 400, 500 }, { 200, 400 }, GREEN));
	walls.push_back(new Wall({ 700, 200 }, { 500, 400 }, BLUE));
}

Game::~Game() {}

void Game::initialize() 
{

}


void Game::update() 
{
	input.Update();
	collide_points.clear();
	light_pie_points.clear();
	// puts("Updated - game");
	player->update(doodle::DeltaTime, &shape_masses, &collide_points, light->return_updating_color(), &walls);
	light->update_color(&get_input());
	light->update(player->getposition(), &shape_masses, &all_shape_points, &light_pie_points, &collide_points);
	for (int i = 0; i < nemos.size(); ++i) {
		nemos[i]->update(doodle::DeltaTime, player->getposition(), light->return_color(), &anemones, &walls);
	}

	for (int i = 0; i < collide_points.size(); ++i) {
		light_pie_points.push_back(collide_points[i]);
	}

	//if (input.MouseButtonDown(0)) {
	//	puts("Left click");
	//}

}

void Game::draw() {

	doodle::clear_background(0);
	// draw points - really slow. need fix 
	// point_map_0.draw();

	for (int i = 0; i < shape_count; ++i) {
		shape_masses[i].draw();
	}
	 
	//doodle::push_settings(); // mouse cross
	//doodle::set_outline_color(255, 0, 220);
	//doodle::draw_line(doodle::get_mouse_x(), 0, doodle::get_mouse_x(), WINDOW_HEIGHT);
	//doodle::draw_line(0, doodle::get_mouse_y(), WINDOW_WIDTH, doodle::get_mouse_y());
	//doodle::pop_settings();

	player->draw();
	light->draw(&collide_points);

	for (int i = 0; i < walls.size(); ++i) {
		walls[i]->draw();
	}
	for (int i = 0; i < nemos.size(); ++i) {
		nemos[i]->draw();
	}
	for (int i = 0; i < anemones.size(); ++i) {
		anemones[i]->draw();
	}

	doodle::push_settings();
	doodle::set_outline_color(255, 255, 255);
	doodle::set_outline_width(7);
	doodle::set_fill_color(255, 0, 0);
	for (int i = 0; i < light_pie_points.size(); ++i) {
		doodle::draw_ellipse(light_pie_points[i].x, light_pie_points[i].y, 10, 10);
	}
	doodle::pop_settings();

}