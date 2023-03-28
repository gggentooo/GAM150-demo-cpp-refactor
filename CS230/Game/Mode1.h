/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Mode1.h
Project:    CS230 Engine
Author:     Hankyung Lee
Created:    March 16, 2023
Updated:    March 21, 2023
*/

#pragma once
#include "../Engine/GameState.h"
#include "../Engine/Sprite.h"
#include "Cat.h"
#include "Asteroid.h"

class Mode1 : public CS230::GameState {
public:
    Mode1();
    void Load() override;
    void Update(double dt) override;
    void Unload() override;
    void Draw() override;

    std::string GetName() override { return "Mode1"; }

    static constexpr double gravity = 800;
    static constexpr double floor = 80;
private:
    CS230::Texture background;
    Cat cat;
    Asteroid asteroid;
};
