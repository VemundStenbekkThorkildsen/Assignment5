#include "iostream"
#include "fstream"
#include "armadillo"

using namespace arma;
using namespace std;

void crankNicolson(){
  //TODO construct Crank-Nicolson
  //My estimate is that it has to test the theta factor
  //and then call either bwdEuler or fwdEuler.
}



void bwdEuler(int n, int tsteps, double delta_x, double alpha)
{
  double a, b, c;
  vec u(n+1);
  vec y(n+1);
  y(n) = u(n) = 1;
  y(0) = u(0) = 0;
  a = c = - alpha;
  b = 1 + 2*alpha;
  for (int t = 1; t <= tsteps; t++) {
    tridag(n+1, y, a, b, c, u);
    u(0) = u(n) = 0;
    for (int i = 0; i <= n; i++) {
      y(i) = u(i);
    }
    y.print()
  }
  y.print()
}


void tridiag(int n, vec& y, double a, double b, double c, vec& u)
{
    vec b_tilde(n);
    vec y_tilde(n);

    b_tilde(0) = b;
    y_tilde(0) = y(0)/b;

    for (int i = 1; i < n; i++){
        b_tilde(i) = b - (c*a)/b_tilde(i-1);
        y_tilde(i) = y(i) - (b_tilde(i-1)*c/b_tilde(i-1);
    }
    u(n-1) = y(n-1)/b_tilde(n-1);
    for (int k = n-2; k>=0; k--){
        u(k) = (y_tilde(k) + u(k+1))/b_tilde(k);
    }
}


int main(int argc, char *argv[]){
  //TODO initialize the entire system
int n, int t_max, int tsteps;
double dx, double dt;
if (argv >= 4){
  n = argv[1];
  t_max = argv[2];
  dx = argv[3];
} else {
  cout << "Bad usage" << endl;
}

dt = dx^2/4;
tsteps = 

bwdEuler(n, )




}
