#include "Cesar.h"
#include <iostream>
#include <string>

using namespace std;

Cesar::Cesar(){
  clave=3;
}
Cesar::Cesar(int _clave){
  clave=_clave*2;
}
string Cesar::Cifrar(string palabra){
  string cifrada(palabra.length(),'x');
  cout<<clave<<endl;
  for(int i=0;i<palabra.length();i++){
    int x=(abecedario.find(palabra[i]))+clave;
    if (x>abecedario.length()){
      x-=abecedario.length();
    }
    cout<<x<<endl;
    cifrada[i]=abecedario[x];
  }
  return cifrada;
}
string Cesar::Descifrar(string palabra){
  string descifrada(palabra.length(),'x');
  for(int i=0;i<palabra.length();i++){
    int x=(abecedario.find(palabra[i]))-clave;
    if (x<0){
      x+=abecedario.length();
    }
    descifrada[i]=abecedario[x];
  }
  return descifrada;
}
