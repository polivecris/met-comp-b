#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define PI acos(-1.0)
#define L 5.0
#define n 50
#define N 100000

void main(void){
  double x,r,area,dx;
  int i,j,k,hist[n];
  
  char nome[30];
  FILE *freq;
  FILE *norm;
  
  //printf("%.30e\n",PI);
  
  for(i=0;i<n;i++){
    hist[i]=0;
  }
  
  /* Semente para o número aleatório*/
  srand48(time(NULL));
  
  /* Tamanho do bin*/
  dx=(PI/(2*L))/(2.0*n);
  
  /* Arquivos para salvar histogramas */
  sprintf(nome,"hist_d.dat");	
  freq=fopen(nome,"w");
  
  sprintf(nome,"norm_d.dat");	
  norm=fopen(nome,"w");
  
  /* Loop para gerar números*/
  for(i=0;i<N;i++){
    r=(drand48()-0.5)*10.0;
    x=(PI/(4*L))*cos((PI*r)/(2*L));

    printf("%lf %lf\n",r,x);
    
    j=floor(x/dx);
    hist[j]++;
  }
  
  /* Imprime histograma */
  for(i=0;i<n;i++){
    fprintf(freq,"%lf %d\n",i*dx, hist[i]);
  }
  
  /* Normaliza histograma */
  area=0.0;
  for(i=0;i<n;i++){
    area+=hist[i]*dx;
  }
  
  /* Imprime histograma normalizado*/
  for(i=0;i<n;i++){
    fprintf(norm,"%lf %lf\n",i*dx, hist[i]/area);
  }
}
