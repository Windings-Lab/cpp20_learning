export module Tester:SpaceShip;

import SpaceShip;

export namespace spaceShip
{
    void Tester()
    {
        MyInt myInt2014(2014);
        MyInt myInt2012(2012);
    
        MyPointer ptr1(&myInt2012);
        MyPointer ptr2(&myInt2014);
    
        Checker(myInt2012, myInt2014);
        Checker(ptr1, ptr2);
    }
}
