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
    for(int i=1; i <=n-1; i++){
      for(int j=1; j <=n-1; j++){
          if(j == 0){
              u(i,j) = 0;
          }
          else if(j == n){
              u(i,j) = 1;
          }
          else if(i == 0){
              u(i,j) = u0(i,j) + alpha*(u0(i+1,j) + u0(n,j) + u0(i,j+1) + u0(i,j-1) - 4*u0(i,j));
          }
          else if(i == n){
              u(i,j) = u0(i,j) + alpha*(u0(0,j) + u0(i-1,j) + u0(i,j+1) + u0(i,j-1) - 4*u0(i,j));
          }
          else{
              u(i,j) = u0(i,j) + alpha*(u0(i+1,j) + u0(i-1,j) + u0(i,j+1) + u0(i,j-1) - 4*u0(i,j));
          }
      }
    }
    u0 = u;
  }
  string fwd2file = "../../data/2fwd" + to_string(n) + ".txt";
  writeMatFile(u0, fwd2file);
}
