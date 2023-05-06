#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double acceleration(double t, double x){
  
}

int main(void){
  int i,n;
  double h,alpha,x,xo,ti,tf,erro;

  xo=5.0; // valor inicial
  alpha=3;
  ti=0.0;
  tf=3.0;
  n=100000; // numero de pontos
  h=(tf-ti)/(1.0*n); // h variavel

  x=xo;
  erro=fabs((5.0*exp(-3.0*0.0)-x)/(5.0*exp(-3.0*0.0)));
  printf("%f %.12e %.5e\n",0.0,x,erro);
  for(i=0;i<n;i++){
    x=x/(1.0+alpha*h);
    erro=fabs((5.0*exp(-3.0*(i+1)*h)-x)/(5.0*exp(-3.0*(i+1)*h)));
    printf("%f %.12e %.5e\n",(i+1)*h,x,erro);
   }
  
  return 0;
}
