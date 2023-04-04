/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#include "collision.h"
#include <math.h>
#include <doodle/drawing.hpp> // temporary, for testing
#include "library.h"

bool Collide::CirclePoint(const Math::vec2* center,
	int diameter,
	const Math::vec2* point) 
{
	double dx = center->x - point->x;
	double dy = center->y - point->y;
	double dist = sqrt(pow(dx, 2) + (dy, 2));

	if (dist <= diameter / 2) {
		return true;
	}

	return false;

}

bool Collide::LinePoint(Math::vec2* point_p, Math::vec2* line_p1_p, Math::vec2* line_p2_p) {

	Math::vec2 point = *point_p, line_p1 = *line_p1_p, line_p2 = *line_p2_p;

	double dist_1 = sqrt( pow(point.x - line_p1.x, 2) + pow(point.y - line_p1.y, 2) );
	double dist_2 = sqrt( pow(point.x - line_p2.x, 2) + pow(point.y - line_p2.y, 2) );
	double line_length = sqrt( pow(line_p1.x - line_p2.x, 2) + pow(line_p1.y - line_p2.y, 2) );

	if ((int)(dist_1 + dist_2) == (int)line_length) { // cast to int to simulate buffer
		return true;
	}

	return false;

}

bool Collide::CircleLine(	const Math::vec2* center_p, 
							int diameter, 
							const Math::vec2* point1_p, 
							const Math::vec2* point2_p,
							std::vector<Math::vec2>* collide_points)
{
	unsigned char intersecting_points_count = 0;
	bool colliding_definite = false;

	Math::vec2 center = *center_p, point1 = *point1_p, point2 = *point2_p;

	Math::vec2 vec_p1_c = center - point1; // vector from point1 to center
	Math::vec2 vec_p1_p2 = point2 - point1; // vector from point2 to center

	double angle = Math::angle_between(vec_p1_c, vec_p1_p2);
	double line_len = sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));

	double dot = ((center.x - point1.x) * (point2.x - point1.x) + (center.y - point1.y) * (point2.y - point1.y)) / pow(line_len, 2);
	Math::vec2 closest_point = { point1.x + dot * (point2.x - point1.x), point1.y + dot * (point2.y - point1.y) };

	// distance from center of circle to closest point on line 
	double dist_center_line = sqrt(pow(center.x - closest_point.x, 2) + pow(center.y - closest_point.y, 2));
	if ((dist_center_line <= diameter / 2) && Collide::LinePoint(&closest_point, &point1, &point2)) {
		colliding_definite = true; // distance to line is less than radius, and closest point is on line -> definitely colliding
	}
	else { // NOT definitely not colliding (see below)
		colliding_definite = false;
	}
	if (Collide::CirclePoint(center_p, diameter, point1_p) || Collide::CirclePoint(center_p, diameter, point2_p)) {
		colliding_definite = true;
	} // if either end of line is inside circle, definitely colliding, even if closest point is not on line

	if (!colliding_definite) {
		return false;
	} // return false and skip everything below if not colliding 

	// if is indeed colliding, get the 2 potential collision points,
	// check if either is on line, and push to collide_points
	double intersect_trigslope = sqrt(pow(diameter / 2, 2) - pow(dist_center_line, 2));
	double intersect_angle = Math::angle_between(vec_p1_p2, { 1, 0 });
	double intersect_dx = intersect_trigslope * cos(intersect_angle);
	double intersect_dy = intersect_trigslope * sin(intersect_angle);
	Math::vec2 maybe_intersect_0 = { closest_point.x + intersect_dx, closest_point.y + intersect_dy };
	Math::vec2 maybe_intersect_1 = { closest_point.x - intersect_dx, closest_point.y - intersect_dy };
	if (Collide::LinePoint(&maybe_intersect_0, &point1, &point2)) {
		collide_points->push_back(maybe_intersect_0);
	}
	if (Collide::LinePoint(&maybe_intersect_1, &point1, &point2)) {
		collide_points->push_back(maybe_intersect_1);
	}
	return true;

	printf("%d\n", intersecting_points_count);

}