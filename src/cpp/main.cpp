#include <iostream>
#include <fstream>
#include "armadillo"
#include "methods.h"
#include "time.h"


using namespace arma;
using namespace std;


int main(int argc, char *argv[]) //n,tmax,tsteps
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
double alpha = dt/(dx*dx);

double ro = (3.510*3.510*3.510)*1000; //kg/km^3
double k = 2.5e3; //W/km/C
double c = 1000; //J/kg/C^-1

//bwdEuler(n, tsteps, alpha);
//fwdEuler(n, tsteps, alpha);
//crankNic(n, tsteps, alpha);
fwd2Euler(n, tsteps, dt, dx);
//geoeulerforward(n, tsteps, dt, dx, ro, k, c);


finish = clock();
double time = (double (finish)- double (start))/(CLOCKS_PER_SEC);
cout << time << " seconds" << endl;

}
