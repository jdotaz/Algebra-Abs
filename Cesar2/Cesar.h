#include <string>
using namespace std;

class Cesar{
public:
  Cesar ();
  Cesar (int);
  string Cifrar(string);
  string Descifrar(string);
private:
  int clave;
  string abecedario="aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
};
