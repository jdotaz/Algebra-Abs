#ifndef EUCLIDES_H
#define EUCLIDES_H
#include <iostream>
#include <stdlib.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

class Euclides
{
    public:
        Euclides();
        ZZ mcd1(ZZ a, ZZ b);
        ZZ mcd2(ZZ a, ZZ b);
        ZZ mcd3(ZZ a, ZZ b,int paso=0);
        ZZ mcd4(ZZ a, ZZ b,int paso=0);
        ZZ mcd5(ZZ a, ZZ b);
        ZZ mcd6(ZZ a, ZZ b);
        ZZ mcd7(ZZ a, ZZ b,int paso=0);

    private:
        ZZ modulo(ZZ dividendo, ZZ divisor);
};

#endif // EUCLIDES_H
