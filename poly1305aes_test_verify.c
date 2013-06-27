/*
poly1305aes_test_verify.c version 20050201
D. J. Bernstein
Public domain.
*/

#include "constanttime.h"
#include "poly1305aes_test.h"

int poly1305aes_test_verify(const unsigned char a[16],
  const unsigned char kr[32],
  const unsigned char n[16],
  const unsigned char m[],unsigned int l)
{
  unsigned char valid[16];
  poly1305aes_test_authenticate(valid,kr,n,m,l);
  return constanttime_isequal(a,16,valid);
}
