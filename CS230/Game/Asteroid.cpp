/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Asteroid.cpp
Project:    CS230 Engine
Author:     Hankyung Lee
Created:    March 27, 2023
*/

#pragma once
#include "Mode1.h"
#include "Asteroid.h"
#include "../Engine/Engine.h"

Asteroid::Asteroid(Math::vec2 start_position) :
    start_position(start_position),
    position(start_position)
{}

void Asteroid::Load() {
    sprite.Load("Assets/Asteroid.png", { 70, 3 });
    velocity = { 0, 0 };
    position = { start_position };
}

void Asteroid::Update(double dt) {
    velocity.y -= Mode1::gravity * dt;
    position += velocity * dt;

    if (position.y < Mode1::floor) {
        position.y = Mode1::floor;
        velocity.y = bounce_velocity;
    }
}

void Asteroid::Draw() {
    sprite.Draw(position);
}
