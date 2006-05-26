#include "fmt_spec.h"
#include "uint64.h"

unsigned int fmt_u64(char *s, uint64 ul)
{
  uint64 len; 
  uint64 q;
  len = 1; q = ul;
  
  /* no. digits */
  while (q > 9) { ++len; q /= 10; }
  
  /* digit -> ascii (base10) */
  if (s) {
    s += len;
    do { *--s = '0' + (ul % 10); ul /= 10; } while (ul);
  }
  return len;
}

