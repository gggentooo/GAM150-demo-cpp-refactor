/*
    GAM150 prototype
    Guyot
    Hankyung Lee
*/

#ifndef STAGE0_H
#define STAGE0_H

#include "library.h"
#include "Vec2.h"

#include "player.h"
#include "nemo.h"
#include "anemone.h"

#include "../mapdata/Points0.h"

class Stage0
{
public:
    //Stage0(Player* player, Light* light, Math::vec2 player_position);
    Stage0();
    ~Stage0();
    void initialize();
    void load_shape_masses();
    void update();
    void draw();


    static Stage0& instance() { // input part needs fix
        static Stage0 instance;
        return instance;
    }

    static CS230::Input& get_input() { return instance().input; }

    Points0* points0 = new Points0;
    std::vector<Point> all_shape_points = points0->points;
    std::vector<Math::vec2> collide_points;
    std::vector<Math::vec2> light_pie_points;
    std::vector<Shape_mass> shape_masses;

    std::vector<Nemo*> nemos;
    std::vector<Anemone*> anemones;

private:
    int shape_count = points0->shapecount;

    CS230::Input input;

    Player* player = new Player({ 300, 100 });
    Light* light = new Light({ 300, 100 });

};

#endif