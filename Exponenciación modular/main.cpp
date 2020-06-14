#include <iostream>
#include "expoMod.h"

using namespace std;

int main(){
  long long a,x,r,n;
  cout<<"Ingrese el numero: ";
  cin>>a;
  cout<<"Ingrese el exponente: ";
  cin>>x;
  cout<<"Ingrese el n: ";
  cin>>n;
  cout<<endl<<"El resultado es: "<<expoMod(a,x,n);
}
