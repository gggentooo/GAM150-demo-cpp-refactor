/*
    GAM150 prototype
    Guyot
    Hankyung Lee
*/

#include <iostream>

#include <doodle/doodle.hpp>
using namespace doodle;
using namespace std;

#include "library.h"

void main() {
    create_window(WINDOW_WIDTH, WINDOW_HEIGHT);
    set_window_title(WINDOW_TITLE);
    set_frame_of_reference(FrameOfReference::RightHanded_OriginBottomLeft);

    // initialize point map
    Point_map point_map_0;

    while (!is_window_closed()) {
        update_window();
        clear_background(0);
        // draw points
        point_map_0.draw();
    }

    return;
}