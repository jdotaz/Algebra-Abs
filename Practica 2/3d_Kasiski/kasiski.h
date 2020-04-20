#include <string>
#include <vector>
using namespace std;

class kasiski{
public:
  kasiski();
  void cryptoanalisis(string);
  string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
private:
  vector<int> distancias;
  void tamDeLaClave(string);
  int euclides(int a,int b);
  int euclidesVector();
  void dividirSubCadenas(string,string[],int);
  void contarTabla(string);
};
