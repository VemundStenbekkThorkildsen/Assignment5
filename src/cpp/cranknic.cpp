#include "methods.h"

void crankNic(int n, int tsteps, double alpha_old)
{
  double a, b, c;
  vec y = zeros(n+1); // This is u in Au=y
  vec u = zeros(n+1); // This is y in Au=y

  y(n) = u(n) = 1;

  double alpha = 0.5*alpha_old;
  a = c = -alpha;
  b = (2+2*alpha);
  for (int t = 1; t <= tsteps; t++) {
    for (int i = 1; i < n; i++) {
      y(i) = (alpha)*u(i-1) + (2 - 2*alpha)*u(i) + (alpha)*u(i+1);
    }

    y(n) = u(n) = 1;
    y(0) = u(0) = 0;
    y(n-1) += alpha;

    //meme

    trisolver(a, b, c, n, y, u);
    }

  string crankfile = "../../data/crank" + to_string(n) + ".txt";
  writeToFile(u, crankfile);
}
