/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include "player.h"
#include <doodle/doodle.hpp>
#include "collision.h"

Player::Player(Math::vec2 initial_position) : position(initial_position) {}

Player::~Player() {}

void Player::move(double dt, std::vector<Shape_mass>* shapes, std::vector<Math::vec2>* collide_points, std::vector<Wall*>* walls) {

	double dx = doodle::get_mouse_x() - position.x;
	double dy = doodle::get_mouse_y() - position.y;
	double distance = sqrt(pow(dx, 2) + pow(dy, 2));

	if (distance > 2) {
		velocity = { dx * 3, dy * 3 };
	}
	if (distance < 2) {
		velocity = { 0, 0 };
	}

	position.x += velocity.x * dt;
	check_shape_mass_collision(shapes, collide_points);
	check_wall_collision(walls, collide_points);
	if (colliding) {
		position.x = prev_position.x;
		colliding = false;
	}
	position.y += velocity.y * dt;
	check_shape_mass_collision(shapes, collide_points);
	check_wall_collision(walls, collide_points);
	if (colliding) {
		position.y = prev_position.y;
		colliding = false;
	}
	

}

void Player::check_shape_mass_collision(std::vector<Shape_mass>* shapes, std::vector<Math::vec2>* collide_points) {

	for (int s = 0; s < shapes->size(); ++s) {
		for (int p = 0; p < (*shapes)[s].return_points_count() - 1; ++p) {
			if (	Collide::CircleLine(&position, 
										size, 
										&((*shapes)[s].return_points_in_shape()[p].position), 
										&((*shapes)[s].return_points_in_shape()[p + 1].position),
										collide_points)
				 ||	Collide::CircleLine(&position,
										size, // last point - first point
										&((*shapes)[s].return_points_in_shape()[0].position), 
										&((*shapes)[s].return_points_in_shape()[(*shapes)[s].return_points_count() - 1].position),
										collide_points)
				) {

				colliding = true;
			}
		}
	}
}

void Player::check_wall_collision(std::vector<Wall*>* walls, std::vector<Math::vec2>* collide_points)
{
	for (int i = 0; i < walls->size(); ++i)
	{
		if ((*walls)[i]->return_is_active())
		{
			Math::vec2 point1 = (*walls)[i]->return_point1();
			Math::vec2 point2 = (*walls)[i]->return_point2();
			if (Collide::CircleLine(&position, size, &point1, &point2, collide_points))
			{
				puts("colliding with wall");
				colliding = true;
			}
		}
	}
}

void Player::update(double dt, std::vector<Shape_mass>* shapes, std::vector<Math::vec2>* collide_points, bool is_updating_color, std::vector<Wall*>* walls) {

	colliding = false;
	if (!is_updating_color) {
		move(dt, shapes, collide_points, walls);
	}
	//check_shape_mass_collision(shapes, collide_points);
	//if (colliding) {
	//	color = { 255, 0, 0, 255 };
	//	position = prev_position;
	//}
	//else {
	//	color = { 0, 0, 255, 255 };
	//}

	// puts("Updated - player");
	prev_position = position;

}

void Player::draw() {

	doodle::push_settings();
	doodle::set_outline_width(4);
	doodle::set_fill_color(color);
	doodle::set_outline_color({ 255, 255, 255, 255 });
	doodle::draw_ellipse(position.x, position.y, size, size);
	doodle::pop_settings();

}