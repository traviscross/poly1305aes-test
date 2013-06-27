/*
D. J. Bernstein, 20050113.
Public domain.

Checks that constanttime_isequal() matches memcmp() for various inputs.
Doesn't try to check the constanttime_isequal() timing.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constanttime.h"

void doit(const unsigned char *buf,const unsigned int len,
  const unsigned char *buf2)
{
  if (constanttime_isequal(buf,len,buf2)) {
    if (memcmp(buf,buf2,len)) {
      printf("alert: constanttime_isequal but memcmp\n");
      exit(1);
    }
  } else {
    if (!memcmp(buf,buf2,len)) {
      printf("alert: !constanttime_isequal but !memcmp\n");
      exit(1);
    }
  }
}

#define MAXLEN 100
unsigned char x[MAXLEN];
unsigned char y[MAXLEN];

main()
{
  int i;
  int j;
  int len;
  int loop;

  doit("",0,"");

  for (i = 0;i < 256;++i)
    for (j = 0;j < 256;++j) {
      x[0] = i;
      y[0] = j;
      doit(x,1,y);
    }

  for (len = 1;len <= MAXLEN;++len) {
    for (loop = 0;loop < 1000;++loop) {
      for (i = 0;i < len;++i) x[i] = random();
      for (i = 0;i < len;++i) y[i] = random();
      doit(x,len,y);
      for (i = 0;i < len;++i) y[i] = x[i];
      doit(x,len,y);
      y[random() % len] = random();
      doit(x,len,y);
    }
  }

  return 0;
}
