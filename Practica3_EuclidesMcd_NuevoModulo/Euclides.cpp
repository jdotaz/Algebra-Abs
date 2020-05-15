#include "Euclides.h"

Euclides::Euclides()
{
}


ZZ Euclides::modulo(ZZ dividendo,ZZ divisor){
  ZZ residuo=dividendo-(b*(dividendo/divisor));
  if (residuo<0){
    residuo+=divisor;
  }
  return residuo;
}

ZZ Euclides::mcd1(ZZ a, ZZ b){
  int paso=0;
  while (true) {
    ZZ r=modulo(a,b);
    paso++;
    cout<<"Paso "<<paso<<":"<<endl;
    cout<<"   "<<a<<"="<<a/b<<"("<<b<<")"<<"+"<<r<<endl;
    if(r==0){
      cout<<"Como el residuo=0 retornamos b="<<b<<endl;
      return b;
    }
    a=b;
    b=r;
  }
}

ZZ Euclides::mcd2(ZZ a, ZZ b){
  int paso=0;
  while (true) {
    ZZ r=modulo(a,b);
    paso++;
    cout<<"Paso "<<paso<<":"<<endl;
    cout<<"   "<<a<<"="<<a/b<<"("<<b<<")"<<"+"<<r<<endl;
    if(r==0){
      cout<<"Como el residuo=0 retornamos b="<<b<<endl;
      return b;
    }
    if(r>b/2){
      r=b-r;
    }
    a=b;
    b=r;
  }
}

ZZ Euclides::mcd3(ZZ a,ZZ b,int paso){
  if(b==0){
    cout<<"Como el b=0 retornamos a="<<a<<endl;
    return a;
  }
  paso++;
  cout<<"Paso "<<paso<<":"<<endl;
  cout<<"   a=b= "<<b<<endl<<"   b=a%b= "<<modulo(a,b)<<endl<<endl;
  return mcd3(b,modulo(a,b),paso);
}

ZZ Euclides::mcd4(ZZ a,ZZ b,int paso){
  if (abs(b)>abs(a)) {
    paso++;
    cout<<"Paso "<<paso<<":"<<endl;
    cout<<"   a=b= "<<b<<endl<<"   b=a= "<<a<<endl<<endl;
    return mcd4(b,a,paso);
  }
  if (b==0) {
    cout<<"Como b=0 retornamos a*(2n) donde n en la cantidad de veces que hicimos a/2 y b/2 en un mismo paso."<<endl;
    return a;
  }
  if (modulo(a,ZZ(2))==0 and modulo(b,ZZ(2))==0) {
    paso++;
    cout<<"Paso "<<paso<<":"<<endl;
    cout<<"   a=a/2= "<<a/2<<endl<<"   b=b/2= "<<b/2<<endl<<endl;
    return 2*mcd4(a/2,b/2,paso);
  }
  if (modulo(a,ZZ(2))==0 and modulo(b,ZZ(2))!=0) {
    paso++;
    cout<<"Paso "<<paso<<":"<<endl;
    cout<<"   a=a/2= "<<a/2<<endl<<"   b= "<<b<<endl<<endl;
    return mcd4(a/2,b,paso);
  }
  if (modulo(a,ZZ(2))!=0 and modulo(b,ZZ(2))==0) {
    paso++;
    cout<<"Paso "<<paso<<":"<<endl;
    cout<<"   a= "<<a<<endl<<"   b=b/2= "<<b/2<<endl<<endl;
    return mcd4(a,b/2,paso);
  }
  paso++;
  cout<<"Paso "<<paso<<":"<<endl;
  cout<<"   a=(a-b)/2= "<<(abs(a)-abs(b))/2<<endl<<"   b= "<<b<<endl<<endl;
  return mcd4((abs(a)-abs(b))/2,b,paso);
}

ZZ Euclides::mcd5(ZZ a,ZZ b){
  if(a<0 or b<0){
    return ZZ(-1);
  }
  ZZ g=ZZ(1);
  int paso=0;
  while (modulo(a,ZZ(2))==0 and modulo(b,ZZ(2))==0) {
    a/=2;
    b/=2;
    g*=2;
    paso++;
    cout<<"Paso "<<paso<<":"<<endl;
    cout<<"   a=a/2= "<<a<<endl<<"   b=b/2= "<<b<<endl<<endl;
  }
  while (a!=0) {
    while (modulo(a,ZZ(2))==0) {
      paso++;
      cout<<"Paso "<<paso<<":"<<endl;
      cout<<"   a=a/2= "<<a<<endl<<"   b= "<<b<<endl<<endl;
      a/=2;
    }
    while (modulo(b,ZZ(2))==0) {
      paso++;
      cout<<"Paso "<<paso<<":"<<endl;
      cout<<"   a= "<<a<<endl<<"   b=b/2= "<<b<<endl<<endl;
      b/=2;
    }
    ZZ t=abs(a-b)/2;
    if (a>=b){
      a=t;
      paso++;
      cout<<"Paso "<<paso<<":"<<endl;
      cout<<"   a=(a-b)/2= "<<a<<endl<<"   b= "<<b<<endl<<endl;
    }else{
      b=t;
      paso++;
      cout<<"Paso "<<paso<<":"<<endl;
      cout<<"   a= "<<a<<endl<<"   b=(a-b)/2= "<<b<<endl<<endl;
    }
  }
  cout<<"Como a=0 retornamos b*(2n) donde n en la cantidad de veces que hicimos a/2 y b/2 en un mismo paso."<<endl;
  return g*b;
}

ZZ Euclides::mcd6(ZZ a,ZZ b){
  int paso=0;
  while (a!=b) {
    if (a>b){
      a=a-b;
      paso++;
      cout<<"Paso "<<paso<<":"<<endl;
      cout<<"   a=a-b= "<<a<<endl<<"   b= "<<b<<endl<<endl;
    }else{
      b=b-a;
      paso++;
      cout<<"Paso "<<paso<<":"<<endl;
      cout<<"   a= "<<a<<endl<<"   b=b-a= "<<b<<endl<<endl;
    }
  }
  cout<<"Como a y b son iguales entonces retornamos cualquiera de los 2"<<endl;
  return a;
}

ZZ Euclides::mcd7(ZZ a,ZZ b,int paso){
  ZZ r=modulo(a,b);
  paso++;
  cout<<"Paso "<<paso<<":"<<endl;
  cout<<"   "<<a<<"="<<a/b<<"("<<b<<")"<<"+"<<r<<endl;
  if(r==0){
    cout<<"Como el residuo=0 retornamos b="<<b<<endl;
    return(b);
  }
  return mcd7(b,r,paso);
}
