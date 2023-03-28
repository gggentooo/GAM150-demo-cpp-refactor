/*
    GAM150 prototype
    Guyot
    Hankyung Lee
*/

#include "library.h"
#include <doodle/doodle.hpp>

Point_map::Point_map() {
    for (int i = 0; i < WINDOW_WIDTH / POINT_DISTANCE; ++i) {
        for (int j = 0; j < WINDOW_HEIGHT / POINT_DISTANCE; ++j) {
            point_map[i][j] = { i,j };
        }
    }
}

void Point_map::draw() {
    // draw points
    doodle::set_fill_color(255, 0, 0, 255);
    for (int i = 0; i < WINDOW_WIDTH / POINT_DISTANCE; ++i) {
        for (int j = 0; j < WINDOW_HEIGHT / POINT_DISTANCE; ++j) {
            doodle::draw_ellipse(i * POINT_DISTANCE, j * POINT_DISTANCE, 4, 4);
        }
    }
}