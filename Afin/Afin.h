#include <string>
using namespace std;

class Afin{
public:
  Afin ();//Emisor
  Afin (int,int);//Receptor
  string Cifrar(string);
  string Descifrar(string);
  int get_clave1();
  int get_clave2();
private:
  void generar_claves();
  int clave1;
  int clave2;
  string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
};
