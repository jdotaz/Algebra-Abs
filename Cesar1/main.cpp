#include <iostream>
#include <string>
#include "Cesar.cpp"

using namespace std;

int main (){
  Cesar emisor(3);
  Cesar receptor(3);
  string mensaje;
  cin>>mensaje;
  string menCif=emisor.Cifrar(mensaje);
  cout<<menCif<<endl;
  cout<<receptor.Descifrar(menCif)<<endl;

  return 0;
}
