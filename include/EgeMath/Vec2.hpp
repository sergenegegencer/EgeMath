#pragma once

namespace EgeMath
{
    struct Vec2
    {
        float x, y;

        Vec2(float x = 0.0f, float y = 0.0f);

        Vec2 operator+(const Vec2& other) const;
        Vec2 operator-(const Vec2& other) const;
        Vec2 operator-() const;

        Vec2 operator*(float scalar) const;
        Vec2 operator/(float scalar) const;

        Vec2& operator+=(const Vec2& other);
        Vec2& operator-=(const Vec2& other);

        float lengthSquared() const;
        float length() const;

        float Dot(const Vec2& other) const;

        Vec2 Normalized() const;
    };
}