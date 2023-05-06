#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define M 100000///100000
#define N1 100
#define N2 1000
#define N3 10000

void main(void){
  double p;
  int i,j,pos;
  int x,xmin,xmax;
  int h100[9],h1000[99],h10000[99];
  
  /* Probabilidade p */
  p=0.5;

  /* Semente do gerador pseudo-aleatório */
  srand48(time(NULL));
  
  xmax=sqrt(N1);
  xmin=-xmax;
  
  for(i=0;i<10;i++){
    h100[i]=0;
  }
  
  /* Loop para 10^5 caminhantes */
  for(j=0;j<M;j++){
    /* Posição inicial do caminhante x=0 */
    x=0;
    for(i=0;i<10;i++){
      if(drand48()<p)
	x+=2;
      else
	x-=2;
      /* Imprime posições instantâneas */
      //printf("%d %d\n",(i+1),x);
    }
    /* Posição final do caminhante j */
    pos=x+(10)/2;
    printf("%d %d\n",x,pos);
    h100[pos]++;
  }
  
  /* Ao final do loop dos M caminhantes */
  //for(i=0;i<10;i++){ 
  //  printf("%d %d\n",i,h100[i]);
  //}  
}
