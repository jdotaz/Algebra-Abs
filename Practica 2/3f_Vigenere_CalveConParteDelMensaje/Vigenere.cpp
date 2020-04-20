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
    clave+=_mensaje[i];
  }
  cout<<"Demostracion de la clave(solo para presentar la tarea):"<<endl<<clave<<endl<<endl;//Comentar
}

string Vigenere::Cifrar(string palabra){
  string cifrada;
  ClaveActualizada(palabra);
  for(int i=0;i<palabra.length();i++){
    int x=(abecedario.find(palabra[i]));
    int y=(abecedario.find(clave[i]));
    x+=y;
    if (x>abecedario.length()-1){
      x-=abecedario.length();
    }
    cifrada+=abecedario[x];
  }
  return cifrada;
}
string Vigenere::Descifrar(string palabra){
  string descifrada;
  for(int i=0;i<palabra.length();i++){
    int x=(abecedario.find(palabra[i]));
    int y=(abecedario.find(clave[i]));
    x-=y;
    if (x<0){
      x+=abecedario.length();
    }
    descifrada+=abecedario[x];
    if (palabra.length()!=clave.length()){
      clave+=abecedario[x];
    }
  }
  return descifrada;
}
