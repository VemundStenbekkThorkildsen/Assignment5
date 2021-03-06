#include <iostream>
#include <fstream>
#include "armadillo"
#include "methods.h"
#include "time.h"


using namespace arma;
using namespace std;


int main(int argc, char *argv[]) //n,tmax,tsteps
//Initializing the system where n, t_steps and t_max is read
//from command line. The different functions are impolemented
//methods.h
{

int n, tsteps;
double dx, dt, t_max;
clock_t start, finish;


if (argc == 4){
  n = atoi(argv[1]);
  t_max = atof(argv[2]);
  tsteps = atof(argv[3]);
} else {
  cout << "Bad usage" << endl;
  exit(1);
}

start = clock();

dx = 1.0/n;
dt = t_max/tsteps;
double per_year = 3600*24*365;
double per_10t = per_year*1e4;
//double alpha = dt/(dx*dx);
double rho = 3.51*1e12; //kg/km^3
double k = 2.5*1e3*per_10t; //J/10year*km/C
double c_p = 1e3; //J/kg/C^-1

double alpha = (dt*k)/(dx*dx);

//bwdEuler(n, tsteps, alpha);
//fwdEuler(n, tsteps, alpha);
//crankNic(n, tsteps, alpha);
//fwd2Euler(n, tsteps, dt, dx);
geoeulerforward(n, tsteps, dt, dx, rho, k, c_p);


finish = clock();
double time = (double (finish)- double (start))/(CLOCKS_PER_SEC);
cout << time << " seconds" << endl;

}
