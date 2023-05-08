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
	double start = 0;
	double x = 80; // 420
	camera->SetLimit({ 0, 0 }, { x * 10, x * 10 });
	int istart = 0;
	int ix = 80; // 420
	clear_point = { start + x * 10, start + x * 1.5 };
	walls.push_back(new Wall({ start,start }, { start + x * 10, start }, WHITE));
	walls.push_back(new Wall({ start,start }, { start, start + x * 10 }, WHITE));
	walls.push_back(new Wall({ start,start + x * 10 }, { start + x * 10, start + x * 10 }, WHITE));
	walls.push_back(new Wall({ start,start + x * 10 }, { start, start + x * 10 }, WHITE));
	walls.push_back(new Wall({ start + x * 10, start + x * 10 }, { start + x * 10, start + x * 2 }, WHITE));

	walls.push_back(new Wall({ start + x * 10, start }, { start + x * 10, start + x }, WHITE));
	walls.push_back(new Wall({ start + x * 9, start }, { start + x * 9, start + x }, WHITE));
	walls.push_back(new Wall({ start, start + x }, { start + x * 3, start + x }, WHITE));
	walls.push_back(new Wall({ start + x * 4, start + x }, { start + x * 6, start + x }, WHITE));
	walls.push_back(new Wall({ start + x * 7, start + x }, { start + x * 8, start + x }, WHITE));
	walls.push_back(new Wall({ start + x, start + x }, { start + x , start + x * 2 }, WHITE));
	walls.push_back(new Wall({ start , start + x * 3 }, { start + x * 2 , start + x * 3 }, WHITE));
	walls.push_back(new Wall({ start + x , start + x * 2 }, { start + x * 2 , start + x * 2 }, WHITE));
	walls.push_back(new Wall({ start + x * 3 , start + x * 2 }, { start + x * 3 , start + x * 3 }, WHITE));
	walls.push_back(new Wall({ start + x * 6 , start }, { start + x * 6 , start + x }, WHITE));
	walls.push_back(new Wall({ start + x * 7 , start + x }, { start + x * 7 , start + x * 2 }, WHITE));
	walls.push_back(new Wall({ start + x * 7 , start + x }, { start + x * 8 , start + x }, WHITE));
	walls.push_back(new Wall({ start + x  , start + x * 4 }, { start + x * 3 , start + x * 4 }, WHITE));
	walls.push_back(new Wall({ start + x  , start + x * 4 }, { start + x , start + x * 6 }, WHITE));
	walls.push_back(new Wall({ start + x * 4  , start + x }, { start + x * 4 , start + x * 3 }, WHITE));
	walls.push_back(new Wall({ start + x * 4 , start + x * 3 }, { start + x * 5 , start + x * 3 }, WHITE));
	walls.push_back(new Wall({ start + x * 5 , start + x * 2 }, { start + x * 5 , start + x * 3 }, WHITE));
	walls.push_back(new Wall({ start + x * 6 , start + x * 2 }, { start + x * 6 , start + x * 3 }, WHITE));
	walls.push_back(new Wall({ start + x * 6 , start + x * 3 }, { start + x * 8 , start + x * 3 }, WHITE));
	walls.push_back(new Wall({ start + x * 8 , start + x * 3 }, { start + x * 8 , start + x * 5 }, WHITE));
	walls.push_back(new Wall({ start + x * 8 , start + x }, { start + x * 8 , start + x * 2 }, WHITE));
	walls.push_back(new Wall({ start + x * 8 , start + x * 2 }, { start + x * 10 , start + x * 2 }, WHITE));
	walls.push_back(new Wall({ start + x  , start + x * 6 }, { start + x * 3 , start + x * 6 }, WHITE));
	walls.push_back(new Wall({ start + x * 2 , start + x * 6 }, { start + x * 2 , start + x * 7 }, WHITE));
	walls.push_back(new Wall({ start + x  , start + x * 7 }, { start + x * 2 , start + x * 7 }, WHITE));
	walls.push_back(new Wall({ start + x  , start + x * 7 }, { start + x  , start + x * 9 }, WHITE));
	walls.push_back(new Wall({ start + x  , start + x * 9 }, { start + x * 2  , start + x * 9 }, WHITE));
	walls.push_back(new Wall({ start + x * 2, start + x * 9 }, { start + x * 2  , start + x * 8 }, WHITE));
	walls.push_back(new Wall({ start + x * 2, start + x * 8 }, { start + x * 3  , start + x * 8 }, WHITE));
	walls.push_back(new Wall({ start + x * 3, start + x * 7 }, { start + x * 3  , start + x * 8 }, WHITE));
	walls.push_back(new Wall({ start + x * 3, start + x * 9 }, { start + x * 3  , start + x * 10 }, WHITE));
	walls.push_back(new Wall({ start + x * 3, start + x * 9 }, { start + x * 4  , start + x * 9 }, WHITE));
	walls.push_back(new Wall({ start + x * 4, start + x * 8 }, { start + x * 4  , start + x * 9 }, WHITE));
	walls.push_back(new Wall({ start + x * 5, start + x * 9 }, { start + x * 5  , start + x * 10 }, WHITE));
	walls.push_back(new Wall({ start + x * 3, start + x * 4 }, { start + x * 3  , start + x * 5 }, WHITE));
	walls.push_back(new Wall({ start + x * 2, start + x * 5 }, { start + x * 4  , start + x * 5 }, WHITE));
	walls.push_back(new Wall({ start + x * 4, start + x * 4 }, { start + x * 4  , start + x * 6 }, WHITE));
	walls.push_back(new Wall({ start + x * 3, start + x * 7 }, { start + x * 4  , start + x * 7 }, WHITE));
	walls.push_back(new Wall({ start + x * 4, start + x * 4 }, { start + x * 5  , start + x * 4 }, WHITE));
	walls.push_back(new Wall({ start + x * 4, start + x * 6 }, { start + x * 5  , start + x * 6 }, WHITE));
	walls.push_back(new Wall({ start + x * 5, start + x * 6 }, { start + x * 5  , start + x * 8 }, WHITE));
	walls.push_back(new Wall({ start + x * 5, start + x * 8 }, { start + x * 8  , start + x * 8 }, WHITE));
	walls.push_back(new Wall({ start + x * 6, start + x * 8 }, { start + x * 6  , start + x * 9 }, WHITE));
	walls.push_back(new Wall({ start + x * 7, start + x * 9 }, { start + x * 7  , start + x * 10 }, WHITE));
	walls.push_back(new Wall({ start + x * 7, start + x * 9 }, { start + x * 9  , start + x * 9 }, WHITE));
	walls.push_back(new Wall({ start + x * 9, start + x * 8 }, { start + x * 10  , start + x * 8 }, WHITE));
	walls.push_back(new Wall({ start + x * 9, start + x * 8 }, { start + x * 9  , start + x * 7 }, WHITE));

	walls.push_back(new Wall({ start + x * 6, start + x * 7 }, { start + x * 9  , start + x * 7 }, WHITE));
	walls.push_back(new Wall({ start + x * 8, start + x * 6 }, { start + x * 8  , start + x * 7 }, WHITE));
	walls.push_back(new Wall({ start + x * 8, start + x * 6 }, { start + x * 9  , start + x * 6 }, WHITE));
	walls.push_back(new Wall({ start + x * 6, start + x * 5 }, { start + x * 6  , start + x * 7 }, WHITE));
	walls.push_back(new Wall({ start + x * 5, start + x * 5 }, { start + x * 6  , start + x * 5 }, WHITE));
	walls.push_back(new Wall({ start + x * 6, start + x * 4 }, { start + x * 7  , start + x * 4 }, WHITE));
	walls.push_back(new Wall({ start + x * 7, start + x * 4 }, { start + x * 7  , start + x * 6 }, WHITE));

	walls.push_back(new Wall({ start + x * 9, start + x * 5 }, { start + x * 10  , start + x * 5 }, WHITE));
	walls.push_back(new Wall({ start + x * 9, start + x * 3 }, { start + x * 9  , start + x * 5 }, WHITE));

	//footprints.push_back(new Footprint({ start + x * 1, start + x }, RED));

	anemones.push_back(new Anemone({ start + x * 1, start + x / 2 + 20 }, RED));
	for (int i = 0; i < 30; ++i)
	{
		int rx = (rand() % ix - (ix / 2)) / 2;
		int ry = (rand() % ix - (ix / 2)) / 2;
		footprints.push_back(new Footprint({ start + x * i / 2 + rx, start + x / 2 + ry}, RED));
	}
	for (int i = 0; i < 10; ++i)
	{
		int rx = (rand() % ix - (ix / 2)) / 2;
		int ry = (rand() % ix - (ix / 2)) / 2;
		footprints.push_back(new Footprint({ start + x * (3.5) + rx, start + x + ry * 3 }, RED));
	}

	anemones.push_back(new Anemone({ start + x * 3.5 + 20, start + x * 2.5 }, GREEN));
	for (int i = 0; i < 10; ++i)
	{
		int rx = (rand() % ix - (ix / 2)) / 2;
		int ry = (rand() % ix - (ix / 2)) / 2;
		footprints.push_back(new Footprint({ start + x * (3.5) + rx, start + x * (2 + i / 2) + ry }, GREEN));
	}
	for (int i = 0; i < 20; ++i)
	{
		int rx = (rand() % ix - (ix / 2)) / 2;
		int ry = (rand() % ix - (ix / 2)) / 2;
		footprints.push_back(new Footprint({ start + x * i / 4 + rx, start + x * 3.5 + ry }, GREEN));
	}
	for (int i = 0; i < 40; ++i)
	{
		int rx = (rand() % ix - (ix / 2)) / 2;
		int ry = (rand() % ix - (ix / 2)) / 2;
		footprints.push_back(new Footprint({ start + x / 2 + rx, start + x * (3.5 + i / 5) + ry }, GREEN));
	}
	for (int i = 0; i < 8; ++i)
	{
		int rx = (rand() % ix - (ix / 2)) / 2;
		int ry = (rand() % ix - (ix / 2)) / 2;
		footprints.push_back(new Footprint({ start + x * i / 4 + rx, start + x * 9.5 + ry }, BLUE));
	}
	for (int i = 0; i < 10; ++i)
	{
		int rx = (rand() % ix - (ix / 2)) / 2;
		int ry = (rand() % ix - (ix / 2)) / 2;
		footprints.push_back(new Footprint({ start + x * 1.5 + rx, start + x * (7.5 + i / 5) + ry }, BLUE));
	}
	for (int i = 0; i < 10; ++i)
	{
		int rx = (rand() % ix - (ix / 2)) / 2;
		int ry = (rand() % ix - (ix / 2)) / 2;
		footprints.push_back(new Footprint({ start + x * 2.5 + rx, start + x * (6.5 + i / 5) + ry }, BLUE));
	}
	anemones.push_back(new Anemone({ start + x * 3.5 + 20, start + x * 6.5 }, BLUE));
	anemones.push_back(new Anemone({ start + x * 2.7, start + x * 9.1 }, RED));
	for (int i = 0; i < 35; ++i)
	{
		int rx = (rand() % ix - (ix / 2)) / 2;
		int ry = (rand() % ix - (ix / 2)) / 2;
		footprints.push_back(new Footprint({ start + x * (2.5 + i / 5) + rx, start + x * 8.5 + ry }, RED));
	}
	anemones.push_back(new Anemone({ start + x * 8.7, start + x * 7.8 }, GREEN));
	for (int i = 0; i < 25; ++i)
	{
		int rx = (rand() % ix - (ix / 2)) / 2;
		int ry = (rand() % ix - (ix / 2)) / 2;
		footprints.push_back(new Footprint({ start + x * (5.5 + i / 5) + rx, start + x * 7.5 + ry }, GREEN));
	}
	for (int i = 0; i < 25; ++i)
	{
		int rx = (rand() % ix - (ix / 2)) / 2;
		int ry = (rand() % ix - (ix / 2)) / 2;
		footprints.push_back(new Footprint({ start + x * 5.5 + rx, start + x * (3.5 + i / 5) + ry }, GREEN));
	}
	for (int i = 0; i < 10; ++i)
	{
		int rx = (rand() % ix - (ix / 2)) / 2;
		int ry = (rand() % ix - (ix / 2)) / 2;
		footprints.push_back(new Footprint({ start + x * 4.5 + rx, start + x * (4.5 + i / 5) + ry }, GREEN));
	}
}

