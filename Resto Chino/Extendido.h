using namespace std;

class Extendido{
public:
  Extendido ();
  Extendido (int,int);
  int modulo(int,int);
  void euclidesExtendido();
  int get_mcd();
  int get_x();
  int get_y();
  int get_a();
  int get_b();
  void imprimirEcuacion();

private:
  int a;
  int b;
  int r;
  int r1;
  int r2;
  int s;
  int s1;
  int s2;
  int t;
  int t1;
  int t2;
};
