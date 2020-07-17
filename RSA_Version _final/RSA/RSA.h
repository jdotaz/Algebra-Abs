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
  string CifrarParte1(string);
  string CifrarParte2(string,ZZ,ZZ);
  string DescifrarParte1(string,ZZ,ZZ,bool);
  string DescifrarParte2(string);
  void bloques(string,vector<string> &blocks,int);
  ZZ Chino(ZZ num);
  ZZ d,e,N,p,q,fN,Epublic,Npublic;
};
