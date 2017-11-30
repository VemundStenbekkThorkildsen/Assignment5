#include "armadillo"

using namespace arma;

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
    tridag(a, b, c, y, u, n+1);
    u(0) = u(n) = 0;
    for (int i = 0; i <= n; i++) {
      y(i) = u(i);
    }
    y.print()
  }
  y.print()
}





void tridiag(double a, double b, double c, double *y, double *u, int n){
    double *d_tilde = new double[n];
    double *b_tilde = new double[n];
    d_tilde[0] = d_array[0];
    b_tilde[0] = b_array[0]/d_array[0];


    for (int i = 1; i < n; i++){
        d_tilde[i] = d_array[i] - (c_array[i-1]*a_array[i-1])/d_tilde[i-1];
        b_tilde[i] = b_array[i] - (b_tilde[i-1]*c_array[i-1])/d_tilde[i-1];
    }

    v[n-1] = b_tilde[n-1]/d_tilde[n-1];
    for (int k = n-2; k>= 0; k--){
        v[k] = (b_tilde[k] - c_array[k]*v[k+1])/d_tilde[k];
    }




int main(int argc, char *argv[]){
  //TODO initialize the entire system
}
