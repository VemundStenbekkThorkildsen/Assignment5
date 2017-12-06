#pragma once
#include "armadillo"
#include <string>

using namespace arma;
using namespace std;

void writeToFile(vec& u, string filename);
void writeMatFile(mat& u, string filename);
void trisolver(double a, double b, double c, int n, vec& v_prev, vec& v);
void fwdEuler(int n, int tsteps, double alpha);
void bwdEuler(int n, int tsteps, double alpha);
void crankNic(int n, int tsteps, double alpha_old);
void fwd2Euler(int n, int tsteps, double dt, double dx);
void geoeulerforward(int n, int tsteps, double dt, double dx, double ro, double k, double c);
