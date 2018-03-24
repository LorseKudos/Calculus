#include <stdio.h>
#include <math.h>

int main(void){
  float a,b,c,sd,alpha,beta;

  a = 1; //x^2の係数
  b= 1000.001; //x^1の係数
  c = 1; //定数項

  sd = sqrt(b*b - 4*a*c); //判別式の根号

  alpha = (-b + sd) / (2*a);
  beta = (-b - sd) / (2*a); //2次方程式の解の公式

  printf("%lfx^2+%lfx+%lfの解\n",a,b,c);

  printf("桁落ちが生じる:alpha = %.10lf, beta = %lf\n",alpha,beta);

  alpha = -2*c/(b + sd); //桁落ちを回避するため変形した公式

  printf("桁落ちが生じない:alpha = %.10lf, beta = %lf\n",alpha,beta);

  return 0;
}