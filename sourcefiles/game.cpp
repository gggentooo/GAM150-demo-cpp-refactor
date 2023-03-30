/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include <doodle/doodle.hpp>
#include "game.h"
#include "filereader.h"
#include "library.h"

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
				//temp_points.push_back(all_shape_points[i]);
			} // all points with shape # j are now in temp_points
		}
		// create new shape initialized with temp_points and push to total shapes vector
		Shape_mass temp_shape_mass(temp_points, temp_points.size(), j);
	}

}

void Game::update() {

}

void Game::draw() {

	doodle::clear_background(0);
	// draw points
	point_map_0.draw();

	for (int i = 0; i < MAX_SHAPE_MASS_COUNT; ++i) {
		shape_masses[i].draw();
	}

}