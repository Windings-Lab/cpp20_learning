export module SpaceShip;

import <compare>;
import <iostream>;
import <concepts>;

export class MyInt
{
public:
    MyInt(int Num) : mNum(Num) {}

    auto operator<=>(const MyInt&) const = default;
    
private:
    int mNum;
    
};

export class MyPointer
{
public:
    explicit MyPointer(void* pointer) : mPointer(pointer) {}

    auto operator<=>(const MyPointer&) const = default;
    
private:
    void* mPointer;
    
};

export template <typename T>
constexpr void Checker(const T& lhs, const T& rhs)
{
    std::cout << std::boolalpha;

    std::cout << "===========================================\n";
    
    bool tester = lhs < rhs;
    std::cout << "lhs < rhs: " << tester << "\n";
    tester = lhs <= rhs;
    std::cout << "lhs <= rhs: " << tester << "\n";

    tester = lhs > rhs;
    std::cout << "lhs > rhs: " << tester << "\n";
    tester = lhs >= rhs;
    std::cout << "lhs >= rhs: " << tester << "\n";

    tester = lhs == rhs;
    std::cout << "lhs == rhs: " << tester << "\n";
    tester = lhs != rhs;
    std::cout << "lhs != rhs: " << tester << "\n";
    
    std::cout << "===========================================\n";
}
