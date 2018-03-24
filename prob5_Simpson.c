#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void simpson(double ,double ,int);//通常のシンプソン則
void simpson_improved(double ,double ,int); //小さい順に足すシンプソン則
//1つ目の変数は積分範囲の下限,2つ目の変数は積分範囲の上限,3つ目の変数は分割数

//被積分関数
double function (double);

int main(int argc, char *argv[]){
  double integral; // 積分結果
  double x_min = 0;//積分範囲の最小値
  double x_max = M_PI/2.0;//積分範囲の最大値
  int div_Num = 100; //分割数 シンプソン則なので偶数
  int method; //1:通常のシンプソン則 2:小さい順に足すシンプソン則
  double x;
  int i;

  method = atoi(argv[1]);

  for(i=1;i<11;i++){
    div_Num *= 2;
    if(method == 1){
      simpson(x_min,x_max,div_Num);
    }else{
      simpson_improved(x_min,x_max,div_Num);
    }
  }

  return 0;
}

void simpson(double x_min,double x_max,int div_Num){
  double integral = 0; // 積分結果
  double h;// 分割数
  double x;
  int i;

  h = (x_max - x_min) / div_Num;
  x = x_min;
  integral = function(x);
  x += h;

  for (i=1; i<div_Num; i++) {
    integral += (3 + pow(-1,i+1)) * function(x);
    x += h;
  }

  integral += function(x);
  integral *= h/ 3.0;

  printf("%lf %.20lf\n",h,fabs(1-integral));
}

void simpson_improved(double x_min,double x_max,int div_Num){
  double integral = 0; // 積分結果
  double h; // 分割数
  double x;
  int i;

  h = (x_max - x_min) / div_Num;
  x = x_min;
  integral = function(x_min) + function(x_max);
  x += h;

  for (i=1; i<div_Num/2; i++) {
    integral += (3 + pow(-1,i+1)) * (function(x) + function(x_max - x));
    x += h;
  }

  if(div_Num % 4 == 0){
    integral += 2*function(x);
  }else{
    integral += 4*function(x);
  }

  integral *= h/ 3.0;

  printf("%lf %.20lf\n",h,fabs(1-integral));
}

double function (double x){
  double result;
  result = sin(2*x);
  return result;
}