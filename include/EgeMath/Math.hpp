#pragma once

namespace EgeMath
{
    constexpr int MAX_ITERATION { 100 };
    constexpr float EPSILON { 0.0001f };

    int abs(int x);
    float fabs(float x);
    float sqrt(float x); //newton-raphson method
}