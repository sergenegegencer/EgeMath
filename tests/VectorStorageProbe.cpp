#include <iostream>
#include <vector>

#include <EgeMath/Vec2.hpp>

using namespace EgeMath;

int main()
{
    std::vector<Vec2> vectors;

    std::cout << "Initial\n";
    std::cout << "Size: " << vectors.size() << '\n';
    std::cout << "Capacity: " << vectors.capacity() << "\n\n";

    for(int i { 0 }; i < 5; i++)
    {
        vectors.push_back(Vec2(static_cast<float>(i), static_cast<float>(i)));

        std::cout << "After push_back\n";
        std::cout << "Size: " << vectors.size() << '\n';
        std::cout << "Capacity: " << vectors.capacity() << '\n';
        std::cout << "First element address: " << &vectors[0] << "\n\n";
    }

    std::cout << "Contiguous storage check\n";

    for(std::size_t i { 0 }; i < vectors.size(); i++)
    {
        std::cout << i << ": " << &vectors[i] << '\n';
    }

    std::cout << "\nReserve Test\n";

    std::vector<Vec2> reservedVectors;

    reservedVectors.reserve(100);

    std::cout << "Size: " << reservedVectors.size() << '\n';

    std::cout << "Capacity: " << reservedVectors.capacity() << '\n';

    std::vector<Vec2> values;
    values.reserve(2);

    values.push_back(Vec2{1.0f, 1.0f});
    values.push_back(Vec2{2.0f, 2.0f});

    Vec2* oldPointer = &values[0];

    std::cout << "\nBefore reallocation: " << oldPointer << '\n';

    values.push_back(Vec2{3.0f, 3.0f});

    std::cout << "After reallocation:  " << &values[0] << '\n';

    return 0;
}