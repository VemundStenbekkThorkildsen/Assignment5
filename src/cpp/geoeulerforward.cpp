#include "methods.h"

void geoeulerforward(int n, int tsteps, double dt, double dx, double ro, double k, double c){

  //Assuming dx = dy
  double alpha = dt/(dx*dx);
  //double beta = dt/(dy*dy);

  mat u0 = zeros(n+1, n+1);
  mat u = zeros(n+1, n+1);

  for(int i = 0; i<=n; i++){
      u(i,n) = 8.0;
  }

  double Q;

  double per_year = 3600*24*365;

  for (int t = 1; t <= tsteps; t++) {
    for(int i=0; i <=n; i++){
      for(int j=0; j <=n; j++){
          double divider = ((double) t / (double) tsteps);
          if(j<=20){
              Q = (per_year*1.4*1e3)*1e4; //J/10000year*km^3
          }
          else if((j>20) && (j<=40)){
              Q = (per_year*0.35*1e3)*1e4; //J/10000year*km^3
          }
          else if((j>40)){
              Q = (per_year*0.05*1e3)*1e4; //J/10000year*km^3
          }


          if(j == 0){
              u(i,j) = 1300;
          }
          else if(j == n){
              u(i,j) = 8;
          }
          else if(i == 0){
              u(i,j) = divider*(k*(u0(i,j) + alpha*(u0(i+1,j) + u0(n,j) + u0(i,j+1) + u0(i,j-1) - 4*u0(i,j)))+Q)/(ro*c);
          }
          else if(i == n){
              u(i,j) = divider*(k*(u0(i,j) + alpha*(u0(0,j) + u0(i-1,j) + u0(i,0) + u0(i,j-1) - 4*u0(i,j)))+Q)/(ro*c);
          }
          else{
              u(i,j) = divider*(k*(u0(i,j) + alpha*(u0(i+1,j) + u0(i-1,j) + u0(i,j+1) + u0(i,j-1) - 4*u0(i,j)))+Q)/(ro*c);
          }
          //cout << u(i,j) << endl;
      }
    }
    u0 = u;
    cout << ((double) t/tsteps)*100 << " % complete" << endl;
  }
  string fwdgeo = "../../data/fwdgeo" + to_string(n) + ".txt";
  writeMatFile(u0, fwdgeo);
}
