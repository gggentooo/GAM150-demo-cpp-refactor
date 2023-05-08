/*
    GAM150 prototype
    Guyot
    Hankyung Lee

*/

#include <iostream>

#include <doodle/doodle.hpp>

#include "game.h"

int main() {
    doodle::create_window(WINDOW_WIDTH, WINDOW_HEIGHT);
    doodle::set_window_title(WINDOW_TITLE);
    doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);

    Game& game = Game::instance();
    //game.initialize();

    while (!doodle::is_window_closed())
    {
        doodle::update_window();
        game.draw();
        game.update();
        if (game.return_thankyou_timer() >= 2)
            return 0;
    }

    return 0;
}