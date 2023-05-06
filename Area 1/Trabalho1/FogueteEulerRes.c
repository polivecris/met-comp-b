// Lancamento de foguete sob gravidade em Euler
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Taxa de variação dv/dm 
double rate(double m,double v){
  double y,g=9.8,u=-2600.0,a=-1.42E0,c=1.0;
  y=g/a+c/a*v*v-u/m;
  return y;
}


int main(void){
  int i,n,N; // Variáveis de iteração
  double m,mi,mf,v,vo,h; // Grandezas físicas envolvidas + passo
  double c,g,a,u; // Grandezas especificas do problema
  
  FILE*Euler=fopen("RocketEuler.dat","w");
  FILE*erro=fopen("Eulerherros.dat","w+");

//  for(N=21;N<21000000;N=N*10){
    N=21000;
    mi=2.8E2; // Massa do foguete + combustível
    mf=0.7E2; // Massa do foguete após a queima do combustível

    h=(mi-mf)/(1.0*N);
  
    // Condições iniciais
    vo=0.0; // Velocidade inicial do foguete
    g=9.8; // Aceleração da gravidade (considerada constante)
    u=-2600.0; // Velocidade de exaustão 
    a=-1.42E0; // Taxa de queima de combustível
    c=1.0; // Coeficiente de arrasto da atmosfera
    v=vo;
    m=mi;

    for(n=0;n<N;n++){
      fprintf(Euler,"%.12e %.12e %.12e\n",m,v,rate(m,v));
      printf("%.12e %.12e %.12e\n",m,v,rate(m,v));
   
      v=v+rate(m,v)*h;
      
      m=mi-(n+1)*h;
    }
    fprintf(Euler,"%.12e %.12e %.12e\n",m,v,rate(m,v));
    printf("%.12e %.12e %.12e\n",m,v,rate(m,v));
    fprintf(erro,"%.12e %.12e %.12e %.12e\n",h,m,v,solution(m)-v);
  //}

  return 0;
}
