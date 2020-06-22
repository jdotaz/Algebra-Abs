#include <string>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

class RSA{
public:
  RSA ();
  RSA (ZZ,ZZ);
  ZZ expoMod(ZZ,ZZ);
  int Digitos(ZZ);
  string Cifrar(string);
  string Descifrar(string);
private:
  ZZ clave;
  ZZ Zn;
  string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
};
