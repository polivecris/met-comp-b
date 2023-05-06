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
  double x[N],y,s1,s2,var1,var2,xmax,xmin,ymax,ymin,r,a;
  double I1,I2,S,P;
  int i,j;

  /* Semente para o número aleatório*/
  srand48(time(NULL));

  xmax=PI;
  xmin=0.0;
  ymax=1.0;
  xmin=0.0;

  for(j=0;j<100;j++){
    a=0.95;
    /* Amostragem por importância*/
    P=0.0;
    for(i=0;i<N;i++){
      r=drand48();
      x[i]=(-1.0/a)*log(1.0-r*(1.0-exp(-a*PI)));
      P+=(f(x[i])/p(x[i],a));
    }
     
    I1=P/(1.0*N);
    s2=0.0;
    for(i=0;i<N;i++){
      s2=((f(x[i])/p(x[i],a))-I1)*((f(x[i])/p(x[i],a))-I1);
    }
    var1=s2/(1.0*(N-1));

    /* Amostragem uniforme */
    S=0;
    s1=0.0;
    s2=0.0;
    for(i=0;i<N;i++){
      x[i]=drand48()*PI;
      y=drand48();
      if(y <= f(x[i]))
	S++;
    }
    I2=(1.0*S*(xmax-xmin)*(ymax-ymin))/(1.0*N);
    s2=0.0;
    for(i=0;i<N;i++){
      s2=(x[i]-I2)*(x[i]-I2);
    }
    var2=s2/(1.0*(N-1));

    printf("%d %.12e %.12e \n",j, I1, I2);
  }
}
