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
  criba(1000000,p,q);
  n=p*q;
  Fn=(p-1)*(q-1);
  do {
    e=(ZZ)rand()%(Fn/2)+(Fn/2);
  } while(mcd(e,Fn)!=1);
  d=invMul(e,Fn);
  cout<<"Clave Publica: <"<<n<<","<<e<<">"<<endl;
  cout<<"Clave Privada: <"<<n<<","<<d<<">"<<endl;
}
