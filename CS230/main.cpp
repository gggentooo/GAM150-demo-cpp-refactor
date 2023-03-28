/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  main.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes, Hankyung Lee
Created:    March 8, 2023
Updated:    March 20, 2023
*/

#include "Engine/Engine.h"
#include "Engine/Vec2.h"
#include "Game/Splash.h"
#include "Game/Mode1.h"
#include "Game/Mode2.h"

int main() {
    Engine& engine = Engine::Instance();
    engine.Start("Assignment 3 - hankyung.lee@digipen.edu");

    Splash splash;
    engine.GetGameStateManager().AddGameState(splash);
    Mode1 mode1;
    engine.GetGameStateManager().AddGameState(mode1);
    Mode2 mode2;
    engine.GetGameStateManager().AddGameState(mode2);

    while (engine.HasGameEnded() == false) {
        engine.Update();
    }
    engine.Stop();

    return 0;
}
