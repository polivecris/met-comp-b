// Pendulo Simples em Velocity Verlet, RK2 e RK4
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Aceleracao (relacionada a forca)
double funcao(double t,double x, double v){
  double y;
  y=-g/L*sin(x);
  return y;
}

// Solucao exata (para comparar erros)
double sol(double t){
  double y;
  y=(t+1)*(t+1)-0.5*exp(t);
  return y;
}

double VelVerlet(double t, double x, double v, double h){
  ao=funcao(t,x,v);
  x=x+v*h+0.5*ao*h*h;
  a=funcao(t,x,v);
  v=v+0.5*(ao+a)*h;
}

double RK2Central(double t,double x, double v, double h){
  double k1x,k2x; // Relacionado a posicao
  double k1v,k2v; // Relacionado a velocidade

  k1x=h*v;
  k1v=h*funcao(t,x,v);
  
  k2x=h*(v+0.5*k1v);
  k2v=h*funcao(t+0.5*h,x+0.5*k1x,v+0.5*k1v);
    
  x=x+k2x;
  v=v+k2v;
  return x;
}

double RK4Runge(double t, double x, double v, double h){
  double k1x, k2x, k3x, k4x; // Relacionado a posicao
  double k1v, k2v, k3v, k4v; // Relacionado a velocidade
  
  k1x=h*v;
  k1v=h*funcao(t,x,v);

  k2x=h*(v+0.5*k1v);
  k2v=h*funcao(t+0.5*h,x+0.5*k1x,v+0.5*k1v);

  k3x=h*(v+0.5*k2v);
  k3v=h*funcao(t+0.5*h,x+0.5*k2x,v+0.5*k2v);

  k4x=h*(v+1.0*k3v);
  k4v=h*funcao(t+1.0*h,x+1.0*k3x,v+1.0*k3v);
  
  x=x+(1.0/6.0)*(k1x+2.0*k2x+2.0*k3x+k4x);
  v=v+(1.0/6.0)*(k1v+2.0*k2v+2.0*k3v+k4v);
    
  return x;
}

int main(){
  int i, n, N;
  double t,xo,x4,x2C,x2H,h,ti,tf,err2C,err2H,err4;
  
  FILE*RK2=fopen("RK2.dat","w");
  FILE*RK4=fopen("RK4.dat","w");
  FILE*erro=fopen("erros.dat","w+");
  
  for(N=20;N<2000000;N=N*10){
    h=2.0/(1.0*N);

    // Valores iniciais
    xo=3.0;
    vo=0.0;
    L=1.0;
    g=10.0;
    
    ti=0.0;
    tf=2.0;
    
    x4=xo;
    x2C=xo;
    t=ti;
    
    for(n=0;n<N;n++){
      fprintf(RK2,"%f %.12e\n",t,x2C);
      fprintf(RK4,"%f %.12e\n",t,x4);
      x2C=RK2Central(t,x2C,h);
      x4=RK4Runge(t,x4,h);
      t=(n+1)*h;
    }
    
    fprintf(RK2,"%f %.12e\n",tf,x2C);
    fprintf(RK4,"%f %.12e\n",tf,x4);

    printf("%.12e %.12e %.12e\n",h,t,x2C);
    printf("%.12e %.12e %.12e\n",h,t,x4);

    // Calculos do erro
    // err2C=fabs(sol(2.0)-x2C);
    // err2H=fabs(sol(2.0)-x2H);
    // err4=fabs(sol(2.0)-x4);
    // fprintf(erro,"%.12e %.12e %.12e %.12e\n",h, err2H,err2C,err4);

    h=h/10;
  }
  return 0;
}
