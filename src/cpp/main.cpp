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


void tridiag(int n, vec& y, double a, double b, double c, vec& u)
{
    vec b_tilde = zeros(n);
    vec y_tilde = zeros(n);

    b_tilde(0) = b;
    y_tilde(0) = y(0);

    for (int i = 1; i < n; i++){
        b_tilde(i) = b - (c*a)/b_tilde(i-1);
        y_tilde(i) = y(i) - (y_tilde(i-1)*c/b_tilde(i-1));
    }
    //print

    //b_t * u_n-1 + c*u_n = y_t_n-1
    u(n-1) = (y(n-1)-c*u(n))/b_tilde(n-1);
    for (int k = n-2; k>0; k--){
        u(k) = (y_tilde(k) - c*u(k+1))/b_tilde(k);
    }

}


void fwdEuler(int n, int tsteps, double alpha){

    vec y = zeros(n+1);
    vec u = zeros(n+1);
    double a = alpha;
    double b = 1 - 2*alpha;
    double c = alpha;
    for(int t = 1; t <= tsteps; t++){
        u(0) = u(n) = 0;
        tridiag(n,y,a,b,c,u);
        for(int i = 0; i<=n; i++){
            y(i) = u(i);
        }
    }
}


void bwdEuler(int n, int tsteps, double alpha)
{
  double a, b, c;
  vec u = zeros(n+1);
  vec y = zeros(n+1);
  y(n) = u(n) = 1;
  y(0) = u(0) = 0;
  a = c = - alpha;
  b = 1 + 2*alpha;
  for (int t = 1; t <= tsteps; t++) {
    tridiag(n, y, a, b, c, u);
    u(0) = 0;
    u(n) = 1;
    for (int i = 0; i <= n; i++) {
      y(i) = u(i);
    }
  }
  string bwdfile = "../../data/bwd" + to_string(n) + ".txt";
  writeToFile(u, bwdfile);
}


void crankNicolson(){
  //TODO construct Crank-Nicolson
  //My estimate is that it has to test the theta factor
  //and then call either bwdEuler or fwdEuler.
}


int main(int argc, char *argv[]) //n,tmax,tsteps
{

int n, t_max, tsteps;
double dx, dt;


if (argc == 4){
  n = atoi(argv[1]);
  t_max = atoi(argv[2]);
  tsteps = atof(argv[3]);
} else {
  cout << "Bad usage" << endl;
  exit(1);
}

dx = 1.0/n;
dt = ((double) t_max)/((double) tsteps);
double alpha = dt/(dx*dx);

bwdEuler(n, tsteps, alpha);
//fwdEuler(n, tsteps, alpha);


}
