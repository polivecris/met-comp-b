#include<stdio.h>
#include<math.h>

int main(void){
  double x,xo,y,yo,a,b;
  double ao,bo,da,lyapunov=0.0;
  
  //Comprimentos
  double cx,cy,cxo,cyo,length;
  //Jacobiano
  double J1,J2,J3,J4;
  int n,N,i,I,j,J;
  char nome[30];

  FILE*arq;
  FILE*exp;

  printf("Entre com a e b: ");
  scanf("%lf",&ao);
  scanf("%lf",&bo);

  sprintf(nome,"bifurcac_a%.2f_b%.2f.dat",ao,bo);	
  arq=fopen(nome,"w");
  
  sprintf(nome,"lyapunov_a%.2f_b%.2f.dat",ao,bo);	
  exp=fopen(nome,"w");
  
  N=10000;
  I=1000;
  
  da=4.0/I;
  
  // Mantém-se b fixo e varia-se a
  b=bo;
  a=ao;
  
  // Loop para a
  for(i=0;i<I;i++){
    xo=0.1;
    yo=0.1;

    cxo=1.0;
    cyo=1.0;
   
    // Loop para x
    for(n=0;n<N;n++){
      if(n > (N-100)){
	fprintf(arq,"%.12e %.12e %.12e\n",a,x,y);
	
	// Elementos do Jacobiano
	J1=a-2*a*a*xo-2*a*b*yo;
	J2=b-2*b*b*yo-2*a*b*xo;
	J3=1.0;
	J4=0.0;
	
	cx=J1*cxo+J2*cyo;
	cy=J3*cxo+J4*cyo;
      
	length=sqrt(cx*cx+cy*cy);
	lyapunov=log(length)/100.0;
	
	cxo=cx;
	cyo=cy;
      }
      
      x=(a*xo+b*yo)*(1-a*xo-b*yo);
      y=xo;
      
      xo=x;
      yo=y;
      
    };
    
    a=ao+(i+1)*da;
    fprintf(arq,"%.12e %.12e %.12e\n",a,x,y);
    fprintf(exp,"%.12e %.12e \n",a,lyapunov);
  };
   
  return 0;
}
