#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
  int i,n;
  double h,alpha,x,xo,ti,tf;

  xo=5.0; // xo variavel tambem
  alpha=2;
  ti=0.0;
  tf=3.0;
  n=100;
  h=(tf-ti)/(1.0*n); // h variavel

  x=xo;
  printf("%f %.12e\n ",0.0,x);
  for(i=0;i<n;i++){
    x=x-alpha*h*x;
    printf("%f %.12e\n ",(i+1)*h,x);
   }
  
  return 0;
}
