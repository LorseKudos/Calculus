#include <stdio.h>
#include <math.h>

void trapezium(double, double, double);//台形則
//1つ目の変数は積分範囲の下限,2つ目の変数は積分範囲の上限,3つ目の変数は分割数

double function (double);// 被積分関数

int main(void){
  int i;
  double x_min = -1; //積分範囲の最小値
  double x_max = 0.999999; //積分範囲の最大値
  double h = 0.000001; //刻み幅

  trapezium(x_min,x_max,h);

  return 0;
}

void trapezium(double x_min,double x_max,double h){
  double integral = 0; // 積分結果
  double div_Num; // 分割数
  double x;
  int i;

  div_Num = (x_max - x_min) / h;
  x = x_min;
  integral = function(x);
  x += h;

  for (i=1; i<div_Num; i++) {
    integral += function(x);
    x += h;
  }

  integral += function(x)/2.0;
  integral *= h;

  printf("%.20lf\n",integral);
}

double function (double x){
  double result;
  result = exp(-(1+x)/(1-x)) * 2 /pow(1-x,2);
  return result;
}