#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double funcao(double t,double x){
  double y;
  y=x-(t*t)+1;
  return y;
}

double sol(double t){
  double y;
  y=(t+1)*(t+1)-0.5*exp(t);
  return y;
}

double RK2Central(double t,double x, double h){
  double k1, k2;
  
  k1=funcao(t,x);
  k2=funcao((t+0.5*h),(x+0.5*k1*h));

  x=x+k2*h;

  return x;
}

double RK2Heun(double t,double x, double h){
  double k1, k2;

  k1=funcao(t,x);
  k2=funcao(t+h,x+k1*h);

  x=x+(0.5*k1+0.5*k2)*h;

  return x;
}

double RK4Runge(double t, double x, double h){
  double k1, k2, k3, k4;
  
  k1=funcao(t,x);
  k2=funcao(t+0.5*h,x+0.5*k1*h);
  k3=funcao(t+0.5*h,x+0.5*k2*h);
  k4=funcao(t+1.0*h,x+1.0*k3*h);
  
  x=x+1.0/6.0*(k1+2.0*k2+2.0*k3+k4)*h;
  
  return x;
}

int main(){
  int i, n, N;
  double t,xo,x4,x2C,x2H,h,ti,tf,err2C,err2H,err4;
  
  FILE*RK2=fopen("RK2.dat","w");
  FILE*RK4=fopen("RK4.dat","w");
  FILE*erro=fopen("erros.dat","w+");
  
  
  //for(i=1;i<7;i++){
  for(N=20;N<2000000;N=N*10){
    h=2.0/(1.0*N);
    
    xo=0.5;
    ti=0.0;
    tf=2.0;
    
    x4=xo;
    x2C=xo;
    x2H=xo;
    t=ti;
    for(n=0;n<N;n++){
      fprintf(RK2,"%f %.12e\n",t,x2C);
      fprintf(RK4,"%f %.12e\n",t,x4);
      x2C=RK2Central(t,x2C,h);
      x2H=RK2Heun(t,x2H,h);
      x4=RK4Runge(t,x4,h);
      t=(n+1)*h;
    }
    
    fprintf(RK2,"%f %.12e\n",tf,x2C);
    fprintf(RK4,"%f %.12e\n",tf,x4);

    printf("%.12e %.12e %.12e\n",h,t,x2C);
    printf("%.12e %.12e %.12e\n",h,t,x4);
    
    err2C=fabs(sol(t)-x2C);
    err2H=fabs(sol(t)-x2H);
    err4=fabs(sol(t)-x4);
    fprintf(erro,"%.12e %.12e %.12e %.12e\n",h, err2H,err2C,err4);

    h=h/10;
  }
  return 0;
}
