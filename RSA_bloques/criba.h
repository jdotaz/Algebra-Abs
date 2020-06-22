#include <iostream>
#include <NTL/ZZ.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;
using namespace NTL;

ZZ expo(ZZ a,ZZ x){
  ZZ r=(ZZ)1;
  do {
    if(x%2==1){
      r=r*a;
    }
    a=a*a;
    x/=2;
  } while(x>0);
  return r;
}

bool primalidad(ZZ num,vector<ZZ> &divs){
  for(int j=0;j<divs.size();j++){
    if(num%divs[j]==0){
      return false;
    }
  }
  return true;
}

void criba(int bits, vector<ZZ> &criba){
  vector<ZZ> divisores;
  ZZ final=expo((ZZ)2,(ZZ)bits);
  ZZ inicio=final/2;
  for(ZZ i=(ZZ)3;i*i<final;i+=2){
    divisores.push_back(i);
  }
  int e=0;
  ZZ tope=divisores[divisores.size()-1];
  while(divisores[e]*divisores[e]<tope){
    for(int i=e+1;i<divisores.size();i++){
      if(divisores[i]%divisores[e]==0){
        divisores.erase(divisores.begin()+i);
      }
    }
    e++;
  }

  for(ZZ i=inicio+1;i<final;i+=2){
    if(primalidad(i,divisores)){
      criba.push_back(i);
    }
  }
}
