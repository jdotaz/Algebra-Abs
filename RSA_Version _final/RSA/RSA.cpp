#include "RSA.h"

//Constructor
RSA::RSA(int bits){
  p=randPrim(bits/2);
  q=randPrim(bits/2);
  N=p*q;
  fN=(p-1)*(q-1);
  do{
    e=random(bits/2);
  }while(mcd(e,fN)!=1);
  d=inversaMul(e,fN);
}

//Actualiza todos los valores de la clase
void RSA::Cambio(ZZ _p, ZZ _q, ZZ _e){
  p=_p;
  q=_q;
  N=p*q;
  fN=(p-1)*(q-1);
  e=_e;
  d=inversaMul(e,fN);
}

//Añade valores del N y e de la persona con la que te vas a comunicar la cual llamo locutor
void RSA::locutor(ZZ _Npublic, ZZ _Epublic){
  Npublic=_Npublic;
  Epublic=_Epublic;
}

//funcion para dividir string en bloques
void RSA::bloques(string mensaje, vector<string> &blocks,int tam){
  int tope=(mensaje.size()/tam);
  for(int i=0;i<tope;i++){
    blocks.push_back(mensaje.substr(0,tam));
    mensaje.erase(0,tam);
  }
}

//Método de Quisquater-Couvreur
ZZ RSA::Chino(ZZ num){
  ZZ dp=modulo(d,p-1);
  ZZ dq=modulo(d,q-1);
  dp=expoMod(modulo(num,p),dp,p);
  dq=expoMod(modulo(num,q),dq,q);
  vector<ZZ> a={dp,dq};
  vector<ZZ> n={p,q};
  return RChino(a,n);
}

//Primera parte del cifrado donde busco cada letra del mensaje en el alfabeto y registro su posicion en un string
string RSA::CifrarParte1(string mensaje){
  string total;
  int max=digitos((ZZ)(alfabeto.size()-1));
  for(int i=0;i<mensaje.size();i++){
    int x=alfabeto.find(mensaje[i]);
    for(int j=0;j<max-digitos((ZZ)x);j++){
      total+="0";
    }
    total+=to_string(x);
  }
  return total;
}

//Segunda parte del cifrado
string RSA::CifrarParte2(string mensaje, ZZ _N, ZZ clave){
  //relleno del valor numerico del caracter menos usado(w) hasta que mi string tenga el porte de un multiplo de N
  int tam=digitos(_N)-1;
  int relleno=alfabeto.find("w");
  int sobra=mensaje.size()%tam;
  if(sobra){
    for(int i=0;i<((tam-sobra)/digitos((ZZ)relleno))+1;i++){
      mensaje+=to_string(relleno);
    }
  }
  //Divido mi string en bloques y los cifro uno por uno
  vector<string> vectorBlocks;
  bloques(mensaje,vectorBlocks,tam);
  string cifrado;
  for(int i=0;i<vectorBlocks.size();i++){
    string block=vectorBlocks[i];
    ZZ num(INIT_VAL, block.c_str());
    ZZ x=expoMod(num,clave,_N);
    for(int j=0;j<digitos(_N)-digitos(x);j++){
      cifrado+="0";
    }
    stringstream cif;
    cif<<x;
    cifrado+=cif.str();
  }
  return cifrado;
}

string RSA::Cifrar(string mensaje){
  mensaje=CifrarParte1(mensaje);
  //Hago la 2da parte del cifrado 2 veces para la firma digital, primro la rubrica y luego el mensaje que enviare.
  mensaje=CifrarParte2(mensaje,N,d);
  mensaje=CifrarParte2(mensaje,Npublic,Epublic);
  return mensaje;
}

//Primera parte del descifrado donde divido mi string en bloques y los descifro uno por uno
string RSA::DescifrarParte1(string mensaje, ZZ _N, ZZ clave, bool RS=false){
  string descifrado;
  vector<string> vectorBlocks;
  bloques(mensaje,vectorBlocks,digitos(_N));
  for(int i=0;i<vectorBlocks.size();i++){
    string block=vectorBlocks[i];
    ZZ num(INIT_VAL, block.c_str());
    ZZ x;
    //Uso un booleano para saber si usar el resto chino o la exponenciación modular
    if(RS){
      x=Chino(num);
    }else{
      x=expoMod(num,clave,_N);
    }
    for(int j=0;j<digitos(_N)-1-digitos(x);j++){
      descifrado+="0";
    }
    stringstream cif;
    cif<<x;
    descifrado+=cif.str();
  }
  return descifrado;
}

//Segunda parte del descifrado donde dividimos nuestro string en bloques y los buscamos en el alfabeto
string RSA::DescifrarParte2(string mensaje){
  vector<string> vectorLetras;
  bloques(mensaje,vectorLetras,digitos((ZZ)alfabeto.size()-1));
  string resultado;
  for(int i=0;i<vectorLetras.size()-1;i++){
    int x=stoi(vectorLetras[i]);
    resultado+=alfabeto[x];
  }

  return resultado;
}

string RSA::Descifrar(string mensaje){
  //Descifro 2 veces, primero el menaje y luego la rubrica
  mensaje=DescifrarParte1(mensaje,N,d,true);
  mensaje=DescifrarParte1(mensaje,Npublic,Epublic);
  mensaje=DescifrarParte2(mensaje);
  return mensaje;
}

//funcion para imprimir los datos de la clase
void RSA::Print(){
  cout<<"p: "<<p<<endl;
  cout<<"q: "<<q<<endl;
  cout<<"N: "<<N<<endl;
  cout<<"fN: "<<fN<<endl;
  cout<<"e: "<<e<<endl;
  cout<<"d: "<<d<<endl;
}
