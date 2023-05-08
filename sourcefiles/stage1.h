/*
    GAM150 prototype
    Guyot
    Hankyung Lee
*/

#ifndef STAGE1_H
#define STAGE1_H

#include "collision.h"
#include "library.h"
#include "Vec2.h"

#include "player.h"
#include "nemo.h"
#include "anemone.h"
#include "footprint.h"

#include "../mapdata/Points1.h"

class Stage1
{
public:
    //Stage0(Player* player, Light* light, Math::vec2 player_position);
    Stage1();
    ~Stage1();
    void initialize(Math::vec2 player_position);
    void load_shape_masses();
    void update();
    void draw();


    static Stage1& instance() { // input part needs fix
        static Stage1 instance;
        return instance;
    }

    static CS230::Input& get_input() { return instance().input; }
    Light* get_light() { return light; }

    Points1* points1 = new Points1;
    std::vector<Point> all_shape_points = points1->points;
    std::vector<Math::vec2> collide_points;
    std::vector<Math::vec2> light_pie_points;
    std::vector<Shape_mass> shape_masses;

    std::vector<Nemo*> nemos;
    std::vector<Anemone*> anemones;
    std::vector<Wall*> walls;
    std::vector<Footprint*> footprints;

    void check_cleared();
    bool return_cleared() { return cleared; }

private:
    int shape_count = points1->shapecount;

    CS230::Input input;

    Player* player = new Player({ 100, 100 });
    Light* light = new Light({ 100, 100 });

    Math::vec2 clear_point = { 1200, 240 };
    int clear_point_size = 100;
    bool cleared = false;
};

#endif