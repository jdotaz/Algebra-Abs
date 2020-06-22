#include "RSA.h"
#include <iostream>
#include <NTL/ZZ.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "ExpoMod.h"
#include <vector>
#include <sstream>

using namespace std;
using namespace NTL;

RSA::RSA(){
  Zn=0;
  clave=0;
}
RSA::RSA(ZZ _Zn,ZZ _clave){
  Zn=_Zn;
  clave=_clave;
}
string RSA::Cifrar(string mensaje){
  string cifrado;
  for(int i=0;i<mensaje.size();i++){
    ZZ x=(ZZ)alfabeto.find(mensaje[i]);
    stringstream cif;
    cif<<expoMod(x,clave,Zn);
    cifrado+=cif.str();
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
    string str=vectorMensaje[i];
    ZZ toInt(  INIT_VAL, str.c_str());
    long a=0;
    conv(a,expoMod(toInt,clave,Zn));
    int x=(int)a;
    descifrado+=alfabeto[x];
  }
  return descifrado;
}
