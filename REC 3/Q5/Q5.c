#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
 
#define PI acos(-1.0)
#define N 100000
#define L 5.0
#define n 50

double f(double x){
  double y;
  y=1/(x*x+cos(x)*cos(x));
  return y;
}

double p(double x, double a){
  double y;
  y=a*exp(-a*x)/(1.0-exp(-a*PI));
  return y;
}

void main(void){
  double x[N],s1,s2,var,xmax=PI,xmin=0.0,r,a,da,A;
  double I,P;
  int i,j;

  /* Semente para o número aleatório*/
  srand48(time(NULL));

  a=0.0;
  da=1.5/150.0;
  for(j=0;j<150;j++){
    a+=da;
    A=1.0-exp(-a*PI);
    
    /* Amostragem por importância*/
    P=0.0;
    for(i=0;i<N;i++){
      r=drand48();
      x[i]=(-1.0/a)*log(1.0-A*r);
      P+=(f(x[i])/p(x[i],a));
    }
     
    I=P/(1.0*N);
    
    s2=0.0;
    for(i=0;i<N;i++){
      s2+=((f(x[i])/p(x[i],a))-I)*((f(x[i])/p(x[i],a))-I);
    }
    var=s2/(1.0*(N-1));
    
    printf("%lf %.12e %.12e\n",a,var,I);
  }
}
