/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Vec2.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes, Hankyung Lee
Created:    March 8, 2023
Updated:    March 20, 2023
*/

#include "Vec2.h"
#include <math.h>

/* vec2------------------------------------------- */

bool Math::vec2::operator==(const vec2& v) {
    return ( (x == v.x) && (y == v.y) );
}

bool Math::vec2::operator!=(const vec2& v) {
    return ( (x != v.x) || (y != v.y) );
}

Math::vec2 Math::vec2::operator+(const vec2& v) {
    return { x + v.x, y + v.y };
}

Math::vec2& Math::vec2::operator+=(const vec2& v) {
    x += v.x;
    y += v.y;
    return *this;
}

Math::vec2 Math::vec2::operator-(const vec2& v) {
    return { x - v.x, y - v.y };
}

Math::vec2& Math::vec2::operator-=(const vec2& v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

Math::vec2 Math::vec2::operator*(double scale) {
    return { x * scale, y * scale };
}

Math::vec2& Math::vec2::operator*=(double scale) {
    x *= scale;
    y *= scale;
    return *this;
}

Math::vec2 Math::vec2::operator/(double divisor) {
    return { x / divisor, y / divisor };
}

Math::vec2& Math::vec2::operator/=(double divisor) {
    x /= divisor;
    y /= divisor;
    return *this;
}

double Math::vec2::magnitude() {
    return sqrt(pow(x, 2) + pow(y, 2));
}

/* ivec2------------------------------------------ */

bool Math::ivec2::operator==(const ivec2& v) {
    return ((x == v.x) && (y == v.y));
}

bool Math::ivec2::operator!=(const ivec2& v) {
    return ((x != v.x) || (y != v.y));
}

Math::ivec2 Math::ivec2::operator+(const ivec2& v) {
    return { x + v.x, y + v.y };
}

Math::ivec2& Math::ivec2::operator+=(const ivec2& v) {
    x += v.x;
    y += v.y;
    return *this;
}

Math::ivec2 Math::ivec2::operator-(const ivec2& v) {
    return { x - v.x, y - v.y };
}

Math::ivec2& Math::ivec2::operator-=(const ivec2& v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

Math::ivec2 Math::ivec2::operator*(int scale) {
    return { x * scale, y * scale };
}

Math::ivec2& Math::ivec2::operator*=(int scale) {
    x *= scale;
    y *= scale;
    return *this;
}

Math::ivec2 Math::ivec2::operator/(int divisor) {
    return { static_cast<int>(x / divisor), static_cast<int>(y / divisor) };
}

Math::ivec2& Math::ivec2::operator/=(int divisor) {
    static_cast<int>(x /= divisor);
    static_cast<int>(y /= divisor);
    return *this;
}

Math::vec2 Math::ivec2::operator*(double scale) {
    return { x * scale, y * scale };
}

Math::vec2 Math::ivec2::operator/(double divisor) {
    return { x / divisor, y / divisor };
}

int Math::ivec2::magnitude() {
    return sqrt(pow(x, 2) + pow(y, 2));
}

/* operations------------------------------------------ */

double Math::cross_product(vec2 v1, vec2 v2) {
    // idk lol
    return 0;

}

double Math::dot_product(vec2 v1, vec2 v2) {

    return (v1.x * v2.x + v1.y * v2.y);

}

double Math::angle_between(vec2 v1, vec2 v2) {

    return (acos(dot_product(v1, v2) / (v1.magnitude() * v2.magnitude())));

}