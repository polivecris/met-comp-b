#include<stdio.h>
#include<math.h>

int main(){
  double x,xo,y,yo,a,b;
  int n, N;

  N=1E4;
  
  a=0.2; //1.4;
  b=-0.999; //0.9991; //0.3;

  xo=0.0;
  yo=0.0;

  //xo=0.63135448;
  //yo=0.18940634;
  
  for(n=0;n<N;n++){
    printf("%d %.12e %.12e \n",n,xo,yo);
    
    x=yo+1-a*xo*xo;
    y=b*xo;

    xo=x;
    yo=y;
  }
  
  return 0;
}
