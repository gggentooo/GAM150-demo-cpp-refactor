/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include <math.h>
#include "collision.h"
#include "library.h"

bool Collide::CircleLine(Math::vec2 center, int diameter, Math::vec2 point1, Math::vec2 point2) {

	Math::vec2 vec_p1_c = center - point1 * POINT_DISTANCE;
	Math::vec2 vec_p1_p2 = point2 * POINT_DISTANCE - point1 * POINT_DISTANCE;

	printf("{%lf, %lf} {%lf, %lf}\n", vec_p1_c.x, vec_p1_c.y, vec_p1_p2.x, vec_p1_p2.y);

	doodle::push_settings();
	doodle::set_outline_color(255, 255, 0, 255);
	doodle::draw_line(point1.x * POINT_DISTANCE, point1.y * POINT_DISTANCE, vec_p1_c.x, vec_p1_c.y);
	doodle::draw_line(point1.x * POINT_DISTANCE, point1.y * POINT_DISTANCE, vec_p1_p2.x, vec_p1_p2.y);
	doodle::pop_settings();

	double angle = Math::angle_between(vec_p1_c, vec_p1_p2);

	double dist_center_line = sin(angle) * 
		sqrt(pow(center.x - point1.x * POINT_DISTANCE, 2) + pow(center.y - point1.y * POINT_DISTANCE, 2));

	if (dist_center_line <= diameter / 2) {
		return true;
	}

	return false;

}