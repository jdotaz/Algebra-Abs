#include <iostream>
#include <vector>
#include "criba.h"
#include "expoMod.h"
#include "inversa/invMul.h"

using namespace std;

void imprimirClaves(){
  srand (time(NULL));
  long long p,q,n,Fn,e,d;
  criba(10000,p,q);
  n=p*q;
  Fn=(p-1)*(q-1);
  do {
    e=rand()%(Fn/2)+(Fn/2);
  } while(mcd(e,Fn)!=1);
  d=invMul(e,Fn);
  cout<<"Clave Publica: <"<<n<<","<<e<<">"<<endl;
  cout<<"Clave Privada: <"<<n<<","<<d<<">"<<endl;
}
