/*
aes_openssl.h version 20050201
D. J. Bernstein
Public domain.
*/

#ifndef AES_OPENSSL_H
#define AES_OPENSSL_H

extern void aes_openssl(unsigned char out[16],
  const unsigned char k[16],
  const unsigned char n[16]);

#ifndef aes_implementation
#define aes_implementation "aes_openssl"
#define aes aes_openssl
#endif

#endif
