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

string Vigenere::reprocesarMensaje(string _mensaje){
  for(int i=10;i<=_mensaje.length();i+=14){
    _mensaje.insert(i,"AQUI");
  }
  int tam=(((_mensaje.length()/4)+1)*4)-_mensaje.length();
  for(int i=0;i<tam;i++){
    _mensaje+="W";
  }
  return _mensaje;
}

string Vigenere::Cifrar(string mensaje){
  mensaje=reprocesarMensaje(mensaje);
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

  cout<<"Demostracion del mensaje(solo para presentar la tarea):"<<endl<<descifrada<<endl<<endl;//Comentar

  bool encontrar=true;
  while(encontrar){
    encontrar=false;
    if(descifrada[descifrada.length()-1]=='W'){
      descifrada.erase(descifrada.length()-1,1);
      encontrar=true;
    }
  }
  for(int i=10;i<descifrada.length();i+=10){
    descifrada.erase(i,4);
  }
  return descifrada;
}
