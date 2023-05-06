#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
 
#define PI acos(-1.0)
#define L 5.0
#define n 50
 
void main(void){
  double x,r,area,dx;
  int i,j,k,hist[n], N;

  char nome[30];
  FILE *freq;
  FILE *norm;

  printf("%.30e\n",PI);
  
  for(i=0;i<n;i++){
    hist[i]=0;
  }
   
  /* Semente para o número aleatório*/
  srand48(time(NULL));

  /* Tamanho do bin*/
  dx=(2.0*L)/n;

  N=100000;  
  /* Loop para variar N */
    sprintf(nome,"letrad.dat");	
    norm=fopen(nome,"w");
    
    /* Loop para gerar números*/
    for(i=0;i<N;i++){
      r=(drand48()-0.5)*10.0;
      x=PI/(4*L)*cos((PI*r)/(2*L));
      
      j=floor((x+L)/dx);
      hist[j]++;
    }
    
    /* Imprime histograma */
    for(i=0;i<n;i++){
      fprintf(freq,"%lf %d\n",i*dx-L+dx/2,hist[i]);
    }
    
    /* Normaliza histograma */
    area=0.0;
    for(i=0;i<n;i++){
      area+=hist[i]*dx;
    }
    
    /* Imprime histograma normalizado*/
    for(i=0;i<n;i++){
      fprintf(norm,"%lf %lf\n",i*dx-L+dx/2,hist[i]/area);
    }
}
