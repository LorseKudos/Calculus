#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//1つ目の変数は求めたい時間,2つ目の変数は刻み幅の値,3つ目の変数は初期値
void euler(int ,double ,double);
void runge2(int ,double ,double);
void runge4(int ,double ,double);

//微分方程式の右辺
double function(double,double);

int main(int argc, char *argv[]){
  int i,T=100;
  int method; //1:オイラー法 2:2次ルンゲクッタ法 3:4次ルンゲクッタ法
  double h; //分割幅

  method = atoi(argv[1]);

  for(i=0;i<10;i++){
    if(i%2==0){
      h = 0.5 * pow(0.1,i/2);
    }else{
      h = pow(0.1,i/2 + 1);
    }
    if (method == 1){
      euler(T,h,1.0);
    }else if(method == 2){
      runge2(T,h,1.0);
    }else if(method == 3){
      runge4(T,h,1.0);
    }
  }
  return 0;
}

void euler(int T,double h,double x0){
  int k; //ループ変数
  double t = 0.0,x;

  x = x0;

  for(k=0;k<T/h;k++){
    t =(double) k * h;
    x += h * function(x,t);
  }
  printf("%.10lf %.20lf\n",h,fabs(2*exp(t)/(exp(t)+1) - x));
}

void runge2(int T,double h,double x0){
  int k; //ループ変数
  double t = 0.0,x,x_tilde;

  x = x0;

  for(k=0;k<T/h;k++){
    t =(double) k * h;
    x_tilde = x + h * function(x,t) / 2;
    x += h * function(x_tilde,t + h/2);
  }
  printf("%.10lf %.20lf\n",h,fabs(2*exp(t)/(exp(t)+1) - x));
}

void runge4(int T,double h,double x0){
  int i; //ループ変数
  double t = 0.0,x,x_tilde,k[4];

  x = x0;

  for(i=0;i<T/h;i++){
    t =(double) i * h;

    k[0] = function(x,t);
    k[1] = function(x+h*k[0]/2.0,t+h/2.0);
    k[2] = function(x+h*k[1]/2.0,t+h/2.0);
    k[3] = function(x+h*k[2],t+h);
    x += h*(k[0]+2*k[1]+2*k[2]+k[3])/6.0;
  }
  printf("%.10lf %.20lf\n",h,fabs(2*exp(t)/(exp(t)+1) -x));
}

double function(double x,double t){
  return x/(1+exp(t));
}