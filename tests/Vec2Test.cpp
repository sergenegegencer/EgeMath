#include <cassert>
#include <cmath>
#include <iostream>

#include <EgeMath/Vec2.hpp>

using namespace EgeMath;

int main()
{
    // Constructor test
    Vec2 v1(3.0f, 4.0f);

    assert(v1.x == 3.0f);
    assert(v1.y == 4.0f);


    // Addition test
    Vec2 v2(1.0f, 2.0f);

    Vec2 sum = v1 + v2;

    assert(sum.x == 4.0f);
    assert(sum.y == 6.0f);


    // Subtraction test
    Vec2 difference = v1 - v2;

    assert(difference.x == 2.0f);
    assert(difference.y == 2.0f);


    // Unary minus test
    Vec2 negative = -v1;

    assert(negative.x == -3.0f);
    assert(negative.y == -4.0f);


    // Scalar multiplication test
    Vec2 scaled = v1 * 2.0f;

    assert(scaled.x == 6.0f);
    assert(scaled.y == 8.0f);


    // Scalar division test
    Vec2 divided = v1 / 2.0f;

    assert(divided.x == 1.5f);
    assert(divided.y == 2.0f);


    // Compound addition test
    Vec2 addAssign(1.0f, 2.0f);

    addAssign += v2;

    assert(addAssign.x == 2.0f);
    assert(addAssign.y == 4.0f);


    // Compound subtraction test
    Vec2 subAssign(5.0f, 5.0f);

    subAssign -= v2;

    assert(subAssign.x == 4.0f);
    assert(subAssign.y == 3.0f);


    // LengthSquared test
    Vec2 lengthVector(3.0f, 4.0f);

    assert(lengthVector.lengthSquared() == 25.0f);


    // Length test
    assert(lengthVector.length() == 5.0f);


    // Division by zero test
    Vec2 invalid = v1 / 0.0f;

    assert(std::isnan(invalid.x));
    assert(std::isnan(invalid.y));

    // Aynı yön
    Vec2 a{1.0f, 0.0f};
    Vec2 b{3.0f, 0.0f};

    assert(a.Dot(b) == 3.0f);

    // Dik
    Vec2 c{1.0f, 0.0f};
    Vec2 d{0.0f, 4.0f};

    assert(c.Dot(d) == 0.0f);

    // Zıt yön
    Vec2 e{1.0f, 0.0f};
    Vec2 f{-2.0f, 0.0f};

    assert(e.Dot(f) == -2.0f);

    assert(a.Dot(b) == b.Dot(a));

    std::cout << "All Vec2 tests passed!\n";

    return 0;
}