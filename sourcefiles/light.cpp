/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include "light.h"
#include <doodle/drawing.hpp>
#include "collision.h"

void Light::check_shape_mass_collision(std::vector<Shape_mass>* shapes, std::vector<Math::vec2>* collide_points) {

	for (int s = 0; s < shapes->size(); ++s) {
		for (int p = 0; p < (*shapes)[s].return_points_count() - 1; ++p) {
			if (Collide::CircleLine(	&position, 
										size,
										&((*shapes)[s].return_points_in_shape()[p].position), 
										&((*shapes)[s].return_points_in_shape()[p + 1].position),
										collide_points)
				|| Collide::CircleLine(	&position, 
										size, // last point - first point
										&((*shapes)[s].return_points_in_shape()[0].position),
										&((*shapes)[s].return_points_in_shape()[(*shapes)[s].return_points_count() - 1].position),
										collide_points)) {
				colliding = true;
			}
		}
	}

}

void Light::check_points_in_light_pie(std::vector<Point>* allpoints, std::vector<Math::vec2>* collide_points)
{
	int i = 0;
	for (int i = 0; i < (*allpoints).size(); ++i) {
		double dx = position.x - (*allpoints)[i].position.x;
		double dy = position.y - (*allpoints)[i].position.y;
		double distance = sqrt(pow(dx, 2) + pow(dy, 2));
		if (distance <= size / 2) {
			collide_points->push_back((*allpoints)[i].position);
		} // why does CirclePoint not work but this????? 

		//if (Collide::CirclePoint(&position, size, &(*allpoints)[i].position)) {
		//	collide_points->push_back((*allpoints)[i].position);
		//}
	}		
	//if (Collide::CirclePoint(&position, size, &(*allpoints)[i].position)) {
	//	collide_points->push_back((*allpoints)[i].position);
	//}
}

void Light::update(	Math::vec2 pos, 
					std::vector<Shape_mass>* shapes, 
					std::vector<Point>* allpoints, 
					std::vector<Math::vec2>* light_pie_points,
					std::vector<Math::vec2>* collide_points) 
{
	colliding = false;
	check_shape_mass_collision(shapes, collide_points);
	check_points_in_light_pie(allpoints, collide_points);
	position = pos;

}

void Light::draw() {

	doodle::push_settings();
	doodle::set_outline_color(255, 255, 255, 255);
	doodle::set_fill_color(color);
	doodle::draw_ellipse(position.x, position.y, size, size);
	doodle::pop_settings();

}