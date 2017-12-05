#include "methods.h"

void geoeulerforward(int n, int tsteps, double dt, double dx, double ro, double k, double c){

  //Assuming dx = dy
  double alpha = dt/(dx*dx);
  //double beta = dt/(dy*dy);

  mat u0 = zeros(n+1, n+1);
  mat u = zeros(n+1, n+1);

  for(int i = 0; i<=n; i++){
      u(i,n) = 1.0;
  }

  double Q;

  for (int t = 1; t <= tsteps; t++) {
    for(int i=0; i <=n; i++){
      for(int j=0; j <=n; j++){
          if(j<=20){
              Q = 1.4e9; //myW/km^3
          }
          else if((j>20) && (j<=40)){
              Q = 0.35e9; //myW/km^3
          }
          else if((j>40)){
              Q = 0.05e9; //myW/km^3
          }


          if(j == 0){
              u(i,j) = 0;
          }
          else if(j == n){
              u(i,j) = 1;
          }
          else if(i == 0){
              u(i,j) = (k*(u0(i,j) + alpha*(u0(i+1,j) + u0(n,j) + u0(i,j+1) + u0(i,j-1) - 4*u0(i,j)))+Q)/(ro*c);
          }
          else if(i == n){
              u(i,j) = (k*(u0(i,j) + alpha*(u0(0,j) + u0(i-1,j) + u0(i,j+1) + u0(i,j-1) - 4*u0(i,j)))+Q)/(ro*c);
          }
          else{
              u(i,j) = (k*(u0(i,j) + alpha*(u0(i+1,j) + u0(i-1,j) + u0(i,j+1) + u0(i,j-1) - 4*u0(i,j)))+Q)/(ro*c);
          }
      }
    }
    u0 = u;
  }
  string fwdgeo = "../../data/fwdgeo" + to_string(n) + ".txt";
  writeMatFile(u0, fwdgeo);
}
