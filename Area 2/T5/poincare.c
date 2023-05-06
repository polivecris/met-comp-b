// Hénon-Heiles caótico usando Velocity-Verlet
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Aceleracao 
double ax(double x, double y){
  double accel;
  // x"=-x-2xy
  accel=-x-2.0*x*y;
  return accel;
}

double ay(double x, double y){
  double accel;
  // x"=-y-x²+y²
  accel=-y-x*x+y*y;
  return accel;
}

int main(){
  int i, I, j, J, n, N;
  // Grandezas fisicas envolvidas
  double t,ti,tf,xo,x,y,yo,vx,vxo,vy,vyo,h,E,Eo,aox,aoy;

  // Arquivos onde serão salvos as coisas
  FILE*arq;
  char nome[30];
  
  // Condições iniciais
  ti=0.0;
  tf=1.0E4;

  Eo=(1.0/6.0);
  sprintf(nome,"poincare%.5lf.dat",Eo);	
  arq=fopen(nome,"w");
  
  I=13;
  J=13;
  
  xo=0.0;
  vyo=-0.60;
  for(i=0;i<I;i++){
  yo=-0.60;
  for(j=0;j<J;j++){
  printf("%lf\t%lf\n",yo,vyo);
  vxo=sqrt(2*Eo-vyo*vyo-yo*yo+(2.0/3.0)*yo*yo*yo);
  
  N=1.0E6;
  h=(tf-ti)/(1.0*N);
  
  // Valores iniciais
  x=xo;
  y=yo;
  vx=vxo;
  vy=vyo;
  E=Eo;
  
  t=ti;
    
  for(n=0;n<N;n++){
    if(fabs(x)<1.0E-3 && vx>0){
      fprintf(arq,"%f %.12e %.12e %.12e %.12e %.12e\n",t,x,y,vx,vy,E);
    }
    
    // Acelerações instantâneas
    aox=ax(x,y);
    aoy=ay(x,y);
    
    // Posicao no fim do intervalo
    x=x+vx*h+0.5*aox*h*h;
    y=y+vy*h+0.5*aoy*h*h;
    
    // Velocidade final
    vx=vx+0.5*(aox+ax(x,y))*h;
    vy=vy+0.5*(aoy+ay(x,y))*h;
    
    
    // Atualiza energia
    E=0.5*vx*vx+0.5*vy*vy+0.5*x*x+0.5*y*y+x*x*y-(1.0/3.0)*y*y*y;
    
    // Atualiza tempo
    t=(n+1)*h;
  }
  if(fabs(x)<1.0E-3 && vx>0){
    fprintf(arq,"%f %.12e %.12e %.12e %.12e %.12e\n",t,x,y,vx,vy,E);
  }
  yo=yo+0.10;
  }
  printf("\n");
  vyo=vyo+0.10;
 }	 
  return 0;
}
