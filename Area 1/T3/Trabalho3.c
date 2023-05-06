// Trabalho 3 - Métodos Computacionais da Física B
// Cristiane de Paula Oliveira - 00261424
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


// Funcão y' do problema
double function(double t, double y){
  double f;
  f=-y+t+1;

  return f;
}


// Método do ponto médio
double midpoint(double t, double y, double h){
  double x, k1, k2;
  k1=function(t,y);
  k2=function(t+0.5*h,y+0.5*h*k1);  
  
  x=y+h*k2;

  return x;
}

// Metodo de Euler
double modified_euler(double t, double y, double h){
  double x, k1, k2;
  k1=function(t,y);
  k2=function(t+h,y+h*k1);
 
  x=y+0.5*h*k1+0.5*h*k2;
  
  return x;
}

// Solucao exata do problema
double solution(double t){
  double f;
  f=exp(-t)+t;
  return f;
}

int main(void){
  int n, N;  // Variável de iteração
  double t, y1, y2, yo, ti, tf, h; 
  // y1: solucão numérica com ponto médio
  // y2: solução numérica com Euler modificado

  FILE*erros=fopen("herros.dat","w+");   // Arquivo com erro global para diferentes h
  FILE*arq=fopen("resultados.dat","w+"); // Arquivo com os resultados de y1 e y2 para cada t


  for(N=1;N<1000000;N=N*10){ // Loop para variar h
    
    // Condições iniciais
    ti=0.0;
    tf=1.0;

    yo=1.0;

    h=(tf-ti)/(1.0*N);  // Tamanho de h

    y1=yo;
    y2=yo;
    t=ti;

    for(n=0;n<N;n++){        // Loop para resolver EDO
      y1=midpoint(t,y1,h);
      y2=modified_euler(t,y2,h);

      t=ti+(n+1)*h;
    }
    // Imprime no arquivo log de h, log dos erros
    fprintf(erros,"%.12e %.12e %.12e\n",log10(h),log10(fabs(solution(t)-y1)),log10(fabs(solution(t)-y2)));
  }


    // Escolhe-se h=0.1 para resolver a EDO
    N=10;

    // Condições iniciais
    ti=0.0;
    tf=1.0;

    yo=1.0;

    h=(tf-ti)/(1.0*N);   // Tamanho de h

    y1=yo;
    y2=yo;
    t=ti;

    for(n=0;n<N;n++){
      fprintf(arq,"%.12e %.16e %.16e %.16e\n", t, y1,y2,solution(t));
      y1=midpoint(t,y1,h);
      y2=modified_euler(t,y2,h);

      t=ti+(n+1)*h;
    }
    fprintf(arq,"%.12e %.16e %.16e %.16e\n",t,y1,y2,solution(t));

  return 0;
}
