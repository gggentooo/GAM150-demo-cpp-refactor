/*
    GAM150 prototype
    Guyot
    Hankyung Lee
*/

#ifndef STAGE1_H
#define STAGE1_H

#include "library.h"
#include "Vec2.h"

#include "player.h"
#include "nemo.h"
#include "anemone.h"

#include "../mapdata/Points1.h"

class Stage1 
{
public:
    Stage1(Player* player, Light* light, Math::vec2 player_position);
    ~Stage1();
    void update();
    void draw();

    Points1 *points1;

	// temp hardcoded points
	std::vector<Point> all_shape_points;

	std::vector<Math::vec2> collide_points;
	std::vector<Math::vec2> light_pie_points;
	std::vector<Shape_mass> shape_masses;

private:
	int shape_count;

};

#endif