Stage1::~Stage1() {}

void Stage1::initialize(Math::vec2 player_position)
{
	puts("stage1 initializing");
	//load_shape_masses();
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
	doodle::push_settings();

	doodle::apply_translate(-camera->GetPosition().x, -camera->GetPosition().y);
	check_cleared();
	collide_points.clear();
	light_pie_points.clear();
	player->update(doodle::DeltaTime, &shape_masses, &collide_points, light->return_updating_color(), &walls, &footprints, camera);
	camera->Update(player->getposition());
	player->set_lightcolor(light->return_color());
	light->update(player->getposition(), &shape_masses, &all_shape_points, &light_pie_points, &collide_points, camera);
	for (int i = 0; i < nemos.size(); ++i) {
		nemos[i]->update(doodle::DeltaTime, player->getposition(), light->return_color(), &anemones, &walls);
	}
	for (int i = 0; i < collide_points.size(); ++i) {
		light_pie_points.push_back(collide_points[i]);
	}
	doodle::pop_settings();
}

void Stage1::draw()
{
	doodle::push_settings();

	doodle::apply_translate(-camera->GetPosition().x, -camera->GetPosition().y);
	//for (int i = 0; i < shape_count; ++i) {
	//	shape_masses[i].draw();
	//}

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
	for (int i = 0; i < footprints.size(); ++i) {
		footprints[i]->draw();
	}

	if (light->return_updating_color())
		light->draw_wheel();

	// clearpoint
	doodle::set_outline_color(255, 0, 0, 255);
	doodle::set_fill_color(255, 255, 255, 180);
	doodle::draw_ellipse(clear_point.x, clear_point.y, clear_point_size, clear_point_size);

	doodle::pop_settings();
}