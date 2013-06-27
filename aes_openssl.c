/*
D. J. Bernstein, 20050113.
Public domain.
*/

#include <openssl/aes.h>
#include "aes_openssl.h"

void aes_openssl(unsigned char out[16],
  const unsigned char k[16],
  const unsigned char n[16])
{
  AES_KEY expanded;
  AES_set_encrypt_key(k,128,&expanded);
  AES_encrypt(n,out,&expanded);
}
