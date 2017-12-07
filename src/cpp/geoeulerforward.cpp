#include "methods.h"

void geoeulerforward(int n, int tsteps, double dt, double dx, double rho, double k, double c_p){

  //Assuming dx = dy
  double alpha = (dt*k)/(dx*dx);
  //double beta = dt/(dy*dy);

  mat u0 = zeros(n+1, n+1);
  mat u = zeros(n+1, n+1);

  for(int i = 0; i<=n; i++){
      u(n,i) = 8.0;
  }

  double Q;

  double per_year = 3600*24*365;
  double per_10t = per_year*1e4;
  double rho_c = rho*c_p;
  int count = 1;
  for (int t = 1; t <= tsteps; t++) {
    for(int i=0; i <=n; i++){
      for(int j=0; j <=n; j++){
          if(i<=20){
              Q = 1.4*1e3*per_10t; //J/10year*km^3
          }
          else if((i>20) && (i<=40)){
              Q = 0.35*1e3*per_10t; //J/10year*km^3
          }
          else if((i>40)){
              Q = 0.05*1e3*per_10t; //J/10year*km^3
          }
          //cout << Q << endl;
          //Q = Q*divider;
          //cout << Q << endl;


          if(i == 0){
              u(i,j) = 1300;
          }
          else if(i == n){
              u(i,j) = 8;
          }
          else if(j == 0){
              u(i,j) = u0(i,j) + (alpha*(u0(i+1,j) + u0(i-1,j) + u0(i,j+1) + u0(i,n) - 4*u0(i,j))+Q*dt)/(rho_c); //C
          }
          else if(j == n){
              u(i,j) = u0(i,j) + (alpha*(u0(i+1,j) + u0(i-1,j) + u0(i,0) + u0(i,j-1) - 4*u0(i,j))+Q*dt)/(rho_c); //C
          }
          else{
              u(i,j) = u0(i,j) + (alpha*(u0(i+1,j) + u0(i-1,j) + u0(i,j+1) + u0(i,j-1) - 4*u0(i,j))+Q*dt)/(rho_c); //C
          }
          //cout << u(i,j) << endl;
      }
    }
    count += 1;
    u0 = u;
    if(count == tsteps/100){
      cout << ((t*100)/tsteps) << " % complete" << endl;
      count = 0;
    }
  }
  string fwdgeo = "../../data/fwdgeo" + to_string(n) + ".txt";
  writeMatFile(u0, fwdgeo);
}
