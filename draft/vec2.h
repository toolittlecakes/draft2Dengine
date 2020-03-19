
#ifndef DRAFT_VEC2_H
#define DRAFT_VEC2_H

#include <math.h>

struct Vec2 {
    float x = 0.f;
    float y = 0.f;

    Vec2() = default;

    Vec2(float _x, float _y) : x(_x), y(_y) {}

    Vec2 operator+(Vec2 other) { return Vec2{x + other.x, y + other.y}; }

    Vec2 operator-(Vec2 other) { return Vec2{x - other.x, y - other.y}; }

    Vec2& operator+=(Vec2 other) { x+= other.x; y += other.y; return *this;}

    Vec2& operator-=(Vec2 other) { x-= other.x; y -= other.y; return *this;}

    float dot(Vec2 other) { return sqrtf(x * other.x +  y * other.y + 1e-3f); }

    Vec2 operator*(float factor) { return Vec2{x * factor, y * factor};}

    Vec2 operator/(float factor) { return Vec2{x / factor, y / factor};}

    Vec2 norm() {float len = 1e-3f + this->abs(); return Vec2{x / len, y / len};}

    float abs() { return this->dot(*this);}


    Vec2 operator-(){return Vec2{-x, -y};}
};

#endif //DRAFT_VEC2_H
