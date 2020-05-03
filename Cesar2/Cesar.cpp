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
  string cifrada;
  for(int i=0;i<palabra.length();i++){
    int x=(abecedario.find(palabra[i]))+clave;
    if (x>abecedario.length()-1){
      x-=abecedario.length();
    }
    cifrada+=abecedario[x];
  }
  return cifrada;
}
string Cesar::Descifrar(string palabra){
  string descifrada;
  for(int i=0;i<palabra.length();i++){
    int x=(abecedario.find(palabra[i]))-clave;
    if (x<0){
      x+=abecedario.length();
    }
    descifrada+=abecedario[x];
  }
  return descifrada;
}
