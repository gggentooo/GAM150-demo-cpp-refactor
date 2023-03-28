/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Cat.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

#pragma once
#include "Ship.h"
#include "../Engine/Engine.h"

Ship::Ship(Math::vec2 start_position) :
    start_position(start_position),
    position(start_position),
    velocity({ 0, 0 })
{}

void Ship::Load() {
    sprite.Load("Assets/Ship.png", { 0, 0 });
    velocity = { 0,0 };
}

void Ship::Update(double dt) {
    if (Engine::GetInput().KeyDown(CS230::Input::Keys::W)) {
        velocity.y += speed * dt;
    }
    if (Engine::GetInput().KeyDown(CS230::Input::Keys::A)) {
        velocity.x -= speed * dt;
    }
    if (Engine::GetInput().KeyDown(CS230::Input::Keys::S)) {
        velocity.y -= speed * dt;
    }
    if (Engine::GetInput().KeyDown(CS230::Input::Keys::D)) {
        velocity.x += speed * dt;
    }

    velocity -= velocity * drag * dt;

    Engine::GetLogger().LogDebug("Velocity: " + std::to_string(velocity.x) + ", " + std::to_string(velocity.y));

    position += velocity * dt;

    //Test for wrap, here
    if (position.x < 0 - sprite.GetTextureSize().x) {
        position.x = Engine::GetWindow().GetSize().x + sprite.GetTextureSize().x / 2;
    }
    if (position.x > Engine::GetWindow().GetSize().x + sprite.GetTextureSize().x / 2) {
        position.x = 0 - sprite.GetTextureSize().x;
    }
    if (position.y < 0 - sprite.GetTextureSize().y) {
        position.y = Engine::GetWindow().GetSize().y + sprite.GetTextureSize().y / 2;
    }
    if (position.y > Engine::GetWindow().GetSize().y + sprite.GetTextureSize().y / 2) {
        position.y = 0 - sprite.GetTextureSize().y;
    }
}

void Ship::Draw() {
    sprite.Draw(position);
}
