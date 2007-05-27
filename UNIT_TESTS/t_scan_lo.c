#include <stdio.h>
#include "../scan.h"

static const struct {
  unsigned long len;
  long num;
  const char *str;
} tests[] = {
  { 1, 0, "0" },

  { 1, 1, "1" },
  { 3, 0255, "255" },
  { 5, 032767, "32767" },
  { 5, 065536, "65536" },
  { 7, 01234567, "1234567" },
  { 11, 037777777777, "37777777777" },
  { 3, 0123, "123 456" },

  { 2, -1, "-1" },
  { 4, -0255, "-255" },
  { 6, -032767, "-32767" },
  { 6, -065536, "-65536" },
  { 8, -01234567, "-1234567" },
  { 12, -037777777777, "-37777777777" },
  { 4, -0123, "-123 456" },

  { 0, 0, "8" },
  { 0, 0, "9" },
  { 1, 0, "-" },
};

int main(void)
{
  unsigned int ind;
  long num;
  unsigned long len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    num = 0;
    len = scan_longo(tests[ind].str, &num);
    if (len != tests[ind].len) {
      printf("[%u] fail: len %lu != %lu\n", ind, len, tests[ind].len);
      return 1;
    }
    if (num != tests[ind].num) {
      printf("[%u] fail: num %ld != %ld\n", ind, num, tests[ind].num);
      return 1;
    }
    printf("[%u] %s %ld\n", ind, tests[ind].str, num);
  }
  return 0;
}
