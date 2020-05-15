#ifndef EUCLIDESLIMPIO_H
#define EUCLIDESLIMPIO_H
#include <iostream>
#include <stdlib.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

class EuclidesLimpio
{
    public:
        EuclidesLimpio();
        ZZ mcd1(ZZ a, ZZ b);
        ZZ mcd2(ZZ a, ZZ b);
        ZZ mcd3(ZZ a, ZZ b);
        ZZ mcd4(ZZ a, ZZ b);
        ZZ mcd5(ZZ a, ZZ b);
        ZZ mcd4_1(ZZ a, ZZ b);
        ZZ mcd5_1(ZZ a, ZZ b);
        ZZ mcd6(ZZ a, ZZ b);
        ZZ mcd7(ZZ a, ZZ b);

    private:
        ZZ modulo(ZZ dividendo, ZZ divisor);
};

#endif // EUCLIDES_H
