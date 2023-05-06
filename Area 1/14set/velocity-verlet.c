#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
  int i,n;
  double h,x,xo,v,vo,a,ao,L,g;

  xo=3.0; // valor inicial
  vo=0.0;
  L=1.0;
  g=10.0;
  n=1000; // numero de pontos
  h=0.01; //(tf-ti)/(1.0*n); // h variavel

  x=xo;
  v=vo;
  a=-g/L*sin(x);
  printf("%f %.12e %.5e\n",0.0,x,v);
  for(i=0;i<n;i++){
    ao=a;
    x=x+v*h+0.5*a*h*h;
    a=-g/L*sin(x);
    v=v+0.5*(ao+a)*h;
    printf("%f %.12e %.5e\n",(i+1)*h,x,v);
  }
  return 0;
}
