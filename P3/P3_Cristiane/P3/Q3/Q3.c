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
  int h100[100],h1000[1000],h10000[10000];
  FILE*arq;
  
  /* Probabilidade p */
  p=0.5;
  
  /* Semente do gerador pseudo-aleatório */
  srand48(time(NULL));

  /* N=100 */
  arq=fopen("Q3100.dat","w");
  xmax=N1/2;
  xmin=-xmax;
  
  for(i=0;i<N1;i++){
    h100[i]=0;
  }
  
  /* Loop para 10^5 caminhantes */
  for(j=0;j<M;j++){
    /* Posição inicial do caminhante x=0 */
    x=0;
    for(i=0;i<N1;i++){
      if(drand48()<p)
	x+=2;
      else
	x-=2;
    }
    /* Posição final do caminhante j */
    pos=(x+N1)/2;
    h100[pos]++;
  }
  
  /* Ao final do loop dos M caminhantes */
  for(i=0;i<N1;i++){ 
    fprintf(arq,"%d %d\n",i-N1/2,h100[i]);
  }
  fclose(arq);
  

  /* N=1000 */
  arq=fopen("Q31000.dat","w");
  xmax=N2/2;
  xmin=-xmax;
  
  for(i=0;i<N2;i++){
    h1000[i]=0;
  }
  
  /* Loop para 10^5 caminhantes */
  for(j=0;j<M;j++){
    /* Posição inicial do caminhante x=0 */
    x=0;
    for(i=0;i<N2;i++){
      if(drand48()<p)
	x+=2;
      else
	x-=2;
    }
    /* Posição final do caminhante j */
    pos=(x+N2)/2;
    h1000[pos]++;
  }
  
  /* Ao final do loop dos M caminhantes */
  for(i=0;i<N2;i++){ 
    fprintf(arq,"%d %d\n",i-N2/2,h1000[i]);
  }
  fclose(arq);
  
  /* N=10000 */
  arq=fopen("Q310000.dat","w");
  xmax=N3/2;
  xmin=-xmax;
  
  for(i=0;i<N3;i++){
    h10000[i]=0;
  }
  
  /* Loop para 10^5 caminhantes */
  for(j=0;j<M;j++){
    /* Posição inicial do caminhante x=0 */
    x=0;
    for(i=0;i<N3;i++){
      if(drand48()<p)
	x+=2;
      else
	x-=2;
    }
    /* Posição final do caminhante j */
    pos=(x+N3)/2;
    h10000[pos]++;
  }
  
  /* Ao final do loop dos M caminhantes */
  for(i=0;i<N3;i++){ 
    fprintf(arq,"%d %d\n",i-N3/2,h10000[i]);
  }  
  fclose(arq);
}
