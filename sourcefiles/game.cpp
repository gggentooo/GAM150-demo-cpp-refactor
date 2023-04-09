/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include <doodle/doodle.hpp>
#include "game.h"
// #include "filereader.h"
#include "library.h"
#include "player.h"

Game::Game() {
	anemones.push_back(new Anemone({ 800, 600 }, RED));
	anemones.push_back(new Anemone({ 400, 500 }, GREEN));
	anemones.push_back(new Anemone({ 700,200 }, BLUE));
	nemos.push_back(new Nemo({ 100, 100 }, BLUE));
	nemos.push_back(new Nemo({ 200, 100 }, RED));
	nemos.push_back(new Nemo({ 300,100 }, GREEN));
	nemos.push_back(new Nemo({ 300,600 }, GREEN));
}
Game::~Game() {}

void Game::initialize() {
	load_shape_masses();
	// whatever other stuff to initialize/load 
}

void Game::load_shape_masses() {
	// temp hardcoded shapes 
	std::vector<Point> temp_points;
	// check each point's shape #, point #, x, y and add to the correct shape
	// if move on to next shape, add previous shape to all shapes vector 
	// shape_masses[all_shape_points[i].shape_no]

	// sort points by shape # & put them in temporary vector of points 
	for (int j = 0; j < shape_count; ++j) {

		for (int i = 0; i < all_shape_points.size(); ++i) { // iterate through points
			if (all_shape_points[i].shape_no == j) {
				temp_points.push_back(all_shape_points[i]);
			} // all points with shape # j are now in temp_points
		}

		// printf("temp_points size: %d\n", temp_points.size());
		// create new shape initialized with temp_points and push to total shapes vector
		Shape_mass temp_shape_mass(temp_points, temp_points.size(), j);
		shape_masses.push_back(temp_shape_mass);

		temp_points.clear();

	}

}

void Game::update() {

	input.Update();
	collide_points.clear();
	light_pie_points.clear();
	// puts("Updated - game");
	player->update(doodle::DeltaTime, &shape_masses, &collide_points, light->return_updating_color());
	light->update_color(&get_input());
	light->update(player->getposition(), &shape_masses, &all_shape_points, &light_pie_points, &collide_points);
	for (int i = 0; i < nemos.size(); ++i) {
		nemos[i]->update(doodle::DeltaTime, player->getposition(), light->return_color(), &anemones);
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