#include <EgeMath/Vec2.hpp>
#include <EgeMath/Math.hpp>
#include <limits>

namespace EgeMath
{
    Vec2::Vec2(float _x, float _y) : x(_x), y(_y) {}

    Vec2 Vec2::operator+(const Vec2& other) const
    {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 Vec2::operator-(const Vec2& other) const
    {
        return Vec2(x - other.x, y - other.y);
    }

    Vec2 Vec2::operator-() const
    {
        return Vec2(-x, -y);
    }

    Vec2 Vec2::operator*(float scalar) const
    {
        return Vec2(x * scalar, y * scalar);
    }

    Vec2 Vec2::operator/(float scalar) const
    {
        if(scalar == 0.0f)
        {
            float nan { std::numeric_limits<float>::quiet_NaN() };
            return Vec2(nan, nan);
        }

        return Vec2(x / scalar, y / scalar);
    }

    Vec2& Vec2::operator+=(const Vec2& other)
    {
        if(this == &other) return *this;

        x += other.x;
        y += other.y;

        return *this;
    }

    Vec2& Vec2::operator-=(const Vec2& other)
    {
        if(this == &other) return *this;

        x -= other.x;
        y -= other.y;

        return *this;
    }

    float Vec2::lengthSquared() const
    {
        return x * x + y * y;
    }

    float Vec2::length() const
    {
        return EgeMath::sqrt(x * x + y * y);
    }

    float Vec2::Dot(const Vec2& other) const
    {
        return x * other.x + y * other.y;
    }

    Vec2 Vec2::Normalized() const
    {
        if(lengthSquared() == 0.0f) return Vec2(0.0f, 0.0f);
        return *this / length();
    }
}