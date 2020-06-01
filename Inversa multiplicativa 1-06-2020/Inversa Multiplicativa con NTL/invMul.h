#include <iostream>
#include <NTL/ZZ.h>
#include "Extendido.cpp"

using namespace std;
using namespace NTL;

ZZ modulo(ZZ dividendo,ZZ divisor){
  ZZ residuo=dividendo-(divisor*(dividendo/divisor));
  if (residuo<0){
    residuo+=divisor;
  }
  return residuo;
}

ZZ mcd(ZZ a,ZZ b){
  if(b==0){
    return a;
  }
  return mcd(b,modulo(a,b));
}

ZZ inversaMul(ZZ _a,ZZ _b){
  if(mcd(_a,_b)==1){
    Extendido inve(_a,_b);
    return modulo(inve.get_x(),_b);
  }
  return -1;
}
