/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Texture.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/
#include <doodle/drawing.hpp>
#include "Texture.h"

CS230::Texture::Texture() {}

void CS230::Texture::Load(const std::filesystem::path& file_path) {
    image = doodle::Image{ file_path };
}

void CS230::Texture::Draw(Math::vec2 location) {
    doodle::draw_image(image, location.x, location.y);
}

Math::ivec2 CS230::Texture::GetSize() {
    return {
        image.GetWidth(), image.GetHeight()
    };
}
