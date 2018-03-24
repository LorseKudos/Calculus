#include <stdio.h>
#include <math.h>

#define T_MIN 0.0 // 積分範囲の最小値
#define T_MAX 1.0 // 積分範囲の最大値

double function (double); // 被積分関数
double simpson (double ,double); //シンプソン則 1つ目の変数は積分区間の上限,2つ目の変数は刻み幅の値

double a,b; //正則化済み不完全ベータ関数のパラメータ

int main(void){
  double h = 0.0001; // 刻み幅

  double t,x;
  double denomi,nume; //分母,分子
  double result; //正則化済み不完全ベータ関数
  int i; //ループ変数

  a = 2;
  b = 3;

  denomi = simpson(1.0,h);

  for(i=0;i<101;i++){
    x = 0.01 * (double) i;
    nume = simpson(x,h);
    result = nume/denomi;
    printf("%lf %lf\n",x,result);
  }

  nume = simpson(0.4,h);

  printf("%lf\n",nume/denomi);

  return 0;
}

double function (double t){
  double result;
  result = pow(t,a-1) * pow(1-t,b-1);
  return result;
}

double simpson(double x,double h){
  double integral; //積分結果
  int div_Num; // 分割数
  double t;
  int i;
  div_Num = (x - T_MIN) / h;
  t = T_MIN;
  integral = function(1e-10);
  t += h;

  if(x == 0) return 0;

  for (i=1; i<div_Num; i++) {
    integral += (3 + pow(-1,i+1))*function(t);
    t += h;
  }

  integral += function(1 - 1e-16);
  integral *= h/3.0;

  return integral;
}