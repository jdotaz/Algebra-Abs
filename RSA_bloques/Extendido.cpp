#include "Extendido.h"
#include <NTL/ZZ.h>
#include <iostream>

using namespace std;
using namespace NTL;

Extendido::Extendido(){
}

Extendido::Extendido(ZZ _a,ZZ _b){
  a=_a;
  b=_b;
  r1=_a;
  s1=1;
  t1=0;
  r2=_b;
  s2=0;
  t2=1;
  euclidesExtendido();
}
void Extendido::euclidesExtendido(){
  while (r2>0) {
    ZZ q=r1/r2;
    r=r1-(q*r2);
    r1=r2;
    r2=r;
    s=s1-(q*s2);
    s1=s2;
    s2=s;
    t=t1-(q*t2);
    t1=t2;
    t2=t;
  }
}
ZZ Extendido::get_mcd(){
  return r1;
}
ZZ Extendido::get_x(){
  return s1;
}
ZZ Extendido::get_y(){
  return t1;
}
ZZ Extendido::get_a(){
  return a;
}
ZZ Extendido::get_b(){
  return b;
}
void Extendido::imprimirEcuacion(){
  cout<<a<<"("<<s1<<")+"<<b<<"("<<t1<<")="<<r1<<endl;
}
