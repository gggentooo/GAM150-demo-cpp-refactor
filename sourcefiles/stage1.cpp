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
	camera->SetLimit({ 0, 0 }, { 1280 * 3, 720 * 3 });
	anemones.push_back(new Anemone({ 440 * 3, 240 * 3 }, RED));
	walls.push_back(new Wall({ 440 * 3, 240 * 3 }, { 480 * 3, 320 * 3 }, RED));
	nemos.push_back(new Nemo({ 720 * 3, 390 * 3 }, RED));
	anemones.push_back(new Anemone({ 930 * 3, 380 * 3 }, BLUE));
	walls.push_back(new Wall({ 930 * 3, 380 * 3 }, { 960 * 3, 580 * 3 }, BLUE));
	nemos.push_back(new Nemo({ 650 *3, 300 * 3 }, BLUE));
}

Stage1::~Stage1() {}

void Stage1::initialize(Math::vec2 player_position)
{
	puts("stage1 initializing");
	load_shape_masses();
	player->set_position(player_position);
}

void Stage1::load_shape_masses()
{
	std::vector<Point> temp_points;
	for (int j = 0; j < shape_count; ++j) {
		for (int i = 0; i < all_shape_points.size(); ++i) {
			if (all_shape_points[i].shape_no == j) {
				temp_points.push_back(all_shape_points[i]);
				Point& added_point = temp_points.back(); // get a reference to the most recently added point
				added_point.position *= 3; // modify its position
			}
		}
		Shape_mass temp_shape_mass(temp_points, temp_points.size(), j);
		shape_masses.push_back(temp_shape_mass);

		temp_points.clear();
	}
}

void Stage1::check_cleared()
{
	Math::vec2 player_position = player->getposition();
	if (Collide::CircleCircle(&clear_point, clear_point_size / 2, &player_position, player->getsize()))
	{
		cleared = true;
	}
}

void Stage1::update() {
	check_cleared();
	collide_points.clear();
	light_pie_points.clear();
	player->update(doodle::DeltaTime, &shape_masses, &collide_points, light->return_updating_color(), &walls, &footprints, camera);
	camera->Update(player->getposition());
	light->update(player->getposition(), &shape_masses, &all_shape_points, &light_pie_points, &collide_points, camera);
	for (int i = 0; i < nemos.size(); ++i) {
		nemos[i]->update(doodle::DeltaTime, player->getposition(), light->return_color(), &anemones, &walls);
	}

	for (int i = 0; i < collide_points.size(); ++i) {
		light_pie_points.push_back(collide_points[i]);
	}
}

void Stage1::draw()
{
	doodle::push_settings();

	doodle::apply_translate(-camera->GetPosition().x, -camera->GetPosition().y);
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
	doodle::set_outline_color(255, 0, 0, 255);
	doodle::set_fill_color(255, 255, 255, 180);
	doodle::draw_ellipse(clear_point.x, clear_point.y, clear_point_size, clear_point_size);

	doodle::pop_settings();
}