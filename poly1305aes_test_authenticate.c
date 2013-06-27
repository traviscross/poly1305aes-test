/*
poly1305aes_test_authenticate.c version 20050201
D. J. Bernstein
Public domain.
*/

#include "poly1305aes_test.h"
#include "aes_openssl.h"
#include "poly1305_gmp.h"

void poly1305aes_test_authenticate(unsigned char out[16],
  const unsigned char kr[32],
#define k (kr + 0)
#define r (kr + 16)
  const unsigned char n[16],
  const unsigned char m[],unsigned int l)
{
  unsigned char aeskn[16];
  aes_openssl(aeskn,k,n);
  poly1305_gmp(out,r,aeskn,m,l);
}
