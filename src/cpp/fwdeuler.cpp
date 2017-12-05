#include "methods.h"

void fwdEuler(int n, int tsteps, double alpha)
{
  vec unew = zeros(n+1);
  vec u = zeros(n+1);
  u(0) = unew(0) = 0;
  u(n) = unew(n) = 1;

  for (int t = 1; t <= tsteps; t++) {
    for (int i = 1; i < n; i++) {
      unew(i) = alpha * u(i-1) + (1 - 2*alpha) * u(i) + alpha * u(i+1);
    }
    u = unew;
  }
  string fwdfile = "../../data/fwd" + to_string(n) + ".txt";
  writeToFile(unew, fwdfile);
}
