#include "scan.h"

unsigned int scan_uchar(const char *s, unsigned char *up)
{
  unsigned long ul;
  unsigned char uc;
  unsigned int len;

  len = scan_ulong(s, &ul);
  if (!len) return 0;

  uc = (unsigned char) ul; *up = uc;
  return len;
}
