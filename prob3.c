#include <stdio.h>
#include <math.h>

int main(void){
  float S_k1;
  double S_k2;
  int k,K;

  printf("float型の場合:\n");

  printf("kが小さい方から足したとき\n");
  for(K=100;K<1000001;K*=10){
    S_k1=0;
    for(k=1;k<K+1;k++){
      S_k1 += pow(k,-8);
    }
    printf("K=%7d:%30.30lf\n",K,S_k1);
  }

  printf("\n");

  printf("kが大きい方から足したとき\n");
  for(K=100;K<1000001;K*=10){
    S_k1=0;
    for(k=K;k>0;k--){
      S_k1 += pow(k,-8);
    }
    printf("K=%7d:%30.30lf\n",K,S_k1);
  }

  printf("\n");
  printf("double型の場合:\n");

  printf("kが小さい方から足したとき\n");
  for(K=100;K<1000001;K*=10){
    S_k2=0;
    for(k=1;k<K+1;k++){
      S_k2 += pow(k,-8);
    }
    printf("K=%7d:%30.30lf\n",K,S_k2);
  }

  printf("\n");

  printf("kが大きい方から足したとき\n");
  for(K=100;K<1000001;K*=10){
    S_k2=0;
    for(k=1;k<K+1;k++){
      S_k2 += pow(K+1-k ,-8);
    }
    printf("K=%7d:%30.30lf\n",K,S_k2);
  }

  return 0;
}