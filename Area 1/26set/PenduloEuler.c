#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
    xo=x;
    x=xo+v*h;
    v=v+(-g/L*sin(xo))*h;
    t=(n+1)*h;
   }
   printf("%f %.12e %.12e\n",t,x,v);
  return 0;
}
