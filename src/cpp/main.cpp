#include <iostream>
#include <fstream>
#include "armadillo"


using namespace arma;
using namespace std;


void writeToFile(vec& u, string filename)
{
  ofstream outfile(filename);
  outfile << u << endl;
  outfile.close();
}


void trisolver(double a, double b, double c, int n, vec& v_prev, vec& v)
{
  vec u(n);
  vec l(n);

  u.fill(b);
  l.fill(a);
  for(int i=0; i <n-1; i++){
    l(i) = a/u(i);
    u(i+1) = b-l(i)*c;
  }
  for(int j=1; j<n; j++){
      v(j) = v_prev(j) - l(j-1)*v(j-1);
    }

  v(n-1) = v(n-1)/u(n-1);
  for(int k=n-2; k>0; k--){
      v(k) = (v(k) - c*v(k+1))/u(k);
    }
}


void fwdEuler(int n, int tsteps, double alpha)
{
  vec unew = zeros(n+1);
  vec u = zeros(n+1);
  u(0) = unew(0) = 0;
  u(n) = unew(n) = 1;

  for (int t = 1; t <= tsteps; t++) {
    for (int i = 1; i < n; i++) {
      unew(i) = alpha * u(i-1) + (1 - 2*alpha) * u(i) + alpha * u(i+1);
    }
    u = unew;
  }
  string fwdfile = "../../data/fwd" + to_string(n) + ".txt";
  writeToFile(unew, fwdfile);
}


void bwdEuler(int n, int tsteps, double alpha)
{
  double a, b, c;
  vec v = zeros(n+1);
  vec v_prev = zeros(n+1);
  v_prev(n) = v(n) = 1;
  v_prev(0) = v(0) = 0;
  a = c = -alpha;
  b = 1 + 2*alpha;
  for (int t = 1; t <= tsteps; t++) {
    v_prev = v;
    v_prev(n-1) += alpha;
    trisolver(a, b, c, n, v_prev, v);
  }
  string bwdfile = "../../data/bwd" + to_string(n) + ".txt";
  writeToFile(v, bwdfile);
}


void crankNic(int n, int tsteps, double alpha)
{ //fungerer ikke
  double a, b, c;
  vec u = zeros(n+1); // This is u in Au=y
  vec y = zeros(n+1); // This is y in Au=y
  u(n) = y(n) = 1;

  a = c = - alpha;
  b = 2 + 2*alpha;
  for (int t = 1; t <= tsteps; t++) {
    for (int i = 1; i < n; i++) {
      y(i) = alpha*u(i-1) + (2 - 2*alpha)*u(i) + alpha*u(i+1);
    }
    u = y;
    trisolver(a, b, c, n, y, u);
    y = u;
    y(n-1) += alpha;
  }
  string crankfile = "../../data/crank" + to_string(n) + ".txt";
  writeToFile(u, crankfile);
}


int main(int argc, char *argv[]) //n,tmax,tsteps
{

int n, tsteps;
double dx, dt, t_max;


if (argc == 4){
  n = atoi(argv[1]);
  t_max = atof(argv[2]);
  tsteps = atof(argv[3]);
} else {
  cout << "Bad usage" << endl;
  exit(1);
}

dx = 1.0/n;
dt = t_max/tsteps;
cout << dt << endl;
double alpha = dt/(dx*dx);

//bwdEuler(n, tsteps, alpha);
//fwdEuler(n, tsteps, alpha);
crankNic(n, tsteps, alpha);

}
