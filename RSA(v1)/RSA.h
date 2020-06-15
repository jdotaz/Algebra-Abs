#include <string>
using namespace std;

class RSA{
public:
  RSA ();
  RSA (long long,long long);
  string Cifrar(string);
  string Descifrar(string);
private:
  int clave;
  int Zn;
  string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
};
