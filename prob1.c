#include <stdio.h>
#include <math.h>

int main(void){
  char c;
  short s;
  int i;
  long l;
  long long ll;

  // 最上位bitが0,それ以外のbitが1となる値を代入
  c = 0x7f;
  s = 0x7fff;
  i = 0x7fffffff;
  l = 0x7fffffffffffffff;
  ll = 0x7fffffffffffffff;

  printf("charの最大値:%d\n",c);
  printf("charの最小値:%d\n",++c);
  printf("shortの最大値:%d\n",s);
  printf("shortの最小値:%d\n",++s);
  printf("intの最大値:%d\n",i);
  printf("intの最小値:%d\n",++i);
  printf("longの最大値:%ld\n",l);
  printf("longの最小値:%ld\n",++l);
  printf("long longの最大値:%ld\n",ll);
  printf("long longの最小値:%ld\n\n",++ll);

  unsigned char uc;
  unsigned short us;
  unsigned int ui;
  unsigned long ul;
  unsigned long long ull;

  // すべてのbitが1となる値を代入
  uc = 0xff;
  us = 0xffff;
  ui = 0xffffffff;
  ul = 0xffffffffffffffff;
  ull = 0xffffffffffffffff;

  printf("unsighed charの最大値:%d\n",uc);
  printf("unsighed charの最小値:%d\n",++uc);
  printf("unsighed shortの最大値:%d\n",us);
  printf("unsighed shortの最小値:%d\n",++us);
  printf("unsighed intの最大値:%ld\n",ui);
  printf("unsighed intの最小値:%ld\n",++ui);
  printf("unsighed longの最大値:%lu\n",ul);
  printf("unsighed longの最小値:%lu\n",++ul);
  printf("unsighed long longの最大値:%lu\n",ull);
  printf("unsighed long longの最小値:%lu\n",++ull);

  return 0;
}