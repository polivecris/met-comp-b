// Pendulo Simples em Runge-Kutta 2
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Aceleracao (relacionada a forca)
double funcao(double t,double x, double v){
  double y, g=10.0, L=1.0;
  y=-g/L*sin(x);
  return y;
}

int main(){
  int i, n, N;
  // Grandezas fisicas envolvidas
  double t,ti,tf,xo,x,v,vo,h;

  //Metodo RK
  double k1x,k2x; // Relacionado a posicao
  double k1v,k2v; // Relacionado a velocidade

  // Grandezas especificas
  double g, L;
  
  FILE*RK2=fopen("RK2.dat","w");
  FILE*erro=fopen("erros.dat","w+");
  
  ti=0.0;
  tf=20.0;
  
  N=2000;
  h=(tf-ti)/(1.0*N);
  
  // Valores iniciais
  xo=1.5;
  vo=0.0;
  L=1.0;
  g=10.0;
  
  x=xo;
  v=vo;
  t=ti;
    
  for(n=0;n<N;n++){
    fprintf(RK2,"%f %.12e %.12e\n",t,x,v);
    printf("%f %.12e %.12e\n",t,x,v);

    k1x=h*v;
    k1v=h*funcao(t,x,v);
  
    k2x=h*(v+0.5*k1v);
    k2v=h*funcao(t+0.5*h,x+0.5*k1x,v+0.5*k1v);
    
    x=x+k2x;
    v=v+k2v;
    t=(n+1)*h;
  }
    
  fprintf(RK2,"%f %.12e %.12e\n",t,x,v);
  printf("%.12e %.12e %.12e\n",t,x,v);

  return 0;
}
