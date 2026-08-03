#pragma once

#include <iostream>

class LifetimeProbe
{
    private:
        inline static int nextID { 0 };
        //static, bir degiskeni bildirir ama ayri bir yerde tanımlamak gerekir
        //inline static ise header icinde degiskeni bildirip ayrica tanimlanabilir
        int id;

    public:
        LifetimeProbe() : id(nextID++)
        {
            std::cout << "Constructor: " << id << '\n';
        }

        LifetimeProbe(int _id) : id(_id)
        {
            std::cout << "Constructor: " << id << '\n';
        }

        LifetimeProbe(const LifetimeProbe& other) : id(nextID++)
        {
            std::cout << "Copy Constructor: " << id << '\n';
        }

        LifetimeProbe& operator=(const LifetimeProbe& other)
        {
            if(this == &other) return *this;

            std::cout << "Copy Assignment: " << id << '\n';

            return *this;
        }

        LifetimeProbe(LifetimeProbe&& other) : id(nextID++) //&& = rvalue reference
        {
            std::cout << "Move Constructor: " << id << " from " << other.id << '\n';
        }

        // && kullaninca parametrenin turu rvalue reference olur. 
        // Bu, fonksiyona gelen objenin kaynaklarinin tasinmasina izin verilebilecegini belirtir.

        LifetimeProbe& operator=(LifetimeProbe&& other) 
        {
            std::cout << "Move Assignment: " << id << " from " << other.id << '\n';

            return *this;
        }

        ~LifetimeProbe()
        {
            std::cout << "Destructor: " << id << '\n';
            nextID--;
        }
};

void passByValue(LifetimeProbe obj)
{
    std::cout << "Inside passByValue\n";
}

void passByReference(LifetimeProbe& obj)
{
    std::cout << "Inside passByReference\n";
}

void passByConstReference(const LifetimeProbe& obj)
{
    std::cout << "Inside passByConstReference\n";
}

int main()
{
    LifetimeProbe a;

    std::cout << "\n--- Pass by value ---\n";
    passByValue(a);

    std::cout << "\n--- Pass by reference ---\n";
    passByReference(a);

    std::cout << "\n--- Pass by const reference ---\n";
    passByConstReference(a);


    std::cout << "\n\n\n--- Move construction ---\n";

    LifetimeProbe b = std::move(a);

    LifetimeProbe x;
    LifetimeProbe y;

    y = x;

    y = std::move(x);

    return 0;
}