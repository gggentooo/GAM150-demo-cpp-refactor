/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Texture.h
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/
#pragma once
#include <doodle/image.hpp>
#include "Vec2.h"

namespace CS230 {
    class Texture {
    public:
        Texture();
        void Load(const std::filesystem::path& file_path);
        void Draw(Math::vec2 location);
        Math::ivec2 GetSize();
    private:
        doodle::Image image;
    };
}
