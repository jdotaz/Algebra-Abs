#include <string>
using namespace std;

class RailFence{
public:
  RailFence ();
  RailFence (int);
  int modulo(int,int);
  string Cifrar(string);
  string Descifrar(string);
private:
  int clave;
};
