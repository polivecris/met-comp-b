#include<stdio.h>
#include<math.h>

double mapa(double l,double x){
  double y;
  y=4*l*x*(1-x);
  return y;
}

double deriv(double l, double x){
  double y;
  y=4*l*(1-x);
  return y;
}

int main(void){
  double l,x,dl,dx,lo,xo,lyapunov;
  int n,N,i,I,c;
  FILE*arquivo=fopen("caos.dat","w");
  FILE*expoente=fopen("lyapunov.dat","w");

  dl=(1.0-0.72)/400.0;
  dx=1.0/1100.0;
  
  lo=0.0;
  l=lo;

  N=1.0/dl;
  I=1500;
  
  xo=0.5;
  // Loop para lambda
  for(n=0;n<N;n++){
    x=xo;
    lyapunov=0.0;

    // Loop para x
    for(i=0;i<I;i++){
      if(i>700){
	fprintf(arquivo,"%.12e %.12e \n", l,x);
	lyapunov=lyapunov+log(fabs(deriv(l,x)));
	printf("%.12e \n",lyapunov);
      }
      x=mapa(l,x);
    };
    
    l=lo+(n+1)*dl;
    fprintf(arquivo,"%.12e %.12e \n", l,x);
    lyapunov=lyapunov/400.0;
    fprintf(expoente,"%.12e %.12e \n", l,lyapunov);
  };

  fprintf(arquivo,"%.12e %.12e \n", l,x);
  fprintf(expoente,"%.12e %.12e \n", l,lyapunov);
   
  return 0;
}
