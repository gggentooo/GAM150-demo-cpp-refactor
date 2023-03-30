/*
    GAM150 prototype
    Guyot
    Hankyung Lee
*/

#include <iostream>

#include <doodle/doodle.hpp>

#include "library.h"
#include "game.h"

int main() {
    doodle::create_window(WINDOW_WIDTH, WINDOW_HEIGHT);
    doodle::set_window_title(WINDOW_TITLE);
    doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);

    Game game;
    game.initialize();

    while (!doodle::is_window_closed()) {

        doodle::update_window();
        game.update();
        game.draw();

    }

    return 0;
}