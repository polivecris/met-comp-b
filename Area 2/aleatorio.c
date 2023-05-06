#include<stdio.h>
#include<stdlib.h>

int main(void){
  double xi,x=0, x2=0,var,desv, bin;
  int hist[99];
  int i,pos,N;

  N=100;
  bin=1.0E-2;
  srand48(time(NULL));

  for(i=0;i<100;i++){
    hist[i]=0;
  }
  
  for(i=0;i<N;i++){
    xi=drand48();
    x=x+xi;
    x2=x2+xi*xi;
    pos=xi/bin;
    
    hist[pos]++;
  }

  for(i=0;i<100;i++){
    printf("%d %d\n",i,hist[i]);
  }
  
  return 0;
}
