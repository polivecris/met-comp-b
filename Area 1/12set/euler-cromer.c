#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
  int i,n;
  double h,alpha,x,xo,v,vo,wo2,ti,tf,erro;

  xo=5.0; // valor inicial
  vo=1.0;
  wo2=3.0;
  ti=0.0;
  tf=3.0; 
  n=10000; // numero de pontos
  h=0.01; //(tf-ti)/(1.0*n); // h variavel

  x=xo;
  v=vo;
  printf("%f %.12e %.5e\n",0.0,x,v);
  for(i=0;i<n;i++){
    v=v+(-wo2*x)*h;
    x=x+v*h;
      printf("%f %.12e %.5e\n",(i+1)*h,x,v);
   }
  return 0;
}
