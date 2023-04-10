/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include "stage1.h"
#include <doodle/drawing.hpp>
#include <vector>

Stage1::Stage1()
{
	anemones.push_back(new Anemone({ 800, 600 }, GREEN));
	anemones.push_back(new Anemone({ 400, 500 }, BLUE));
	anemones.push_back(new Anemone({ 700,200 }, RED));
	nemos.push_back(new Nemo({ 100, 100 }, RED));
	nemos.push_back(new Nemo({ 200, 100 }, RED));
	nemos.push_back(new Nemo({ 800, 100 }, GREEN));
	nemos.push_back(new Nemo({ 300,100 }, GREEN));
	nemos.push_back(new Nemo({ 300,600 }, BLUE));
	walls.push_back(new Wall({ 800, 600 }, { 900, 400 }, GREEN));
	walls.push_back(new Wall({ 400, 500 }, { 200, 400 }, RED));
	walls.push_back(new Wall({ 700, 200 }, { 500, 400 }, BLUE));
}

Stage1::~Stage1() {}

void Stage1::initialize(Math::vec2 player_position)
{
	puts("stage1 initializing");
	load_shape_masses();
	printf("all_shape_points size: %d\n", all_shape_points.size());
	printf("shape mass count: %d\n", shape_masses.size());
	player->set_position(player_position);
}

void Stage1::load_shape_masses()
{
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

void Stage1::update() {
	collide_points.clear();
	light_pie_points.clear();
	player->update(doodle::DeltaTime, &shape_masses, &collide_points, light->return_updating_color(), &walls);
	light->update(player->getposition(), &shape_masses, &all_shape_points, &light_pie_points, &collide_points);
	light->update_color(&get_input());
	for (int i = 0; i < nemos.size(); ++i) {
		nemos[i]->update(doodle::DeltaTime, player->getposition(), light->return_color(), &anemones, &walls);
	}

	for (int i = 0; i < collide_points.size(); ++i) {
		light_pie_points.push_back(collide_points[i]);
	}
}

void Stage1::draw()
{
	//printf("shape mass count: %d\n", shape_masses.size());
	for (int i = 0; i < shape_count; ++i) {
		shape_masses[i].draw();
	}

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

	if (light->return_updating_color())
		light->draw_wheel();
}