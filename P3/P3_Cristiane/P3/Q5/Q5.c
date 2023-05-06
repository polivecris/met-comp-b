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
  y=exp(-a*x);
  return y;
}

void main(void){
  double x[N],s1,s2,var,xmax=PI,xmin=0.0,r,a,da;
  double I,P;
  int i,j;

  /* Semente para o número aleatório*/
  srand48(time(NULL));

  a=0.0;
  da=2.0/200.0;
  for(j=0;j<200;j++){
    a+=da;
    /* Amostragem por importância*/
    P=0.0;
    //s1=0.0;
    //s2=0.0;
    for(i=0;i<N;i++){
      r=drand48();
      x[i]=(-1.0/a)*log(1.0-r*(1.0-exp(-a*PI)));
      P+=(f(x[i])/p(x[i],a));
      //s1+=(f(x[i])/p(x[i],a));
      //s2+=s1*s1;
    }
     
    I=P/(1.0*N);

    s2=0.0;
    for(i=0;i<N;i++){
// ERRO
      s2+=((f(x[i])/p(x[i],a))-I)*((f(x[i])/p(x[i],a))-I);
    }
    var=s2/(1.0*(N-1));
    printf("%lf %.12e %.12e\n",a,var,I);
  }
}
