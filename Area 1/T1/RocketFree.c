// Lancamento de foguete no espaço livre em Euler
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Taxa de variação dv/dm 
double rate(double m,double v){
  double y,g=9.8,u=2600.0,a=1.42E0;
  y=-u/m;
  return y;
}

// Solução analitica
double solution(double m){
  double y,g=9.8,u=2600.0,a=1.42E0, mi=2.8E2,vi=0.0;
  y=vi-u*log(m/mi);
  return y;
}

int main(void){
  int i,n,N; // Variáveis de iteração
  double m,mi,mf,v,vo,h; // Grandezas físicas envolvidas + passo
  double c,g,a,u; // Grandezas especificas do problema
  double k1,k2,k3,k4; // k's do método de Runge-Kutta
  
  // Arquivos onde serão salvos as coisas
  FILE*Euler=fopen("dados/RocketEulerFree.dat","w");      //Euler
  FILE*RK2=fopen("dados/RocketRK2Free.dat","w");          //Runge-Kutta 2
  FILE*RK4=fopen("dados/RocketRK4Free.dat","w");          //Runge-Kutta 4


    //*********************************************************************
    // A partir daqui o método é Euler
    //*********************************************************************

    //  for(N=21;N<21000000;N=N*10){
    N=210;    // Numero de passos
    mi=2.8E2; // [1E4 kg] Massa do foguete + combustível
    mf=0.7E2; // [1E4 kg] Massa do foguete após a queima do combustível

    h=(mf-mi)/(1.0*N); // Passo
  
    // Condições iniciais
    vo=0.0;    // [m/s] Velocidade inicial do foguete
    g=9.8;     // [m/s^2] Aceleração da gravidade (considerada constante)
    u=2600.0;  // [m/s] Velocidade de exaustão 
    a=1.42E0;  // [1E4 kg/s] Taxa de queima de combustível
  
    v=vo;
    m=mi;

    for(n=0;n<N;n++){
      fprintf(Euler,"%.12e %.12e %.12e %.12e\n",m,v,solution(m),rate(m,v));
      printf("%.12e %.12e %.12e\n",m,v,rate(m,v));
   
      v=v+rate(m,v)*h;
      
      m=mi+(n+1)*h;
    }
    fprintf(Euler,"%.12e %.12e %.12e %.12e\n",m,v,solution(m),rate(m,v));
    printf("%.12e %.12e %.12e\n",m,v,rate(m,v));
    //fprintf(erro,"%.12e %.12e %.12e %.12e\n",h,m,v,solution(m)-v);
//  }


    
    //*********************************************************************
    // A partir daqui o método é RK2
    //*********************************************************************
  
    //  for(N=21;N<21000000;N=N*10){
    N=210;    // Numero de passos
    mi=2.8E2; // [1E4 kg] Massa do foguete + combustível
    mf=0.7E2; // [1E4 kg] Massa do foguete após a queima do combustível

    h=(mf-mi)/(1.0*N); // Passo
  
    // Condições iniciais
    vo=0.0;    // [m/s] Velocidade inicial do foguete
    g=9.8;     // [m/s^2] Aceleração da gravidade (considerada constante)
    u=2600.0;  // [m/s] Velocidade de exaustão 
    a=1.42E0;  // [1E4 kg/s] Taxa de queima de combustível
  
    v=vo;
    m=mi;

    for(n=0;n<N;n++){
      fprintf(RK2,"%.12e %.12e %.12e %.12e\n",m,v,solution(m),rate(m,v));
      printf("%.12e %.12e %.12e\n",m,v,rate(m,v));
   
      k1=rate(m,v)*h;
      k2=rate(m+0.5*h,v+0.5*k1)*h;
    
      v=v+k2;
    
      m=mi+(n+1)*h;
    }
    fprintf(RK2,"%.12e %.12e %.12e %.12e\n",m,v,solution(m),rate(m,v));
    printf("%.12e %.12e %.12e\n",m,v,rate(m,v));
    //fprintf(erro,"%.12e %.12e %.12e %.12e\n",h,m,v,solution(m)-v);
//  }


    
    //*********************************************************************
    // A partir daqui o método é RK4
    //*********************************************************************

    //  for(N=21;N<21000000;N=N*10){
    N=210;    // Numero de passos
    mi=2.8E2; // [1E4 kg] Massa do foguete + combustível
    mf=0.7E2; // [1E4 kg] Massa do foguete após a queima do combustível

    h=(mf-mi)/(1.0*N); // Passo
  
    // Condições iniciais
    vo=0.0;    // [m/s] Velocidade inicial do foguete
    g=9.8;     // [m/s^2] Aceleração da gravidade (considerada constante)
    u=2600.0;  // [m/s] Velocidade de exaustão 
    a=1.42E0;  // [1E4 kg/s] Taxa de queima de combustível
  
    v=vo;
    m=mi;

    for(n=0;n<N;n++){
      fprintf(RK4,"%.12e %.12e %.12e %.12e\n",m,v,solution(m),rate(m,v));
      printf("%.12e %.12e %.12e\n",m,v,rate(m,v));
    
      k1=rate(m,v)*h;
      k2=rate(m+0.5*h,v+0.5*k1)*h;
      k3=rate(m+0.5*h,v+0.5*k2)*h;
      k4=rate(m+1.0*h,v+1.0*k3)*h;
  
      v=v+(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);

      m=mi+(n+1)*h;
    }
    fprintf(RK4,"%.12e %.12e %.12e %.12e\n",m,v,solution(m),rate(m,v));
    printf("%.12e %.12e %.12e\n",m,v,rate(m,v));
    //fprintf(erro,"%.12e %.12e %.12e %.12e\n",h,m,v,solution(m)-v);
//  }
   
  return 0;
}
