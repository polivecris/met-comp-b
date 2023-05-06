#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double funcao(double t,double x){
  double y;
  y=x-(t*t)+1;
  
  return y;
}

double RK2PontoCentral(double t,double x, double h){
  //double a, b, c, d;
  double k1, k2;

  k1=funcao(t,x);
  k2=funcao((t+0.5*h),(x+0.5*k1*h));

  x=x+(0*k1+1*k2)*h;

  return x;
}


int main(){
  double t,xo,x,h,ti,tf,err;
  xo=0.5;
  ti=0.0;
  tf=2.0;
  h=0.1;

  x=xo;
  for(t=ti;t<tf;t+=h){
      printf("%f %.12e\n",t,x);
      x=RK2PontoCentral(t,x,h);
  }
  printf("%f %.12e\n",tf, x);

  err=fabs(9.0-0.5*exp(2.0)-x);
  printf("%f %.12e\n",h, err);
  return 0;
}
