/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Asteroid.h
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

#pragma once
#include "..\Engine\Sprite.h"
#include "..\Engine\Vec2.h"

class Asteroid {
public:
    Asteroid(Math::vec2 start_position);
    void Load();
    void Update(double dt);
    void Draw();

private:
    CS230::Sprite sprite;
    Math::vec2 start_position;
    Math::vec2 position;
    Math::vec2 velocity;

    static constexpr double bounce_velocity = 500;
};

