#include <iostream>
#include <NTL/ZZ.h>
#include <vector>
#include "criba.h"
#include "invMul.h"

using namespace std;
using namespace NTL;

void imprimirClaves(){
  srand (time(NULL));
  ZZ p,q,n,Fn,e,d;
  int bits;
  cout<<"Ingrese el bloque de de primos: ";
  cin>>bits;
  vector<ZZ> cribaV;
  criba(bits,cribaV);
  p=cribaV[rand()%cribaV.size()];
  q=cribaV[rand()%cribaV.size()];
  n=p*q;
  Fn=(p-1)*(q-1);
  do {
    e=cribaV[rand()%cribaV.size()];
  } while(mcd(e,Fn)!=1);
  d=invMul(e,Fn);
  cout<<"Clave Publica: <"<<n<<","<<e<<">"<<endl;
  cout<<"Clave Privada: <"<<n<<","<<d<<">"<<endl;
}
