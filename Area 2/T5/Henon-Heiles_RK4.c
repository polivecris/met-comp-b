// Kepler caótico usando RK4
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Aceleracao (relacionada a forca)
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
  int i, n, N;
  // Grandezas fisicas envolvidas
  double t,ti,tf,xo,x,y,yo,vx,vxo,vy,vyo,h,E,Eo;

  //Metodo Runge-Kutta de ordem 4
  double k1x, k2x, k3x, k4x;     // Relacionado a posicao
  double k1y, k2y, k3y, k4y;
  
  double k1vx, k2vx, k3vx, k4vx; // Relacionado a velocidade
  double k1vy, k2vy, k3vy, k4vy;
  
  FILE*RK4=fopen("RK4.dat","w");
  
  // Condições iniciais
  ti=0.0;
  tf=1.0E3;

  Eo=(1.0/12.0);
 
  xo=0.0;
  yo=0.02;

  vyo=-0.08;
  vxo=sqrt(2*Eo-vyo*vyo-yo*yo+(2.0/3.0)*yo*yo*yo);
  
  N=1.0E5;
  h=(tf-ti)/(1.0*N);
  
  // Valores iniciais
  x=xo;
  y=yo;
  vx=vxo;
  vy=vyo;
  E=Eo;
  
  t=ti;
    
  for(n=0;n<N;n++){
    fprintf(RK4,"%f %.12e %.12e %.12e %.12e %.12e\n",t,x,y,vx,vy,E);
    printf("%f %.12e %.12e %.12e %.12e\n",t,x,y,vx,vy);
    
    // Calculos de K1
    k1x=h*vx;
    k1y=h*vy;
    
    k1vx=h*ax(x,y);
    k1vy=h*ay(x,y);

    // Calculos de K2
    k2x=h*(vx+0.5*k1vx);
    k2y=h*(vy+0.5*k1vy);
    
    k2vx=h*ax(x+0.5*k1x,y+0.5*k1y);
    k2vy=h*ay(x+0.5*k1x,y+0.5*k1y);
    
    // Calculos de K3
    k3x=h*(vx+0.5*k2vx);
    k3y=h*(vy+0.5*k2vy);
    
    k3vx=h*ax(x+0.5*k2x,y+0.5*k2y);
    k3vy=h*ay(x+0.5*k2y,y+0.5*k2y);

    // Calculo de K4
    k4x=h*(vx+1.0*k3vx);
    k4y=h*(vy+1.0*k3vy);
    
    k4vx=h*ax(x+1.0*k3x,y+1.0*k3y);
    k4vy=h*ay(x+1.0*k3x,y+1.0*k3y);

    // Atualiza posições
    x=x+(1.0/6.0)*(k1x+2.0*k2x+2.0*k3x+k4x);
    y=y+(1.0/6.0)*(k1y+2.0*k2y+2.0*k3y+k4y);

    // Atualiza velocidades
    vx=vx+(1.0/6.0)*(k1vx+2.0*k2vx+2.0*k3vx+k4vx);
    vy=vy+(1.0/6.0)*(k1vy+2.0*k2vy+2.0*k3vy+k4vy);

    // Atualiza energia
    E=0.5*vx*vx+0.5*vy*vy+0.5*x*x+0.5*y*y+x*x*y-(1.0/3.0)*y*y*y;
    
    // Atualiza tempo
    t=(n+1)*h;
  }
  fprintf(RK4,"%f %.12e %.12e %.12e %.12e %.12e\n",t,x,y,vx,vy,E);
  printf("%f %.12e %.12e %.12e %.12e\n",t,x,y,vx,vy);
  return 0;
}
