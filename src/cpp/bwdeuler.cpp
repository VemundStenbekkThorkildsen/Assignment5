#include "methods.h"

void bwdEuler(int n, int tsteps, double alpha)
{
  double a, b, c;
  vec v = zeros(n+1);
  vec v_prev = zeros(n+1);
  v_prev(n) = v(n) = 1;
  v_prev(0) = v(0) = 0;
  a = c = -alpha;
  b = 1 + 2*alpha;

  for (int t = 1; t <= tsteps; t++) {
    v_prev = v;
    v_prev(n-1) += alpha;
    trisolver(a, b, c, n, v_prev, v);
  }
  string bwdfile = "../../data/bwd" + to_string(n) + ".txt";
  writeToFile(v, bwdfile);
}
