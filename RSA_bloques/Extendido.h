#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

class Extendido{
public:
  Extendido ();
  Extendido (ZZ,ZZ);
  ZZ modulo(ZZ,ZZ);
  void euclidesExtendido();
  ZZ get_mcd();
  ZZ get_x();
  ZZ get_y();
  ZZ get_a();
  ZZ get_b();
  void imprimirEcuacion();

private:
  ZZ a;
  ZZ b;
  ZZ r;
  ZZ r1;
  ZZ r2;
  ZZ s;
  ZZ s1;
  ZZ s2;
  ZZ t;
  ZZ t1;
  ZZ t2;
};
