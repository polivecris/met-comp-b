#include<stdio.h>
#include<stdlib.h>

double funcao(double t,double x){
  double y;
  y=x-(t*t)+1;
  return y;
}

double solucao(double t){
  double y;
  y=(t+1)*(t+1)-0.5*exp(t);
  return y;
}

double RK2(double t,double x, double h){
  double k1, k2;

  k1=funcao(t,x);
  k2=funcao(t+0.5*h,x+0.5*k1*h);

  x=x+(0*k1+1*k2)*h;

  return x;
}

double RK4(double t, double x, double h){
  double k1, k2, k3, k4;
  
  k1=funcao(t,x);
  k2=funcao(t+0.5*h,x+0.5*k1*h);
  k3=funcao(t+0.5*h,x+0.5*k2*h);
  k4=funcao(t+1.0*h,x+1.0*k3*h);
  
  x=x+1.0/6.0*(k1+2.0*k2+2.0*k3+k4)*h;
  
  return x;
}

int main(void){
  int i, n, N;
  double t,xo,ti,tf,h;
  double err=1E-2;
  double xRK2, xRK2_2, errRK2;
  double xRK4, xRK4_2, errRK4;
  
  // Arquivos onde escrevo as coisas
  FILE*RK2=fopen("RK2.dat","w");
  FILE*RK4=fopen("RK4.dat","w");

  xo=0.5;
  ti=0.0;
  tf=2.0;

  xRK2=xo;
  xRK4=xo;

  t=ti;
  for(n=0;n<N;n++){
    ///Calcula RK2 com h
    ///Calcula RK2 com h/2 (duas vezes)
    // Calcula o erro
    // Decide se mantém x de h ou x de h/2
    t=ti+h;
  }

  // Redefine tudo para RK4
  for(n=0;n<N;n++){
    ///Calcula RK4 com h
    ///Calcula RK4 com h/2 (duas vezes)
    // Calcula o erro
    // Decide se mantém x de h ou x de h/2
    t=ti+h;
  }
  
  return 0;
}
