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
	anemones.push_back(new Anemone({ 400, 500 }, RED));
	anemones.push_back(new Anemone({ 500, 400 }, GREEN));
	anemones.push_back(new Anemone({ 600, 300 }, BLUE));
	walls.push_back(new Wall({ 400, 0 }, { 400, 720 }, RED));
	walls.push_back(new Wall({ 500, 0 }, { 500, 720 }, GREEN));
	walls.push_back(new Wall({ 600, 0 }, { 600, 720 }, BLUE));
	nemos.push_back(new Nemo({ 900, 500 }, RED));
	nemos.push_back(new Nemo({ 900, 400 }, GREEN));
	nemos.push_back(new Nemo({ 900, 300 }, BLUE));
}

Stage0::~Stage0() {}

void Stage0::initialize(Math::vec2 player_position)
{
	load_shape_masses();
	player->set_position(player_position);
}

void Stage0::load_shape_masses() 
{
	std::vector<Point> temp_points;
	for (int j = 0; j < shape_count; ++j) {

		for (int i = 0; i < all_shape_points.size(); ++i) { 
			if (all_shape_points[i].shape_no == j) {
				temp_points.push_back(all_shape_points[i]);
			} 
		}
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

	if (light->return_updating_color())
		light->draw_wheel();

	// clearpoint
	doodle::push_settings();
	doodle::set_outline_color(255, 0, 0, 255);
	doodle::set_fill_color(255, 255, 255, 180);
	doodle::draw_ellipse(clear_point.x, clear_point.y, clear_point_size, clear_point_size);
	doodle::pop_settings();
}