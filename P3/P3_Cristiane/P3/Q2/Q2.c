#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
 
#define PI acos(-1.0)
#define L 5.0
#define n 50

double f(double x){
  double y;
  y=3*(1-x*x/25);
  return y;
}

double p(double x){
  double y;
  y=(PI/(4*L))*cos((PI*x)/(2*L));
  return y;
}

void main(void){
  double x,y,xmax,xmin,ymax,ymin,r,dx;
  double I1,I2,I3,M,P;
  double s1,s2, var1,var2,var3;
  int i,j,k,hist[n],N,S;
   
  /* Semente para o número aleatório*/
  srand48(time(NULL));
   
  xmin=-L;
  xmax=L;
  ymin=0;
  ymax=3;

  N=10;
  for(k=0;k<7;k++){
    /* Amostragem uniforme */
    S=0;
    s1=0.0;
    s2=0.0;
    for(i=0;i<N;i++){
      x=(drand48()-0.5)*10;
      y=drand48()*3;
      if(y <= f(x)){
	S++;
	s1+=x;
	s2+=x*x;
      }
    }
    I1=(1.0*S*(xmax-xmin)*(ymax-ymin))/(1.0*N);
    var1=s2/(1.0*N)-(s1/(1.0*N))*(s1/(1.0*N));
    
    /* Amostragem simples*/
    M=0.0;
    s1=0.0;
    s2=0.0;
    for(i=0;i<N;i++){
      x=(drand48()-0.5)*10;
      M+=f(x);
      s1+=f(x);
      s2+=f(x)*f(x);
    }
    I2=M*(xmax-xmin)/(1.0*N);
    var2=s2/(1.0*N)-(s1/(1.0*N))*(s1/(1.0*N));
   
    /* Amostragem por importância*/
    P=0.0;
    s1=0.0;
    s2=0.0;
    for(i=0;i<N;i++){
      r=drand48();
      x=((2.0*L)/PI)*asin(2.0*r-1);
      P+=(f(x)/p(x));
      s1+=(f(x)/p(x));
      s2+=(f(x)/p(x))*(f(x)/p(x));
    }
    I3=P/(1.0*N);
    var3=s2/(1.0*N)-(s1/(1.0*N))*(s1/(1.0*N));
    
    printf("%d %lf %lf %lf %.12e %.12e %.12e\n",
	   N,I1,I2,I3,var1,var2,var3);
    
    /* Atualiza N */
    N=N*10;
  }
}
