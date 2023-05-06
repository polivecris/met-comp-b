// Pendulo Simples em velocity verlet
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Aceleracao (relacionada a forca)
double funcao(double t,double x, double v){
  double y, g=10.0, L=1.0;
  y=-g/L*sin(x);
  return y;
}

int main(void){
  int i,n,N;
  double t,ti,tf,x,xo,v,vo,a,ao,h;
  double g, L;
  
  ti=0.0;
  tf=20.0;
  
  N=2000; 
  h=(tf-ti)/(1.0*N); 

  // Valores iniciais
  xo=1.5; 
  vo=0.0;
  L=1.0;
  g=10.0;

  x=xo;
  v=vo;
  t=ti;
  a=-g/L*sin(x);
  
  for(n=0;n<N;n++){
    printf("%f %.12e %.12e\n",t,x,v);
    ao=a;
    x=x+v*h+0.5*a*h*h;
    a=-g/L*sin(x);
    v=v+0.5*(ao+a)*h;  
    t=(n+1)*h;
  }
  printf("%f %.12e %.12e\n",t,x,v);
  
  return 0;
}
