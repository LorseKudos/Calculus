#include <stdio.h>
#include <math.h>

int main(void){
  // 1 + 1e-16 * 1e8 = 1.00000001を計算する

  double x = 1;
  int i; //ループ変数

  printf("1 + 1e-16 * 1e8\n");

  for(i=0;i<1e8;i++){
    x += 1e-16;
  }

  printf("大きい数から足した場合:%.20lf\n",x);

  x = 0;

  for(i=0;i<1e8;i++){
    x += 1e-16;
  }
  x++;
  printf("小さい数から足した場合:%.20lf\n",x);

  return 0;
}