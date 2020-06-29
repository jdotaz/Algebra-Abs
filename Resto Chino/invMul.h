#include <iostream>
#include "Extendido.cpp"

int modulo(int dividendo,int divisor){
  int residuo=dividendo-(divisor*(dividendo/divisor));
  if (residuo<0){
    residuo+=divisor;
  }
  return residuo;
}

int mcd(int a,int b){
  if(b==0){
    return a;
  }
  return mcd(b,modulo(a,b));
}

int inversaMul(int _a,int _b){
  if(mcd(_a,_b)==1){
    Extendido inve(_a,_b);
    return modulo(inve.get_x(),_b);
  }
  return -1;
}
