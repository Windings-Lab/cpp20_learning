module;

#include <concepts>
#include <iostream>

export module custom_math;

export namespace WD::Math
{
    int add(int a, int b);
}

export template<typename T>
requires std::integral<T>
std::integral auto gcd1(T a, T b)
{
    std::cout << a << " " << b << "\n";
    if( b == 0 ) return a;
    
    return gcd1(b, a % b);
}

export std::integral auto gcd2(std::integral auto a, std::integral auto b)
{
    std::cout << a << " " << b << "\n";
    if( b == 0 ) return a;

    return gcd2(b, a % b);
}