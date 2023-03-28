/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Cat.h
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

#pragma once
#include "..\Engine\Sprite.h"
#include "..\Engine\Input.h"
#include "..\Engine\Vec2.h"

class Cat {
public:
    Cat(Math::vec2 start_position);
    void Load();
    void Update(double dt);
    void Draw();

private:
    CS230::Sprite sprite;
    Math::vec2 start_position;
    Math::vec2 position;
    Math::vec2 velocity;

    static constexpr double x_acceleration = 12;
    static constexpr double x_drag = 15;
    static constexpr double max_velocity = 320;

    bool did_log_Stopped = false;

    bool jumping = false;
    bool going_up = false;
    static constexpr double jump_velocity = 650;
};
