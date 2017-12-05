#include "methods.h"

void fwdEuler(int n, int tsteps, double alpha, double ro, double k, double c)
{
  vec unew = zeros(n+1);
  vec u = zeros(n+1);
  u(0) = unew(0) = 0;
  u(n) = unew(n) = 1;

  double Q;

  for (int t = 1; t <= tsteps; t++) {
    for (int i = 1; i < n; i++) {
        if(i<=20){
            Q = 1.4; //myW/m^3
        }
        else if(i>20 && i<=40){
            Q = 0.35; //myW/m^3
        }
        else if(i>40){
            Q = 0.05; //myW/m^3
        }
      unew(i) = (k*(alpha * u(i-1) + (1 - 2*alpha) * u(i) + alpha * u(i+1)) + Q)/(ro*c);
    }
    u = unew;
  }
  string fwdfile = "../../data/fwd" + to_string(n) + ".txt";
  writeToFile(unew, fwdfile);
}
