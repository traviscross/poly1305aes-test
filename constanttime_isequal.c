/*
D. J. Bernstein, 20050113.
Public domain.

On the Pentium, Athlon, UltraSPARC, PowerPC, etc.,
the time for this function is independent of the values
of buf[0],...,buf[len-1],buf2[0],...,buf2[len-1].
*/

#include "constanttime.h"

int constanttime_isequal(const unsigned char *buf,unsigned int len,
  const unsigned char *buf2)
{
  unsigned int differentbits = 0;
  while (len > 0) {
    differentbits |= (buf[0] ^ buf2[0]);
    ++buf; --len; ++buf2;
  }
  return (differentbits - 1) >> 8;
}
