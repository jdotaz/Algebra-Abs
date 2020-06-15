#include <iostream>
#include "Extendido.cpp"

long long modulo(long long dividendo,long long divisor){
  long long residuo=dividendo-(divisor*(dividendo/divisor));
  if (residuo<0){
    residuo+=divisor;
  }
  return residuo;
}

long long mcd(long long a,long long b){
  if(b==0){
    return a;
  }
  return mcd(b,modulo(a,b));
}

long long invMul(long long _a,long long _b){
  if(mcd(_a,_b)==1){
    Extendido inve(_a,_b);
    return modulo(inve.get_x(),_b);
  }
  return -1;
}
