/*
    GAM150 prototype
    Guyot
    Hankyung Lee
*/

#include "stage0.h"
#include <doodle/drawing.hpp>
#include <vector>

Stage0::Stage0() 
{
	anemones.push_back(new Anemone({ 800, 600 }, RED));
	anemones.push_back(new Anemone({ 400, 500 }, GREEN));
	anemones.push_back(new Anemone({ 700,200 }, BLUE));
	nemos.push_back(new Nemo({ 100, 100 }, BLUE));
	nemos.push_back(new Nemo({ 200, 100 }, RED));
	nemos.push_back(new Nemo({ 800, 100 }, RED));
	nemos.push_back(new Nemo({ 300,100 }, GREEN));
	nemos.push_back(new Nemo({ 300,600 }, GREEN));
	walls.push_back(new Wall({ 800, 600 }, { 900, 400 }, RED));
	walls.push_back(new Wall({ 400, 500 }, { 200, 400 }, GREEN));
	walls.push_back(new Wall({ 700, 200 }, { 500, 400 }, BLUE));
}

Stage0::~Stage0() {}

void Stage0::initialize(Math::vec2 player_position)
{
	load_shape_masses();
	player->set_position(player_position);
}

void Stage0::load_shape_masses() 
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

void Stage0::check_cleared()
{
	Math::vec2 player_position = player->getposition();
	if (Collide::CirclePoint(&clear_point, clear_point_size, &player_position))
	{
		cleared = true;
	}
}

void Stage0::update() {
	check_cleared();
	collide_points.clear();
	light_pie_points.clear();
	player->update(doodle::DeltaTime, &shape_masses, &collide_points, light->return_updating_color(), &walls);
	light->update(player->getposition(), &shape_masses, &all_shape_points, &light_pie_points, &collide_points);
	light->update_color(&get_input());
	//printf("is_updating_color, in stage0::update: %d\n", light->return_updating_color());
	for (int i = 0; i < nemos.size(); ++i) {
		nemos[i]->update(doodle::DeltaTime, player->getposition(), light->return_color(), &anemones, &walls);
	}

	for (int i = 0; i < collide_points.size(); ++i) {
		light_pie_points.push_back(collide_points[i]);
	}
}

void Stage0::draw()
{
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

	// clearpoint
	doodle::push_settings();
	doodle::set_outline_color(255, 0, 0, 255);
	doodle::set_fill_color(255, 255, 255, 180);
	doodle::draw_ellipse(clear_point.x, clear_point.y, clear_point_size, clear_point_size);
	doodle::pop_settings();
}