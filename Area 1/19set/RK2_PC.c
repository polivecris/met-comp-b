#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double funcao(double t,double x){
  double y;
  y=x-(t*t)+1;
  
  return y;
}

double RK2PontoCentral(double t,double x, double h){
  double alpha=0.5, beta=0.5, gamma=1, delta=1;
  double k1, k2;

  k1=funcao(t,x);
  k2=funcao((t+gamma*h),(x+delta*k1*h));

  x=x+(alpha*k1+beta*k2)*h;

  return x;
}


int main(){
  double t,xo,x,h,ti,tf,err;
  FILE*arquivo=fopen("RK2PontoCentral.dat","w+");
  FILE*erro=fopen("RK2PontoCentral-err.dat","w+");

  xo=0.5;
  ti=0.0;
  tf=2.0;
  h=0.1;
  
  x=xo;
  for(t=ti;t<tf;t+=h){
    fprintf(arquivo,"%f %.12e\n",t,x);
    x=RK2PontoCentral(t,x,h);
  }
  fprintf(arquivo,"%f %.12e\n",tf, x);
  
  err=fabs(9.0-0.5*exp(2.0)-x);
  fprintf(erro,"%f %.12e\n",h, err);
  return 0;
}
