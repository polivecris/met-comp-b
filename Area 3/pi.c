#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 4000
#define S 20

int main(void){
  double xi,x=0,x2=0;
  double yi,y=0,y2=0;
  double var,desv,bin;
  double prob;
  
  int hist[N];
  int i,s,nhits;

  prob=M_PI/4.0;
  //printf("%f\n",prob);
  
  for(i=0;i<N;i++){
    hist[i]=0;
  }
  //
  srand48(time(NULL));
  for(s=0;s<S;s++){

    nhits=0;
    for(i=0;i<N;i++){
      if(drand48()<prob){
	nhits++;
      }
    }
    //printf("%d %d %d\n",s, i, nhits);
    hist[nhits]++;
  }
  //
  for(i=1;i<N;i++){
    printf("%d %d\n",i,hist[i]);
  }
  //
  
  return 0;
}
