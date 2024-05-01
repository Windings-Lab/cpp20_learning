export module concept_test;

import <concepts>;
import <iostream>;


export namespace concept_test
{
    int add(int a, int b);
}

export template <typename T>
struct Vector
{
    Vector() {
        std::cout << "Vector<T>" << '\n';
    }
};

export template <std::regular Reg>
struct Vector<Reg>
{
    Vector()
    {
        std::cout << "Vector<std::regular>" << '\n';
    }
};
