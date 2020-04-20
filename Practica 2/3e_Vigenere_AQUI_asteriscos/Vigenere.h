#include <string>
using namespace std;

class Vigenere{
public:
  Vigenere ();
  Vigenere (string);
  void ClaveActualizada(string);
  string reprocesarMensaje(string);
  string Cifrar(string);
  string Descifrar(string);
  string abecedario="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
private:
  string clave;
};
