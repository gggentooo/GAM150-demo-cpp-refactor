/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Input.h"
#include "library.h"
#include "light.h"
#include "wall.h"
#include "footprint.h"
#include "camera.h"

struct Player {
	Player(Math::vec2 initial_position);
	~Player();
	
	void move(	double dt, std::vector<Shape_mass>* shapes, 
				std::vector<Math::vec2>* collide_points,
				std::vector<Wall*>* walls,
				Camera* camera);
	void check_shape_mass_collision(std::vector<Shape_mass>* shapes, 
									std::vector<Math::vec2>* collide_points);
	void check_footprint_visible(std::vector<Footprint*>* footprints);
	void check_wall_collision(std::vector<Wall*>* walls, std::vector<Math::vec2>* collide_points);
	void update(double dt, 
				std::vector<Shape_mass>* shapes, 
				std::vector<Math::vec2>* collide_points,
				bool is_updating_color,
				std::vector<Wall*>* walls,
				std::vector<Footprint*>* footprints,
				Camera* camera);
	void draw();
	Math::vec2 getposition() { return position; }

	void set_position(Math::vec2 coords);
	void set_lightcolor(enum LightColors color);

private:
	doodle::Color color = {0, 0, 255, 255};

	enum LightColors lightcolor = WHITE;

	bool colliding = false;

	Math::vec2 position;
	Math::vec2 prev_position;

	static constexpr int max_speed = 500;
	static constexpr int min_brake_speed = 10;
	static constexpr int acceleration = 20;
	static constexpr int brake_margin = 30;
	Math::vec2 velocity = { 0, 0 };

	static constexpr int size = 40;

};

#endif
