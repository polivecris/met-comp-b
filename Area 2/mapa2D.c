#include<stdio.h>
#include<math.h>

int main(void){
  double x, y, xo, yo;
  int n, N;

  N=100;

  xo=0.5*(-1-sqrt(5));
  yo=1.0;
  for(n=0;n<N;n++){
    printf("%.12e %.12e \n", xo, yo);
    x=xo+yo;
    y=xo+2*yo;

    xo=x;
    yo=y;
  }

  return 0;
}
