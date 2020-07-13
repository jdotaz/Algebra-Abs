#include "RSA.h"

RSA::RSA(int bits){
  p=randPrim(bits/2);
  q=randPrim(bits/2);
  N=p*q;
  fN=(p-1)*(q-1);
  do{
    e=random(bits/2);
  }while(mcd(e,fN)!=1);
  d=inversaMul(e,fN);
  cout<<"p: "<<p<<endl;
  cout<<"q: "<<q<<endl;
  cout<<"N: "<<N<<endl;
  cout<<"fN: "<<fN<<endl;
  cout<<"e: "<<e<<endl;
  cout<<"d: "<<d<<endl;

}

void RSA::Cambio(ZZ _p, ZZ _q, ZZ _e){
  p=_p;
  q=_q;
  N=p*q;
  fN=(p-1)*(q-1);
  e=_e;
  d=inversaMul(e,fN);
  cout<<"p: "<<p<<endl;
  cout<<"q: "<<q<<endl;
  cout<<"N: "<<N<<endl;
  cout<<"fN: "<<fN<<endl;
  cout<<"e: "<<e<<endl;
  cout<<"d: "<<d<<endl;
}

void RSA::locutor(ZZ _Npublic, ZZ _Epublic){
  Npublic=_Npublic;
  Epublic=_Epublic;
}

string RSA::mensajeNum(string mensaje){
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

void RSA::bloques(string mensaje, vector<string> &blocks,int tam){
  int tope=(mensaje.size()/tam);
  for(int i=0;i<tope;i++){
    blocks.push_back(mensaje.substr(0,tam));
    mensaje.erase(0,tam);
  }
}

string RSA::Firma(string mensaje){
  mensaje=mensajeNum(mensaje);
  int tam=digitos(N)-1;
  int relleno=alfabeto.find("w");
  int sobra=mensaje.size()%tam;
  if(sobra){
    for(int i=0;i<((tam-sobra)/digitos((ZZ)relleno))+1;i++){
      mensaje+=to_string(relleno);
    }
  }
  vector<string> vectorBlocks;
  bloques(mensaje,vectorBlocks,tam);
  string cifrado;
  for(int i=0;i<vectorBlocks.size();i++){
    string block=vectorBlocks[i];
    ZZ num(INIT_VAL, block.c_str());
    ZZ x=expoMod(num,d,N);
    for(int j=0;j<digitos(N)-digitos(x);j++){
      cifrado+="0";
    }
    stringstream cif;
    cif<<x;
    cifrado+=cif.str();
  }
  return cifrado;
}

string RSA::Cifrar(string mensaje){
  mensaje=Firma(mensaje);
  mensaje=mensajeNum(mensaje);
  int tam=digitos(Npublic)-1;
    int relleno=alfabeto.find("w");
  int sobra=mensaje.size()%tam;
  if(sobra){
    for(int i=0;i<((tam-sobra)/digitos((ZZ)relleno))+1;i++){
      mensaje+=to_string(relleno);
    }
  }
  vector<string> vectorBlocks;
  bloques(mensaje,vectorBlocks,tam);
  string cifrado;
  for(int i=0;i<vectorBlocks.size();i++){
    string block=vectorBlocks[i];
    ZZ num(INIT_VAL, block.c_str());
    ZZ x=expoMod(num,Epublic,Npublic);
    for(int j=0;j<digitos(Npublic)-digitos(x);j++){
      cifrado+="0";
    }
    stringstream cif;
    cif<<x;
    cifrado+=cif.str();
  }
  return cifrado;
}

string RSA::AntFirma(string mensaje){
  string descifrado;
  vector<string> vectorBlocks;
  bloques(mensaje,vectorBlocks,digitos(N));
  for(int i=0;i<vectorBlocks.size();i++){
    string block=vectorBlocks[i];
    ZZ num(INIT_VAL, block.c_str());
    ZZ x=expoMod(num,d,N);
    for(int j=0;j<digitos(N)-1-digitos(x);j++){
      descifrado+="0";
    }
    stringstream cif;
    cif<<x;
    descifrado+=cif.str();
  }
  vector<string> vectorLetras;
  bloques(descifrado,vectorLetras,digitos((ZZ)alfabeto.size()-1));
  string resultado;
  for(int i=0;i<vectorLetras.size();i++){
    int x=stoi(vectorLetras[i]);
    resultado+=alfabeto[x];
  }
  cout<<endl<<endl<<resultado<<endl<<endl;
  return resultado;
}

string RSA::Descifrar(string mensaje){
  mensaje=AntFirma(mensaje);
  string descifrado;
  vector<string> vectorBlocks;
  bloques(mensaje,vectorBlocks,digitos(Npublic));
  for(int i=0;i<vectorBlocks.size();i++){
    string block=vectorBlocks[i];
    cout<<"block:"<<block<<endl;
    ZZ num(INIT_VAL, block.c_str());
    cout<<"num:"<<num<<endl;
    ZZ x=expoMod(num,Epublic,Npublic);
    for(int j=0;j<digitos(Npublic)-1-digitos(x);j++){
      descifrado+="0";
    }
    stringstream cif;
    cif<<x;
    descifrado+=cif.str();
  }
  vector<string> vectorLetras;
  bloques(descifrado,vectorLetras,digitos((ZZ)alfabeto.size()-1));
  string resultado;
  for(int i=0;i<vectorLetras.size()-1;i++){
    int x=stoi(vectorLetras[i]);
    resultado+=alfabeto[x];
  }

  return resultado;
}

void RSA::Print(){
  cout<<"p: "<<p<<endl;
  cout<<"q: "<<q<<endl;
  cout<<"N: "<<N<<endl;
  cout<<"fN: "<<fN<<endl;
  cout<<"e: "<<e<<endl;
  cout<<"d: "<<d<<endl;
  cout<<"e otro: "<<Epublic<<endl;
  cout<<"N otro: "<<Npublic<<endl;
}
