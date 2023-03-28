/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Mode1.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

#include "../Engine/Engine.h"
#include "States.h"
#include "Mode1.h"

Mode1::Mode1() : cat({ 300, floor }), asteroid({ 500, floor }) { }

void Mode1::Load() {
    background.Load("Assets/Background.png");
    cat.Load();
    asteroid.Load();
}

void Mode1::Update(double dt) {
    cat.Update(dt);
    asteroid.Update(dt);
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Enter)) {
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Mode2));
    }
    if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::R)) {
        Engine::GetGameStateManager().ReloadGameState();
    }
}

void Mode1::Draw() {
    Engine::GetWindow().Clear(0x00F0F0FF);

    background.Draw({ 0, 0 });
    cat.Draw();
    asteroid.Draw();
}

void Mode1::Unload() { }