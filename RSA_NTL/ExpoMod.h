#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ expoMod(ZZ a,ZZ x,ZZ n){
  ZZ r=(ZZ)1;
  do {
    if(x%2==1){
      r=((r%n)*(a%n))%n;
    }
    a=((a%n)*(a%n))%n;
    x/=2;
  } while(x>0);
  return r;
}
