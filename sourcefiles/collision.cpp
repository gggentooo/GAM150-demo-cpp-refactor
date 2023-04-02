/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include "collision.h"
#include <math.h>
#include <doodle/drawing.hpp> // temporary, for testing
#include "library.h"

bool Collide::LinePoint(Math::vec2* point_p, Math::vec2* line_p1_p, Math::vec2* line_p2_p) {

	Math::vec2 point = *point_p, line_p1 = *line_p1_p, line_p2 = *line_p2_p;

	double dist_1 = sqrt( pow(point.x * POINT_DISTANCE - line_p1.x * POINT_DISTANCE, 2) +
						  pow(point.y * POINT_DISTANCE - line_p1.y * POINT_DISTANCE, 2) );
	double dist_2 = sqrt( pow(point.x * POINT_DISTANCE - line_p2.x * POINT_DISTANCE, 2) +
						  pow(point.y * POINT_DISTANCE - line_p2.y * POINT_DISTANCE, 2) );
	double line_length = sqrt( pow(line_p1.x * POINT_DISTANCE - line_p2.x * POINT_DISTANCE, 2) +
							   pow(line_p1.y * POINT_DISTANCE - line_p2.y * POINT_DISTANCE, 2) );

	if ((int)(dist_1 + dist_2) == (int)line_length) { // cast to int to simulate buffer
		return true;
	}

	return false;

}

bool Collide::CircleLine(const Math::vec2* center_p, int diameter, const Math::vec2* point1_p, const Math::vec2* point2_p) {

	Math::vec2 center = *center_p, point1_not_multiplied = *point1_p, point2_not_multiplied = *point2_p;
	Math::vec2 point1 = point1_not_multiplied * POINT_DISTANCE;
	Math::vec2 point2 = point2_not_multiplied * POINT_DISTANCE; // multiply with POINT_DISTANCE to get raw coords

	Math::vec2 vec_p1_c = center - point1; // vector from point1 to center
	Math::vec2 vec_p1_p2 = point2 - point1; // vector from point2 to center

	double angle = Math::angle_between(vec_p1_c, vec_p1_p2);
	double line_len = sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));

	double dot = ((center.x - point1.x) * (point2.x - point1.x) + (center.y - point1.y) * (point2.y - point1.y)) / pow(line_len, 2);
	Math::vec2 closest_point = { point1.x + dot * (point2.x - point1.x), point1.y + dot * (point2.y - point1.y) };

	doodle::push_settings();
	doodle::set_fill_color(0, 0, 0, 0);
	doodle::set_outline_color(255, 0, 255, 255);
	doodle::draw_ellipse(closest_point.x, closest_point.y, 4, 4);
	doodle::pop_settings();

	if (!Collide::LinePoint(&closest_point, &point1, &point2)) {
		return false;
	}

	double dist_center_line = sqrt(pow(center.x - closest_point.x, 2) + pow(center.y - closest_point.y, 2));

	if (dist_center_line <= diameter / 2) {
		return true;
	}

	return false;

}