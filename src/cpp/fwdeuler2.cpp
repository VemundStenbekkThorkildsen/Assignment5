#include "methods.h"

void fwd2Euler(int n, int tsteps, double dt, double dx){

  //Assuming dx = dy
  double alpha = dt/(dx*dx);
  //double beta = dt/(dy*dy);

  mat u0 = zeros(n+1, n+1);
  mat u = zeros(n+1, n+1);

  for(int i = 0; i<=n; i++){
      u(i,n) = 1.0;
  }

  for (int t = 1; t <= tsteps; t++) {
    for(int i=0; i <=n; i++){
      for(int j=0; j <=n; j++){
        if(i==0 || i==n){
          continue
        } else if(j==0){
            u(i,j) = u0(i,j) + alpha*(u0(i+1,j) + u0(i-1,j) + u0(i,j+1) - 4*u0(i,j));
        } else if(j==n){
            u(i,j) = u0(i,j) + alpha*(u0(i+1,j) + u0(i-1,j) + u0(i,j-1) - 4*u0(i,j));
        }
        u(i,j) = u0(i,j) + alpha*(u0(i+1,j) + u0(i-1,j) + u0(i,j+1) + u0(i,j-1) - 4*u0(i,j));
      }
    }
    u0 = u;
  }
  string fwd2file = "../../data/2fwd" + to_string(n) + ".txt";
  writeMatFile(u0, fwd2file);
}
