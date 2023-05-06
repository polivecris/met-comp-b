#include<stdio.h>
#include<stdlib.h>
#define N 100

main(){
  double x=0,x2=0;
  float p;
  int xi,hist[99], i,j, pos;

  printf("Probabilidade p: ");
  scanf("%f", &p);
  
  srand48(time(NULL));
  for(i=0;i<100;i++){
    hist[i]=0;
  }

  xi=0;
  for(i=0;i<N;i++){
    if(drand48()<p)
      xi++;
    else
      xi--;

    printf("%d %d\n",i+1,xi);

    x=x+xi;
    x2=x2+xi*xi;

    pos=xi+50;
    
    hist[pos]++;
  }

  /* for(i=0;i<100;i++){ */
  /*   printf("%d %d\n",i,hist[i]); */
  /* } */


  // Histograma do último x em várias repetições
  
}
