/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Engine.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes, Hankyung Lee
Created:    March 8, 2023
Updated:    March 20, 2023
*/
#pragma once
#include "Engine.h"

Engine::Engine() :
#ifdef _DEBUG				
    logger(CS230::Logger::Severity::Debug, true, last_tick)
#else 						
    logger(CS230::Logger::Severity::Event, false, last_tick)
#endif
{ }

Engine::~Engine() {}

void Engine::Start(std::string window_title) {
    logger.LogEvent("Engine Started");
    window.Start(window_title);
    //Start other services
    last_test = last_tick;
}

void Engine::Stop() {
    //Stop all services
    logger.LogEvent("Engine Stopped");
}

void Engine::Update() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    double dt = std::chrono::duration<double>(now - last_tick).count();

    if (dt > 1 / TargetFPS) {
        logger.LogVerbose("Engine Update");
        last_tick = now;

        ++frame_count;
        if (frame_count >= FPSTargetFrames) {
            double test_time = std::chrono::duration<double>(now - last_test).count();
            double FPS = frame_count / test_time;
            logger.LogDebug("FPS: " + std::to_string(FPS));
            frame_count = 0;
            last_test = now;
        }

        gamestatemanager.Update(dt);
        input.Update();
        window.Update();
        //Update other services
    }
}
bool Engine::HasGameEnded() {
    return gamestatemanager.HasGameEnded();
}