/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include <math.h>
#include "collision.h"

bool Collide::CircleLine(Math::vec2 center, int r, Math::vec2 point1, Math::vec2 point2) {

	Math::vec2 vec_p1_c = center - point1;
	Math::vec2 vec_p1_p2 = point2 - point1;
	double angle = Math::angle_between(vec_p1_c, vec_p1_p2);

	double dist_center_line = sin(angle) * sqrt(pow(center.x - point1.x, 2) + pow(center.y - point1.y, 2));

	if (dist_center_line <= r) {
		return true;
	}

	return false;

}