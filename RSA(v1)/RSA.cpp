#include "RSA.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

RSA::RSA(){
  Zn=0;
  clave=0;
}
RSA::RSA(long long _Zn,long long _clave){
  Zn=_Zn;
  clave=_clave;
}
string RSA::Cifrar(string mensaje){
  string cifrado;
  for(int i=0;i<mensaje.size();i++){
    long long x=(long long)alfabeto.find(mensaje[i]);
    cifrado+=to_string(expoMod(x,clave,Zn));
    cifrado+=" ";
  }
  return cifrado;
}
string RSA::Descifrar(string mensaje){
  string descifrado;
  vector<string> vectorMensaje;
  string letra;
  for(int i=0;i<mensaje.size();i++){
    if(mensaje[i]!=' '){
      letra+=mensaje[i];
    }else{
      vectorMensaje.push_back(letra);
      letra="";
    }
  }
  vectorMensaje.push_back(letra);
  for(int i=0;i<vectorMensaje.size();i++){
    long long toInt =(long long)atoi(vectorMensaje[i].c_str());
    int x=(int)expoMod(toInt,clave,Zn);
    descifrado+=alfabeto[x];
  }
  return descifrado;
}
