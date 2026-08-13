#include <EgeMath/Math.hpp>
#include <limits>

int EgeMath::abs(int x)
{
    return (x >= 0) ? x : -x;
}

float EgeMath::fabs(float x)
{
    return (x >= 0) ? x : -x;
}

float EgeMath::sqrt(float x)
{
    if(x < 0) return std::numeric_limits<float>::quiet_NaN();
    if(x == 0) return 0;

    float guess;

    if(x <= 1) guess = 1;

    else
    {
        guess = x / 2;
    }

    for(int i = 0; i < MAX_ITERATION; i++)
    {
        float newGuess = 0.5 * (guess + x / guess);

        if(fabs(newGuess - guess) < EPSILON)
        {
            guess = newGuess;
            break;
        }

        guess = newGuess;
    }

    return guess;
}