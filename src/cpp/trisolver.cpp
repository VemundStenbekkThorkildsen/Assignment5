#include "methods.h"

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
