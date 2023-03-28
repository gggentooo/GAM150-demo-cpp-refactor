/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Mode2.cpp
Project:    CS230 Engine
Author:     Hankyung Lee
Created:    March 16, 2023
Updated:    March 21, 2023
*/

#include "../Engine/Engine.h"
#include "States.h"
#include "Mode2.h"

Mode2::Mode2() : ship({ static_cast<double>(Engine::GetWindow().GetSize().x) / 2, 
						static_cast<double>(Engine::GetWindow().GetSize().y) / 2 }) {}

void Mode2::Load() {
	ship.Load();
}

void Mode2::Update([[maybe_unused]] double dt) {
	ship.Update(dt);
	if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Enter)) {
        Engine::GetGameStateManager().ClearNextGameState();
	}
	if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::R)) {
		Engine::GetGameStateManager().ReloadGameState();
	}
}

void Mode2::Unload() {

}

void Mode2::Draw() {
	Engine::GetWindow().Clear(0x000000FF);
	ship.Draw();
}
