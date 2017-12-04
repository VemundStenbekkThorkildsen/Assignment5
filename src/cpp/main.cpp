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

bwdEuler(n, tsteps, alpha);
fwdEuler(n, tsteps, alpha);
crankNic(n, tsteps, alpha);
fwd2Euler(n, tsteps, dt, dx);
bwd2Euler(n, tsteps, dt, dx);


finish = clock();
double time = (double (finish)- double (start))/(CLOCKS_PER_SEC);
cout << time << " seconds" << endl;

}
