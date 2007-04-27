#include "scan.h"
#include "sd_longlong.h"

#if defined(HAVE_LONGLONG)
unsigned int scan_ulonglongx(const char *s, unsigned long long *ull)
{
  register unsigned long long res;
  register unsigned int pos;
  register char ch;

  pos = 0;
  res = 0;

  for (;;) {
    ch = s[pos];
    switch (ch) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        ch -= '0';
        break;
      case 'a':
      case 'b':
      case 'c':
      case 'd':
      case 'e':
      case 'f':
        ch = ch - 'a' + 10;
        break;
      case 'A':
      case 'B':
      case 'C':
      case 'D':
      case 'E':
      case 'F':
        ch = ch - 'A' + 10;
        break;
      default:
        goto END; 
    }
    res = (res << 4) + (unsigned char) ch;
    ++pos;
  }

  END:
  if (ull) *ull = res;
  return pos;
}
#endif
