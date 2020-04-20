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
  string claveNueva;
  int x=_mensaje.length()/clave.length();
  for(int i=0;i<x;i++){
    claveNueva+=clave;
  }
  int y=_mensaje.length()%clave.length();
  for(int i=0;i<y;i++){
    claveNueva+=clave[i];
  }
  clave=claveNueva;
}
int Vigenere::find(string _mensaje,int indice,int _tipo){
  switch (_tipo) {
    case 1:{
      return abecedario.find(_mensaje[indice]);
    }
    case 2:{
      for(int j=0;j<55;j++){
        if(_mensaje[indice]==ASCII[j]){
          return j;
        }
      }
    }
    case 3:{
      for(int j=0;j<55;j++){
        if(_mensaje[indice]==ASCII[j]){
          return j;
        }
      }
    }
  }
  return 0;
}

string Vigenere::Cifrar(string mensaje,int tipo){
  string cifrada;
  ClaveActualizada(mensaje);
  for(int i=0;i<mensaje.length();i++){
    int x=find(mensaje,i,tipo);
    int y=find(clave,i,tipo);
    x+=y;
    if (x>abecedario.length()-1){
      x-=abecedario.length();
    }
    if (tipo==1){
      cifrada+=abecedario[x];
    }
    if (tipo==2){
      cifrada+=ASCII[x];
    }
    if (tipo==3){
      cifrada+=ASCII[x];
    }
  }
  return cifrada;
}

string Vigenere::Descifrar(string mensaje,int tipo){
  string descifrada;
  ClaveActualizada(mensaje);
  for(int i=0;i<mensaje.length();i++){
    int x=find(mensaje,i,tipo);
    int y=find(clave,i,tipo);
    x-=y;
    if (x<0){
      x+=abecedario.length();
    }
    if (tipo==1){
      descifrada+=abecedario[x];
    }
    if (tipo==2){
      descifrada+=ASCII[x];
    }
    if (tipo==3){
      descifrada+=ASCII[x];
    }
  }
  return descifrada;
}

// string Vigenere::Descifrar(string mensaje){
//   string descifrada;
//   ClaveActualizada(mensaje);
//   for(int i=0;i<mensaje.length();i++){
//     int x=(abecedario.find(mensaje[i]));
//     int y=(abecedario.find(clave[i]));
//     x-=y;
//     if (x<0){
//       x+=abecedario.length();
//     }
//     descifrada+=abecedario[x];
//   }
//   return descifrada;
// }
