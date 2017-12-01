#include "iostream"
#include "fstream"
#include <armadillo>

using namespace arma;
using namespace std;

void crankNicolson(){
  //TODO construct Crank-Nicolson
  //My estimate is that it has to test the theta factor
  //and then call either bwdEuler or fwdEuler.
}

void tridiag(int n, vec& y, double a, double b, double c, vec& u)
{
    vec b_tilde(n);
    vec y_tilde(n);

    b_tilde(0) = b;
    y_tilde(0) = y(0)/b;

    for (int i = 1; i < n; i++){
        b_tilde(i) = b - (c*a)/b_tilde(i-1);
        y_tilde(i) = y(i) - (b_tilde(i-1)*c/b_tilde(i-1));
    }
    u(n-1) = y(n-1)/b_tilde(n-1);
    for (int k = n-2; k>=0; k--){
        u(k) = (y_tilde(k) + u(k+1))/b_tilde(k);
    }
}

void bwdEuler(int n, int tsteps, double delta_x, double alpha)
{
  double a, b, c;
  vec u = zeros(n+1);
  vec y = zeros(n+1);
  y(n) = u(n) = 1;
  y(0) = u(0) = 0;
  a = c = - alpha;
  b = 1 + 2*alpha;
  for (int t = 1; t <= tsteps; t++) {
    tridiag(n+1, y, a, b, c, u);
    u(0) = u(n) = 0;
    for (int i = 0; i <= n; i++) {
      y(i) = u(i);
    }
    //y.print()
  }
  y.print();
}


int main(/*int argc, char *argv[]*/)
{

int n, t_max, tsteps;
double dx, dt;

if (argc > 3){
  n = atoi(argv[1]);
  t_max = atoi(argv[2]);
  dx = atof(argv[3]);
} else {
  cout << "Bad usage" << endl;
}

dt = (dx*dx)/4;
tsteps = t_max/dt;
double alpha = dt/(dx*dx);

bwdEuler(n, tsteps, dx, alpha);




}
