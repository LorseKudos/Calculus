#include <stdio.h>
#include <math.h>

void trapezium(double, double, double); //台形則
//1つ目の変数は積分範囲の下限,2つ目の変数は積分範囲の上限,3つ目の変数は分割数

double function (double);// 被積分関数

int main(void){
  int i;
  double x_min = 0; //積分範囲の最小値
  double x_max = 0; //積分範囲の最大値
  double h = 0.001; //刻み幅

  for(i=0;i<105;i++){
    trapezium(x_min,x_max,h);

    if(i < 100){
      x_max += 0.1;
    }else {
      x_max *= 10;
    }
  }

  return 0;
}

void trapezium(double x_min,double x_max,double h){
  double integral = 0; // 積分結果
  double div_Num; // 分割数
  double x;
  int i;

  div_Num = (x_max - x_min) / h;
  x = x_max;
  integral = function(x)/2.0;
  x -= h;

  for (i=1; i<div_Num; i++) {
    integral += function(x);
    x -= h;
  }

  integral += function(x)/2.0;
  integral *= h;

  printf("%lf %.20lf\n",x_max,integral);
}

double function (double x){
  double result;
  result = exp(-x);
  return result;
}