#include "MonoBino.h"
#include <iostream>
#include <string>

using namespace std;

MonoBino::MonoBino(){
}

MonoBino::MonoBino(string memotec,int clave1,int clave2){
  _clave1=clave1;
  _clave2=clave2;
  tableroLetras+=memotec;
  for(int i=0;i<alfabeto.size();i++){
    if(tableroLetras.find(alfabeto[i])==-1){
      tableroLetras+=alfabeto[i];
    }
  }
  int j=0;
  for(int i=0;i<10;i++){
    if(i!=clave1 and i!=clave2){
      tableroCodigos[i+j]=to_string(i);
    }else{
      j--;
    }
  }
  int k=0;
  for(int i=8;i<18;i++){
    tableroCodigos[i]=to_string(clave1)+to_string(k);
    k++;
  }
  k=0;
  for(int i=18;i<28;i++){
    tableroCodigos[i]=to_string(clave2)+to_string(k);
    k++;
  }
  for (int i=0;i<28;i++){
  }
}

int MonoBino::modulo(int dividendo,int divisor){
  int residuo=dividendo-(divisor*(dividendo/divisor));
  if (residuo<0){
    residuo+=divisor;
  }
  return residuo;
}

string MonoBino::Cifrar(string mensaje){
  string mensajeCifrado;
  for(int i=0;i<mensaje.size();i++){
    int x=tableroLetras.find(mensaje[i]);
    mensajeCifrado+=tableroCodigos[x];
  }
  return mensajeCifrado;
}

string MonoBino::Descifrar(string mensaje){
  string mensajeDescifrado;
  int x=0;
  string doble;
  for(int i=0;i<mensaje.size();i++){
    string codigo;
    doble=mensaje[i];
    if(doble==to_string(_clave1) or doble==to_string(_clave2)){
      codigo+=mensaje[i];
      codigo+=mensaje[++i];
    }else{
      codigo=mensaje[i];
    }
    for(int j=0;j<28;j++){
      if (codigo==tableroCodigos[j]){
        x=j;
      }
    }
    mensajeDescifrado+=tableroLetras[x];
  }
  return mensajeDescifrado;
}
