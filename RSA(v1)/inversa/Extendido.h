using namespace std;

class Extendido{
public:
  Extendido ();
  Extendido (long long,long long);
  long long modulo(long long,long long);
  void euclidesExtendido();
  long long get_mcd();
  long long get_x();
  long long get_y();
  long long get_a();
  long long get_b();
  void imprimirEcuacion();

private:
  long long a;
  long long b;
  long long r;
  long long r1;
  long long r2;
  long long s;
  long long s1;
  long long s2;
  long long t;
  long long t1;
  long long t2;
};
