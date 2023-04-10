/*
    GAM150 prototype
    Guyot
    Hankyung Lee
*/

#ifndef TITLE_H
#define TITLE_H

#include "Input.h"

class Title
{
public:
    Title();
    ~Title();
    void update();
    void draw();


    static Title& instance() { // input part needs fix
        static Title instance;
        return instance;
    }

    bool return_move_on() { return move_on; }

private:
    bool move_on = false;

};

#endif