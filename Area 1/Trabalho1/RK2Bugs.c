// Lancamento de foguete sob gravidade em Runge-Kutta de ordem 2
// Programa funcionando só falta deixar bonito
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Taxa de variação dv/dm 
double rate(double m,double v){
  double y,g=9.8,u=-2600.0,a=-1.42E4;
  y=g/a-u/m;
  return y;
}

// Solução analítica
double solution(double m){
  double y,g=9.8,u=-2600.0,a=-1.42E4, mi=2.8E6;
  y=g/a*(mi-m)-u*log(mi/m);
  return y;
}

int main(void){
  int i,n,N; // Variáveis de iteração
  double m,mi,mf,v,vo,h; // Grandezas físicas envolvidas + passo
  double c,g,a,u; // Grandezas especificas do problema
  double k1,k2; // k's do método de Runge-Kutta
  
  FILE*RK2=fopen("RocketRK2.dat","w");
  FILE*erro=fopen("RK2herros.dat","w+");
  
  mi=2.8E6;
  mf=0.7E6;
  
  N=1000*2.1;
  h=(mi-mf)/(1.0*N);
  
  // Condições iniciais
  vo=0.0; // Velocidade inicial do foguete
  g=9.8; // Aceleração da gravidade (considerada constante)
  u=-2600.0; // Velocidade de exaustão 
  a=-1.42E4; // Taxa de queima de combustível
  
  v=vo;
  m=mi;
  
  for(n=0;n<N;n++){
    fprintf(RK2,"%.12e %.12e %.12e\n",m,v,rate(m,v));
    printf("%.12e %.12e %.12e\n",m,v,rate(m,v));
    
    k1=rate(m,v)*h;
    k2=rate(m+0.5*h,v+0.5*k1)*h;
    
    v=v+k2;
    
    m=m-h;
  }
  
  fprintf(RK2,"%.12e %.12e %.12e\n",m,v,rate(m,v));
  printf("%.12e %.12e %.12e\n",m,v,rate(m,v));
  
  return 0;
}
