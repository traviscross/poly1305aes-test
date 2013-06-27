/*
poly1305aes_test.h version 20050201
D. J. Bernstein
Public domain.
*/

#ifndef POLY1305AES_TEST_H
#define POLY1305AES_TEST_H

extern void poly1305aes_test_clamp(unsigned char kr[32]);

extern void poly1305aes_test_authenticate(unsigned char out[16],
  const unsigned char kr[32],
  const unsigned char n[16],
  const unsigned char m[],unsigned int l);

extern int poly1305aes_test_verify(const unsigned char a[16],
  const unsigned char kr[32],
  const unsigned char n[16],
  const unsigned char m[],unsigned int l);

#ifndef poly1305aes_implementation
#define poly1305aes_implementation "poly1305aes_test"
#define poly1305aes_clamp poly1305aes_test_clamp
#define poly1305aes_authenticate poly1305aes_test_authenticate
#define poly1305aes_verify poly1305aes_test_verify
#endif

#endif
