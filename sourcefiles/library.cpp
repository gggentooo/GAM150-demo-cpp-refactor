/*
    GAM150 prototype
    Guyot
    Hankyung Lee
*/

#include "library.h"
#include <doodle/doodle.hpp>
#include <cstdio>

Point_map::Point_map() {

    for (int i = 0; i < width_point_count; ++i) {
        for (int j = 0; j < height_point_count; ++j) {
            this->point_map[i][j] = { i,j };
        }
    }

}

void Point_map::draw() {
    // draw points
    doodle::set_fill_color(255, 0, 0, 255);
    for (int i = 0; i < width_point_count; ++i) {
        for (int j = 0; j < height_point_count; ++j) {
            doodle::draw_ellipse(i * POINT_DISTANCE - 40, j * POINT_DISTANCE - 40, 6, 6);
        }
    }

}

// -------------------------------------------------------------------------------------

Shape_mass::Shape_mass(std::vector<Point> points, int pointcount, int shapeno) : points_count(pointcount), shape_no(shapeno) {
    // temporary points, later rewrite so that points can be added through constructor
    printf("points_count: %d\nshape_no: %d\n", points_count, shape_no);
    for (int i = 0; i < points_count; ++i) {
        printf("%d\n", i);
        points_in_shape.push_back( points[i] );
    }

}

void Shape_mass::draw() {

    doodle::push_settings();
    doodle::apply_translate(-40, -40);

    doodle::set_outline_color(255, 255, 0, 255);
    doodle::draw_line(points_in_shape[0].x * POINT_DISTANCE, points_in_shape[0].y * POINT_DISTANCE,
                      points_in_shape[points_count - 1].x * POINT_DISTANCE, points_in_shape[points_count - 1].y * POINT_DISTANCE);
    for (int i = 0; i < points_count - 1; ++i) {
        doodle::draw_line(points_in_shape[i].x * POINT_DISTANCE, points_in_shape[i].y * POINT_DISTANCE,
                          points_in_shape[i + 1].x * POINT_DISTANCE, points_in_shape[i + 1].y * POINT_DISTANCE);
    }
    
    doodle::apply_translate(40, 40);
    doodle::pop_settings();

}