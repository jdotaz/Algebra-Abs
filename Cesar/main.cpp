#include <iostream>
#include <string>
#include "Cesar.cpp"

using namespace std;

int main (){
  cout<<"Hola"<<endl;
  Cesar emisor(3);
  cout<<emisor.Descifrar("iholc");
  return 0;
}
