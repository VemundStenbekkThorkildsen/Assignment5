#include "methods.h"

void fwd2Euler(int n, int tsteps, double dt, double dx){

  double dy = dx;
  double alpha = dt/(dx*dx);
  double beta = dt/(dy*dy)

  mat unew = zeros(n+1, n+1);
  mat u = zeros(n+1, n+1);

  u(0, 0) = u0(0, 0) = 0;
  u(n, n) = u0(n, n) = 1;

  for (int t = 1; t <= tsteps; t++) {
    for(int i=1; i < n; i++){
      for(int j=1; j < n; j++){
        uxx = alpha*(u0(i+1,j) - 2*u0(i,j) + u0(i-1,j));
        uyy = beta*(u0(i,j+1) - 2*u0(i,j) + u0(i,j-1));
        u(i,j) = uxx + uyy + dt*u0(i,j);
      }
    }
    u0 = u;
  }
  string fwd2file = "../../data/2fwd" + to_string(n) + ".txt";
  writeMatFile(u0, fwd2file);
}
