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

Game::Game() {}
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

	collide_points.clear();
	// puts("Updated - game");
	player.update(doodle::DeltaTime, &shape_masses, &collide_points);

}

void Game::draw() {

	doodle::clear_background(0);
	// draw points - really slow. need fix 
	// point_map_0.draw();

	for (int i = 0; i < shape_count; ++i) {
		shape_masses[i].draw();
	}
	 
	doodle::push_settings(); // mouse cross
	doodle::set_outline_color(255, 0, 220);
	doodle::draw_line(doodle::get_mouse_x(), 0, doodle::get_mouse_x(), WINDOW_HEIGHT);
	doodle::draw_line(0, doodle::get_mouse_y(), WINDOW_WIDTH, doodle::get_mouse_y());
	doodle::pop_settings();

	player.draw();

	doodle::push_settings();
	doodle::set_outline_color(255, 255, 255);
	doodle::set_outline_width(7);
	doodle::set_fill_color(255, 0, 0);
	for (int i = 0; i < collide_points.size(); ++i) {
		doodle::draw_ellipse(collide_points[i].x, collide_points[i].y, 10, 10);
	}
	doodle::pop_settings();

}