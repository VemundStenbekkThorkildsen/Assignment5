#include "methods.h"

void geoeulerforward(int n, int tsteps, double dt, double dx, double rho, double k_old, double c_p){

  //Assuming dx = dy
  double alpha = dt/(dx*dx);
  //double beta = dt/(dy*dy);

  mat u0 = zeros(n+1, n+1);
  mat u = zeros(n+1, n+1);

  for(int i = 0; i<=n; i++){
      u(i,n) = 8.0;
  }

  double Q;
  double k;

  double per_year = 3600*24*365;
  double per_10Ma = per_year*1e7;
  double rho_c = rho*c_p;
  int count = 1;
  for (int t = 1; t <= tsteps; t++) {
    double divider = ((double) t / (double) tsteps);
    //k = k_old*divider;
    for(int i=0; i <=n; i++){
      for(int j=0; j <=n; j++){
          if(j<=20){
              Q = (per_10Ma*(1.4*1e-6)*1e9)*1e-12;//*10e-12; //TJ/10My*km^3
          }
          else if((j>20) && (j<=40)){
              Q = (per_10Ma*(0.35*1e-6)*1e9)*1e-12;//*10e-12; //TJ/10My*km^3
          }
          else if((j>40)){
              Q = (per_10Ma*(0.05*1e-6)*1e9)*1e-12;//*10e-12; //TJ/10My*km^3
          }
          //cout << Q << endl;
          //Q = Q*divider;
          //cout << Q << endl;


          if(j == 0){
              u(i,j) = 1300;
          }
          else if(j == n){
              u(i,j) = 8;
          }
          else if(i == 0){
              u(i,j) = (k*(u0(i,j) + alpha*(u0(i+1,j) + u0(n,j) + u0(i,j+1) + u0(i,j-1) - 4*u0(i,j)))+Q)/(rho_c);
          }
          else if(i == n){
              u(i,j) = (k*(u0(i,j) + alpha*(u0(0,j) + u0(i-1,j) + u0(i,0) + u0(i,j-1) - 4*u0(i,j)))+Q)/(rho_c);
          }
          else{
              u(i,j) = (k*(u0(i,j) + alpha*(u0(i+1,j) + u0(i-1,j) + u0(i,j+1) + u0(i,j-1) - 4*u0(i,j)))+Q)/(rho_c);
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
