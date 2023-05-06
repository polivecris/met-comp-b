#include<stdio.h>
#include<math.h>

int main(void){
  double x,xo,y,yo,a,b;
  int n, N, i, I, j, J;
  char nome[30];
  
  FILE*arq;

  printf("Entre com a e b: ");
  scanf("%lf",&a);
  scanf("%lf",&b);
  
  sprintf(nome,"mapa_a%.2f_b%.2f.dat",a,b);	
  arq=fopen(nome,"w");
  
  N=100000;
  
  xo=0.1;
  yo=0.1;
  
  for(n=0;n<N;n++){
    fprintf(arq,"%.12e %.12e \n",xo,yo);	

    x=(a*xo+b*yo)*(1-a*xo-b*yo);
    y=xo;

    xo=x;
    yo=y;
  }
  
  fprintf(arq,"%.12e %.12e \n",xo,yo);
  return 0;
}

