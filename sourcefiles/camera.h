/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Camera.h
Project:    CS230 Engine
Author:     Jonathan Holmes, Hankyung Lee
Created:    March 8, 2023
Updated:    April 7, 2023
*/

#pragma once
#include "Vec2.h"

class Camera {
public:
    Camera(Math::vec2 player_zone_bottomleft, Math::vec2 player_zone_topright);
    void SetPosition(Math::vec2 new_position);
    const Math::vec2& GetPosition() const { return position; }
    void SetLimit(Math::vec2 new_limit_bottomleft, Math::vec2 new_limit_topright);
    void Update(const Math::vec2& player_position);
private:
    Math::vec2 limit_bottomleft;
    Math::vec2 limit_topright;

    Math::vec2 position;

    Math::vec2 player_zone_bottomleft;
    Math::vec2 player_zone_topright;
};