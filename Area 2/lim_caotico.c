#include<stdio.h>
#include<math.h>

double mapa(double l,double x){
  double y;
  y=4*l*x*(1-x);
  return y;
  
}

int main(void){
  double l,x,dl,dx,lo,xo;
  int n,N,i,I;
  FILE*arquivo=fopen("caos.dat","w");

  dl=(1.0-0.72)/400.0;
  dx=1.0/1100.0;
  
  lo=0.0;
  l=lo;

  N=1.0/dl;
  I=1100;
  xo=0.5;
  
  // Loop para lambda
  for(n=0;n<N;n++){
    x=xo;
    // Loop para x
    for(i=0;i<I;i++){
      if(i>700)
	fprintf(arquivo,"%.12e %.12e \n", l,x);
      x=mapa(l,x);
    };
    l=lo+(n+1)*dl;
    fprintf(arquivo,"%.12e %.12e \n", l,x);
  };
   
  return 0;
}
