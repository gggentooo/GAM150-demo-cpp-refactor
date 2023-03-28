/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Sprite.cpp
Project:    CS230 Engine
Author:     Hankyung Lee
Created:    March 21, 2023
*/

#include "Sprite.h"

CS230::Sprite::Sprite() {
	hotspot.x = 0;
	hotspot.y = 0;
}

void CS230::Sprite::Load(const std::filesystem::path& texture_path) {
	texture.Load(texture_path);
}

void CS230::Sprite::Load(const std::filesystem::path& texture_path, Math::ivec2 hotspot_position) {
	texture.Load(texture_path);
	hotspot.x = hotspot_position.x;
	hotspot.y = hotspot_position.y;
}

void CS230::Sprite::Draw(Math::vec2 position) {
	texture.Draw(position);
}

Math::ivec2 CS230::Sprite::GetTextureSize() {
	return texture.GetSize();
}