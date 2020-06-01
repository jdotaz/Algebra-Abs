#include <string>
using namespace std;

class MonoBino{
public:
  MonoBino ();
  MonoBino (string,int,int);
  int modulo(int,int);
  string Cifrar(string);
  string Descifrar(string);
  string alfabeto="ABCDEFGHIJKLMN/OPQRSTUVWXYZ#";
private:
  int _clave1;
  int _clave2;
  string tableroLetras;
  string tableroCodigos[28];
};
