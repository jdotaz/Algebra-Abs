#include "Vigenere.h"
#include <iostream>
#include <string>

using namespace std;

Vigenere::Vigenere(){
}
Vigenere::Vigenere(string _clave){
  clave=_clave;
}
void Vigenere::ClaveActualizada(string _mensaje){
  int diferencia=_mensaje.length()-clave.length();
  for(int i=0;i<diferencia;i++){
    clave+=clave[i];
  }
}

string Vigenere::Cifrar(string mensaje){
  string cifrada;
  ClaveActualizada(mensaje);
  for(int i=0;i<mensaje.length();i++){
    int x=(abecedario.find(mensaje[i]));
    int y=(abecedario.find(clave[i]));
    x+=y;
    if (x>abecedario.length()-1){
      x-=abecedario.length();
    }
    cifrada+=abecedario[x];
  }
  return cifrada;
}
string Vigenere::Descifrar(string mensaje){
  string descifrada;
  ClaveActualizada(mensaje);
  for(int i=0;i<mensaje.length();i++){
    int x=(abecedario.find(mensaje[i]));
    int y=(abecedario.find(clave[i]));
    x-=y;
    if (x<0){
      x+=abecedario.length();
    }
    descifrada+=abecedario[x];
  }
  return descifrada;
}
