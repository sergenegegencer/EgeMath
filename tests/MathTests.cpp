#include <cassert>
#include <cmath>
#include <iostream>

#include <EgeMath/Math.hpp>

using namespace EgeMath;

int main()
{
    constexpr float TEST_EPSILON = 0.0001f;


    // Square root - zero
    assert(EgeMath::sqrt(0.0f) == 0.0f);


    // Square root - one
    assert(EgeMath::sqrt(1.0f) == 1.0f);


    // Square root - perfect square
    assert(EgeMath::sqrt(4.0f) == 2.0f);


    // Square root - irrational number
    assert(
        EgeMath::fabs(EgeMath::sqrt(2.0f) - 1.4142135f)
        < TEST_EPSILON
    );


    // Square root - value between 0 and 1
    assert(
        EgeMath::fabs(EgeMath::sqrt(0.25f) - 0.5f)
        < TEST_EPSILON
    );


    // Square root - negative value
    assert(std::isnan(EgeMath::sqrt(-1.0f)));


    // Absolute value - positive
    assert(EgeMath::fabs(5.0f) == 5.0f);


    // Absolute value - negative
    assert(EgeMath::fabs(-5.0f) == 5.0f);


    // Absolute value - zero
    assert(EgeMath::fabs(0.0f) == 0.0f);
    

    std::cout << "All Math tests passed!\n";

    return 0;
}