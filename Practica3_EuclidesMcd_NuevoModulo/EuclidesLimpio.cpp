#include "EuclidesLimpio.h"

EuclidesLimpio::EuclidesLimpio()
{
}


ZZ EuclidesLimpio::modulo(ZZ dividendo,ZZ divisor){
  ZZ residuo=dividendo-(divisor*(dividendo/divisor));
  if (residuo<0){
    residuo+=divisor;
  }
  return residuo;
}

ZZ EuclidesLimpio::mcd1(ZZ a, ZZ b){
  while (true) {
    ZZ r=modulo(a,b);
    if(r==0){
      return b;
    }
    a=b;
    b=r;
  }
}

ZZ EuclidesLimpio::mcd2(ZZ a, ZZ b){
  while (true) {
    ZZ r=modulo(a,b);
    if(r==0){
      return b;
    }
    if(r>b/2){
      r=b-r;
    }
    a=b;
    b=r;
  }
}

ZZ EuclidesLimpio::mcd3(ZZ a,ZZ b){
  if(b==0){
    return a;
  }
  return mcd3(b,modulo(a,b));
}

ZZ EuclidesLimpio::mcd4(ZZ a,ZZ b){
  if (abs(b)>abs(a)) {
    return mcd4(b,a);
  }
  if (b==0) {
    return a;
  }
  if (modulo(a,ZZ(2))==0 and modulo(b,ZZ(2))==0) {
    return 2*mcd4(a/2,b/2);
  }
  if (modulo(a,ZZ(2))==0 and modulo(b,ZZ(2))!=0) {
    return mcd4(a/2,b);
  }
  if (modulo(a,ZZ(2))!=0 and modulo(b,ZZ(2))==0) {
    return mcd4(a,b/2);
  }
  return mcd4((abs(a)-abs(b))/2,b);
}

ZZ EuclidesLimpio::mcd5(ZZ a,ZZ b){
  if(a<0 or b<0){
    return ZZ(-1);
  }
  ZZ g=ZZ(1);

  while (modulo(a,ZZ(2))==0 and modulo(b,ZZ(2))==0) {
    a/=2;
    b/=2;
    g*=2;
  }
  while (a!=0) {
    while (modulo(a,ZZ(2))==0) {
      a/=2;
    }
    while (modulo(b,ZZ(2))==0) {
      b/=2;
    }
    ZZ t=abs(a-b)/2;
    if (a>=b){
      a=t;
    }else{
      b=t;
    }
  }
  return g*b;
}


ZZ EuclidesLimpio::mcd4_1(ZZ a,ZZ b){
  if (abs(b)>abs(a)) {
    return mcd4(b,a);
  }
  if (b==0) {
    return a;
  }
  if ((a&1)==0 and (b&1)==0) {
    return mcd4(a>>1,b>>1)<<1;
  }
  if ((a&1)==0 and (b&1)!=0) {
    return mcd4(a>>1,b);
  }
  if ((a&1)!=0 and (b&1)==0) {
    return mcd4(a,b>>1);
  }
  return mcd4((abs(a)-abs(b))>>1,b);
}//Con operaciones bitwise

ZZ EuclidesLimpio::mcd5_1(ZZ a,ZZ b){
  if(a<0 or b<0){
    return ZZ(-1);
  }
  int g=0;

  while ((a&1)==0 and (b&1)==0) {
    a=a>>1;
    b=b>>1;
    g++;
  }
  while (a!=0) {
    while ((a&1)==0) {
      a=a>>1;
    }
    while ((b&1)==0) {
      b=b>>1;
    }
    ZZ t=abs(a-b)>>1;
    if (a>=b){
      a=t;
    }else{
      b=t;
    }
  }
  return b<<g;
}//Con operaciones bitwise


ZZ EuclidesLimpio::mcd6(ZZ a,ZZ b){
  while (a!=b) {
    if (a>b){
      a=a-b;
    }else{
      b=b-a;
    }
  }
  return a;
}

ZZ EuclidesLimpio::mcd7(ZZ a,ZZ b){
  ZZ r=modulo(a,b);
  if(r==0){
    return(b);
  }
  return mcd7(b,r);
}
