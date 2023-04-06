/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Input.h
Project:    CS230 Engine
Author:     Jonathan Holmes, Hankyung Lee
Created:    March 8, 2023
*/

#include <doodle/input.hpp>
#include "Input.h"
#include "game.h"

CS230::Input::Input() {
    mousebuttons_down.resize(static_cast<int>(MouseButtons::Unknown));
    previous_mousebuttons_down.resize(static_cast<int>(MouseButtons::Unknown));
}

void CS230::Input::Update() {
    previous_mousebuttons_down = mousebuttons_down;
}

void CS230::Input::SetMouseButtonDown(MouseButtons button, bool value) {
    mousebuttons_down[static_cast<int>(button)] = value;
}

CS230::Input::MouseButtons convert_doodle_to_cs230(doodle::MouseButtons doodle_mousebutton) {
    switch (doodle_mousebutton) {
    case doodle::MouseButtons::Left:
        return CS230::Input::MouseButtons::Left;
    case doodle::MouseButtons::Right:
        return CS230::Input::MouseButtons::Right;
    }
    return CS230::Input::MouseButtons::Unknown;
}

void on_mouse_pressed(doodle::MouseButtons doodle_mouse) {
    CS230::Input::MouseButtons button = convert_doodle_to_cs230(doodle_mouse);
    if (button != CS230::Input::MouseButtons::Unknown) {
        Game::get_input().SetMouseButtonDown(button, true);
    }
}

void on_mouse_released(doodle::MouseButtons doodle_mouse) {
    CS230::Input::MouseButtons button = convert_doodle_to_cs230(doodle_mouse);
    if (button != CS230::Input::MouseButtons::Unknown) {
        Game::get_input().SetMouseButtonDown(button, false);
    }
}
bool CS230::Input::MouseButtonDown(MouseButtons button) {
    return mousebuttons_down[static_cast<int>(button)];
}

bool CS230::Input::MouseButtonJustPressed(MouseButtons button) {
    return mousebuttons_down[static_cast<int>(button)] == true && previous_mousebuttons_down[static_cast<int>(button)] == false;
}

bool CS230::Input::MouseButtonJustReleased(MouseButtons button) {
    return mousebuttons_down[static_cast<int>(button)] == false && previous_mousebuttons_down[static_cast<int>(button)] == true;
}
