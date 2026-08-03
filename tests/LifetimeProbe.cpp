#pragma once

#include <iostream>

class LifetimeProbe
{
    public:
        LifetimeProbe()
        {
            std::cout << "Constructor\n";
        }

        LifetimeProbe(const LifetimeProbe& other)
        {
            std::cout << "Copy Constructor\n";
        }

        LifetimeProbe& operator=(const LifetimeProbe& other)
        {
            std::cout << "Copy Assignment\n";

            return *this;
        }

        LifetimeProbe(LifetimeProbe&&) //&& = rvalue reference
        {
            std::cout << "Move Constructor\n";
        }

        // && kullaninca parametrenin turu rvalue reference olur. 
        // Bu, fonksiyona gelen objenin kaynaklarinin tasinmasina izin verilebilecegini belirtir.

        LifetimeProbe& operator=(LifetimeProbe&&) 
        {
            std::cout << "Move Assignment\n";

            return *this;
        }

        ~LifetimeProbe()
        {
            std::cout << "Destructor\n";
        }
};

int main()
{
    LifetimeProbe a;

    LifetimeProbe b = a;

    LifetimeProbe c = std::move(a);

    b = c;

    c = std::move(b);

    return 0;
}