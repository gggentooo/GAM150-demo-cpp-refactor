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
#include "Cat.h"
#include "Mode1.h"
#include "../Engine/Engine.h"

Cat::Cat(Math::vec2 start_position) :
    start_position(start_position),
    position(start_position)
{}

void Cat::Load() {
    sprite.Load("Assets/Cat.png", { 64, 15 });
    velocity = { 0, 0 };
    position = { start_position };
    jumping = false;
    going_up = false;
}

void Cat::Update(double dt) {
    /* Left - and - right movement-----------------------------------*/
    if (Engine::GetInput().KeyDown(CS230::Input::Keys::Left)) {
        if (velocity.x <= 0) {
            velocity.x -= x_acceleration;
            Engine::GetLogger().LogDebug("Accelerating to the left");
            if (velocity.x <= -max_velocity) {
                velocity.x = -max_velocity;
                Engine::GetLogger().LogDebug("Reached maximum velocity to the left");
            }
        }
        else { // skidding
            velocity.x -= x_drag * 2;
            Engine::GetLogger().LogDebug("Skidding to the left");
        }
        did_log_Stopped = false;
    }
    else if (Engine::GetInput().KeyDown(CS230::Input::Keys::Right)) {
        if (velocity.x >= 0) {
            velocity.x += x_acceleration;
            Engine::GetLogger().LogDebug("Accelerating to the right");
            if (velocity.x >= max_velocity) {
                velocity.x = max_velocity;
                Engine::GetLogger().LogDebug("Reached maximum velocity to the right");
            }
        }
        else { // skidding
            velocity.x += x_drag * 2;
            Engine::GetLogger().LogDebug("Skidding to the right");
        }
        did_log_Stopped = false;
    }
    else { // neither keys being pressed
        if (velocity.x >= x_drag) {
            velocity.x -= x_drag;
            Engine::GetLogger().LogDebug("Dragging while moving to the right");
        } else if (velocity.x <= -x_drag) {
            velocity.x += x_drag;
            Engine::GetLogger().LogDebug("Dragging while moving to the left");
        }
        else { // -drag < velocity.x < drag
            velocity.x = 0;
            if (!did_log_Stopped) {
                Engine::GetLogger().LogDebug("Stopped");
                did_log_Stopped = true;
            }
        }
    }
    /*---------------------------------------------------------------*/

    /* Jumping ------------------------------------------------------*/
    if (jumping) {
        velocity.y -= Mode1::gravity * dt;
        if (going_up && !Engine::GetInput().KeyDown(CS230::Input::Keys::Up)) {
            Engine::GetLogger().LogDebug("Released Jump Early: " + std::to_string(position.y));
            velocity.y = 0;
            going_up = false;
        }
        if (going_up && velocity.y < 0) {
            Engine::GetLogger().LogDebug("Max Height: " + std::to_string(position.y));
            going_up = false;
        }
    }

    if (Engine::GetInput().KeyDown(CS230::Input::Keys::Up) && position.y == Mode1::floor) {
        velocity.y = jump_velocity;
        jumping = true;
        going_up = true;
        Engine::GetLogger().LogDebug("Starting Jump: " + std::to_string(position.y));
    }
    /*---------------------------------------------------------------*/

    position += velocity * dt;

    if (jumping && (position.y <= Mode1::floor)) {
        velocity.y = 0;
        position.y = Mode1::floor;
        jumping = false;
        Engine::GetLogger().LogDebug("Landing: " + std::to_string(position.y));
    } // Stop falling when cat hits floor
}

void Cat::Draw() {
    sprite.Draw(position);
}
