/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Splash.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes, Hankyung Lee
Created:    March 8, 2023
Updated:    March 21, 2023
*/

#include "../Engine/Engine.h"
#include "States.h"
#include "Splash.h"

Splash::Splash() {

}

void Splash::Load() {
    counter = 0.0;
    texture.Load("Assets/DigiPen.png");
}

void Splash::Update(double dt) {
    Engine::GetLogger().LogDebug(std::to_string(counter));
    if (counter >= 3) {
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Mode1));
    }
    counter += dt;
}

void Splash::Unload() {

}

void Splash::Draw() {
    Engine::GetWindow().Clear(UINT_MAX);
    texture.Draw({ (Engine::GetWindow().GetSize() - texture.GetSize()) / 2.0 });
}
