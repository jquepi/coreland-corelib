#include <stdio.h>
#include "../fmt.h"
#include "../str.h"

struct fmt_test {
  unsigned long num;
  char *str;
};

static const struct fmt_test tests[] = {
  { 0, "0" },
  { 1, "1" },
  { 2, "10" },
  { 3, "11" },
  { 4, "100" },
  { 5, "101" },
  { 6, "110" },
  { 7, "111" },
  { 8, "1000" },
  { 9, "1001" },
  { 10, "1010" },
  { 11, "1011" },
  { 0xffffffffUL, "11111111111111111111111111111111" }, 
  { 0xfffffff0UL, "11111111111111111111111111110000" },
  { 0xffffff00UL, "11111111111111111111111100000000" },
  { 0xfffff000UL, "11111111111111111111000000000000" },
  { 0xffff0000UL, "11111111111111110000000000000000" },
};

int main(void)
{
  char cnum[FMT_ULONG];
  unsigned int ind;

  for (ind = 0; ind < sizeof(tests) / sizeof(struct fmt_test); ++ind) {
    cnum[fmt_ulongb(cnum, tests[ind].num)] = 0;
    if (!str_same(cnum, tests[ind].str)) {
      printf("fail: [%u] %s != %s\n", ind, cnum, tests[ind].str);
      return 1;
    }
    printf("[%u] %s\n", ind, cnum);
  }

  return 0;
}
