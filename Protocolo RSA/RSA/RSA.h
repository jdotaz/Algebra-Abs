#include "Librerias/abstracta.h"

class RSA{
public:
  RSA (int);
  void Cambio(ZZ,ZZ,ZZ);
  void locutor(ZZ, ZZ);
  string Cifrar(string);
  string Descifrar(string);
  void Print();
  string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
private:
  string Firma(string);
  string AntFirma(string);
  string mensajeNum(string);
  void bloques(string,vector<string> &blocks,int);
  ZZ d,e,N,p,q,fN,Epublic,Npublic;
};
