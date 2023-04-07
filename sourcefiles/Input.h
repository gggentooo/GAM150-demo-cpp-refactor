/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Input.h
Project:    CS230 Engine
Author:     Jonathan Holmes, Hankyung Lee
Created:    March 8, 2023
*/

#pragma once
#include <vector>

namespace CS230 {
    class Input {
    public:
        enum class MouseButtons {
            Left, Right,
            Unknown
        };

        Input();
        void Update();

        void SetMouseButtonDown(MouseButtons button, bool value);
        //bool MouseButtonDown(MouseButtons button);
        bool MouseButtonDown(int button);
        bool MouseButtonJustPressed(MouseButtons button);
        bool MouseButtonJustReleased(MouseButtons button);
    private:
        // std::vector<bool> mousebuttons_down = {0, 0};
        // std::vector<bool> previous_mousebuttons_down = {0, 0};
        bool *mousebuttons_down  {new bool[2]};
        bool *previous_mousebuttons_down  {new bool[2]};

    };
}
