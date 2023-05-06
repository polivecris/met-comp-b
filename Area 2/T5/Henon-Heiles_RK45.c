// Kepler caótico usando RK4-Fehlberg
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
  int FLAG=0;
  double t,ti,tf;
  double xo,x, x_4,x_5;
  double yo,y, y_4, y_5;
  double vxo,vx,vx_4,vx_5;
  double vyo,vy,vy_4,vy_5;
  double h,h_min,h_max;
  double R,Rx,Ry,Rvx,Rvy,Rp,Rv;
  double s,TOL=1.0E-6;
  double E,Eo;
  
  //Metodo Runge-Kutta-Fehlberg
  double k1x, k2x, k3x, k4x, k5x, k6x;     // Relacionado a posicao
  double k1y, k2y, k3y, k4y, k5y, k6y;
  
  double k1vx,k2vx,k3vx,k4vx,k5vx,k6vx; // Relacionado a velocidade
  double k1vy,k2vy,k3vy,k4vy,k5vy,k6vy;
  
  FILE*RK45=fopen("RK45.dat","w");
  
  // Condições iniciais
  ti=0.0;
  tf=1.0E3;

  Eo=(1.0/12.0);
 
  xo=0.0;
  yo=0.02;

  vyo=-0.08;
  vxo=sqrt(2*Eo-vyo*vyo-yo*yo+(2.0/3.0)*yo*yo*yo);

  h=1.0E-3;
  
  h_min=1.0E-6;
  h_max=1.0E-2;
  
  // Valores iniciais
  x=xo;
  y=yo;
  vx=vxo;
  vy=vyo;
  E=Eo;
  
  t=ti;
  x=xo;
  y=yo;
  
  while (FLAG==0){
    if(fabs(x)<0.001 && vx>0){
      fprintf(RK45,"%f %.12e %.12e %.12e %.12e %.12e\n",t,x,y,vx,vy,E);
      printf("%f %.12e %.12e %.12e %.12e\n",t,x,y,vx,vy);
    }
    // Calculos de K1
    k1x=h*vx;
    k1y=h*vy;
    
    k1vx=h*ax(x,y);
    k1vy=h*ay(x,y);

    // Calculos de K2
    k2x=h*(vx+
	   (1.0/4.0)*k1vx);
    k2y=h*(vy+
	   (1.0/4.0)*k1vy);
    
    k2vx=h*ax(x+
	      (1.0/4.0)*k1x,
	      y+
	      (1.0/4.0)*k1y);
    
    k2vy=h*ay(x+
	      (1.0/4.0)*k1x,
	      y+
	      (1.0/4.0)*k1y);
    
    // Calculos de K3
    k3x=h*(vx+
	   (3.0/32.0)*k1vx+
	   (9.0/32.0)*k2vx);

    k3y=h*(vy+
	   (3.0/32.0)*k1vy+
	   (9.0/32.0)*k2vy);
    
    k3vx=h*ax(x+
	      (3.0/32.0)*k1x+
	      (9.0/32.0)*k2x,
	      y+
	      (3.0/32.0)*k1y+
	      (9.0/32.0)*k2y);

    k3vy=h*ay(x+
	      (3.0/32.0)*k1x+
	      (9.0/32.0)*k2x,
	      y+
	      (3.0/32.0)*k1y+
	      (9.0/32.0)*k2y);

    // Calculo de K4
    k4x=h*(vx+
	   (1932.0/2197.0)*k1vx+
	   (-7200.0/2197.0)*k2vx+
	   (7296.0/2197.0)*k3vx);

    k4y=h*(vy+
	   (1932.0/2197.0)*k1vy+
	   (-7200.0/2197.0)*k2vy+
	   (7296.0/2197.0)*k3vy);
    
    k4vx=h*ax(x+
	      (1932.0/2197.0)*k1x+
	      (-7200.0/2197.0)*k2x+
	      (7296.0/2197.0)*k3x,
	      y+
	      (1932.0/2197.0)*k1y+
	      (-7200.0/2197.0)*k2y+
	      (7296.0/2197.0)*k3y);
    
    k4vy=h*ay(x+
	      (1932.0/2197.0)*k1x+
	      (-7200.0/2197.0)*k2x+
	      (7296.0/2197.0)*k3x,
	      y+
	      (1932.0/2197.0)*k1y+
	      (-7200.0/2197.0)*k2y+
	      (7296.0/2197.0)*k3y);

    // Calculo de K5
    k5x=h*(vx+
	   (439.0/216.0)*k1vx+
	   (-8.0)*k2vx+
	   (3680.0/513.0)*k3vx+
	   (-845.0/4104.0)*k4vx);
    
    k5y=h*(vy+
	   (439.0/216.0)*k1vy+
	   (-8.0)*k2vy+
	   (3680.0/513.0)*k3vy+
	   (-845.0/4104.0)*k4vy);
    
    k5vx=h*ax(x+
	      (439.0/216.0)*k1x+
	      (-8.0)*k2x+
	      (3680.0/513.0)*k3x+
	      (-845.0/4104.0)*k4x,
	      y+
	      (439.0/216.0)*k1y+
	      (-8.0)*k2y+
	      (3680.0/513.0)*k3y+
	      (-845.0/4104.0)*k4y);

    k5vy=h*ay(x+
	      (439.0/216.0)*k1x+
	      (-8.0)*k2x+
	      (3680.0/513.0)*k3x+
	      (-845.0/4104.0)*k4x,
	      y+
	      (439.0/216.0)*k1y+
	      (-8.0)*k2y+
	      (3680.0/513.0)*k3y+
	      (-845.0/4104.0)*k4y);

    // Calculo de K6
    k6x=h*(vx+
	   (-8.0/27.0)*k1vx+
	   (2.0)*k2vx+
	   (-3544.0/2565.0)*k3vx+
	   (1859.0/4104.0)*k4vx+
	   (-11.0/40.0)*k5vx);

    k6y=h*(vy+
	   (-8.0/27.0)*k1vy+
	   (2.0)*k2vy+
	   (-3544.0/2565.0)*k3vy+
	   (1859.0/4104.0)*k4vy+
	   (-11.0/40.0)*k5vy);
    
    k6vx=h*ax(x+
	      (-8.0/27.0)*k1x+
	      (2.0)*k2x+
	      (-3544.0/2565.0)*k3x+
	      (1859.0/4104.0)*k4x+
	      (-11.0/40.0)*k5x,
	      y+
	      (-8.0/27.0)*k1y+
	      (2.0)*k2y+
	      (-3544.0/2565.0)*k3y+
	      (1859.0/4104.0)*k4y+
	      (-11.0/40.0)*k5y);

    k6vy=h*ay(x+
	      (-8.0/27.0)*k1x+
	      (2.0)*k2x+
	      (-3544.0/2565.0)*k3x+
	      (1859.0/4104.0)*k4x+
	      (-11.0/40.0)*k5x,
	      y+
	      (-8.0/27.0)*k1y+
	      (2.0)*k2y+
	      (-3544.0/2565.0)*k3y+
	      (1859.0/4104.0)*k4y+
	      (-11.0/40.0)*k5y);
    
    // Atualiza posição x
    x_5=x+
      (16.0/135.0)*k1x+
      (6656.0/12825.0)*k3x+
      (28561.0/56430.0)*k4x+
      (-9.0/50.0)*k5x+
      (2.0/55.0)*k6x;
    
    x_4=x+
      (25.0/216.0)*k1x+
      (1408.0/2565.0)*k3x+
      (2197.0/4101.0)*k4x+
      (-1.0/5.0)*k5x;
    
    // Atualiza posição y
    y_5=y+
      (16.0/135.0)*k1y+
      (6656.0/12825.0)*k3y+
      (28561.0/56430.0)*k4y+
      (-9.0/50.0)*k5y+
      (2.0/55.0)*k6y;
    
    y_4=y+
      (25.0/216.0)*k1y+
      (1408.0/2565.0)*k3y+
      (2197.0/4101.0)*k4y+
      (-1.0/5.0)*k5y;
    
    // Atualiza velocidade vx
    vx_5=vx+
      (16.0/135.0)*k1vx+
      (6656.0/12825.0)*k3vx+
      (28561.0/56430.0)*k4vx+
      (-9.0/50.0)*k5vx+
      (2.0/55.0)*k6vx;

    vx_4=vx+
      (25.0/216.0)*k1vx+
      (1408.0/2565.0)*k3vx+
      (2197.0/4101.0)*k4vx+
      (-1.0/5.0)*k5vx;

    // Atualiza velocidade vy
    vy_5=vy+
      (16.0/135.0)*k1vy+
      (6656.0/12825.0)*k3vy+
      (28561.0/56430.0)*k4vy+
      (-9.0/50.0)*k5vy+
      (2.0/55.0)*k6vy;

    vy_4=vy+
      (25.0/216.0)*k1vy+
      (1408.0/2565.0)*k3vy+
      (2197.0/4101.0)*k4vy+
      (-1.0/5.0)*k5vy;

    // Calcula erros correntes
    Rx=fabs(x_5-x_4);
    Ry=fabs(x_5-x_4);
    Rvx=fabs(vx_5-vx_4);
    Rvy=fabs(vy_5-vy_4);

    if(Rx >= Ry)
      Rp=Rx;
    else
      Rp=Ry;

    if(Rvx >= Rvy)
      Rv=Rvx;
    else
      Rv=Rvy;

    if(Rp >= Rv)
      R=Rp;
    else
      R=Rv;

    if(R <= TOL){
      t=t+h;
      
      x=x_4;
      y=y_4;
      vx=vx_4;
      vy=vy_4;
      
      // Atualiza energia
      E=0.5*vx*vx+0.5*vy*vy+0.5*x*x+0.5*y*y+x*x*y-(1.0/3.0)*y*y*y;
      
      fprintf(RK45,"%f %.12e %.12e %.12e %.12e %.12e\n",t,x,y,vx,vy,E);
      printf("%f %.12e %.12e %.12e %.12e\n",t,x,y,vx,vy);
      s=pow(0.5*(TOL/R),1.0/4.0);
      h=s*h;
    }
    else
      {
	s=pow(0.5*(TOL/R),1.0/4.0);	
	h=s*h;
      }
    if(h > h_max)
      h=h_max;
    if(t >= tf)
      FLAG=1;
    else if(t+h > tf)
      h=tf-t; 
    else if(h < h_min)
      FLAG=1;
  }
  
  return 0;
}
