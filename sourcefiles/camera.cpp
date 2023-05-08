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
#include "camera.h"

Camera::Camera(Math::vec2 player_zone_bottomleft, Math::vec2 player_zone_topright) : 
	player_zone_bottomleft(player_zone_bottomleft), player_zone_topright(player_zone_topright)
{

}
void Camera::SetPosition(Math::vec2 new_position)
{
	position = new_position;
}
void Camera::SetLimit(Math::vec2 new_limit_bottomleft, Math::vec2 new_limit_topright)
{
	limit_bottomleft = new_limit_bottomleft;
	limit_topright = new_limit_topright;
}
void Camera::Update(const Math::vec2& player_position)
{
    if (player_position.x > player_zone_topright.x + position.x) {
        position.x = player_position.x - player_zone_topright.x;
    }
    if (player_position.x - position.x < player_zone_bottomleft.x) {
        position.x = player_position.x - player_zone_bottomleft.x;
    }
    if (player_position.y > player_zone_topright.y + position.y) {
        position.y = player_position.y - player_zone_topright.y;
    }
    if (player_position.y - position.y < player_zone_bottomleft.y) {
        position.y = player_position.y - player_zone_bottomleft.y;
    }

    if (position.x < limit_bottomleft.x) {
        position.x = limit_bottomleft.x;
    }
    if (position.x > limit_topright.x) {
        position.x = limit_topright.x;
    }
    if (position.y < limit_bottomleft.y) {
        position.y = limit_bottomleft.y;
    }
    if (position.y > limit_topright.y) {
        position.y = limit_topright.y;
    }
}