#include <stdio.h>
#include "../fmt.h"
#include "../str.h"

struct fmt_test {
  unsigned int sig;
  unsigned int len;
  float num;
  char *str;
};

#include <limits.h>
#include <float.h>

static const struct fmt_test tests[] = {
  /* zero tests */
  { 0, 0, 0.0, "" },
  { 1, 3, 0.0, "0.0" },
  { 2, 3, 0.0, "0.0" },
  { 3, 3, 0.0, "0.0" },
  { 4, 3, 0.0, "0.0" },
  { 5, 3, 0.0, "0.0" },
  { 6, 3, 0.0, "0.0" },
  { 7, 3, 0.0, "0.0" },
  { 8, 3, 0.0, "0.0" },
  { 9, 3, 0.0, "0.0" },
  { 10, 3, 0.0, "0.0" },
  { 11, 3, 0.0, "0.0" },
  { 12, 3, 0.0, "0.0" },
  { 13, 3, 0.0, "0.0" },
  { 14, 3, 0.0, "0.0" },
  { 15, 3, 0.0, "0.0" },

  /* negative zero tests */
  { 0, 0, -0.0, "" },
  { 1, 4, -0.0, "-0.0" },
  { 2, 4, -0.0, "-0.0" },
  { 3, 4, -0.0, "-0.0" },
  { 4, 4, -0.0, "-0.0" },
  { 5, 4, -0.0, "-0.0" },
  { 6, 4, -0.0, "-0.0" },
  { 7, 4, -0.0, "-0.0" },
  { 8, 4, -0.0, "-0.0" },
  { 9, 4, -0.0, "-0.0" },
  { 10, 4, -0.0, "-0.0" },
  { 11, 4, -0.0, "-0.0" },
  { 12, 4, -0.0, "-0.0" },
  { 13, 4, -0.0, "-0.0" },
  { 14, 4, -0.0, "-0.0" },
  { 15, 4, -0.0, "-0.0" },

  /* integral */
  { 0, 0, 123456789.0, "" },
  { 1, 11, 123456789.0, "123456792.0" },
  { 2, 11, 123456789.0, "123456792.0" },
  { 3, 11, 123456789.0, "123456792.0" },
  { 4, 11, 123456789.0, "123456792.0" },
  { 5, 11, 123456789.0, "123456792.0" },
  { 6, 11, 123456789.0, "123456792.0" },
  { 7, 11, 123456789.0, "123456792.0" },
  { 8, 11, 123456789.0, "123456792.0" },
  { 9, 11, 123456789.0, "123456792.0" },
  { 10, 11, 123456789.0, "123456792.0" },
  { 11, 11, 123456789.0, "123456792.0" },
  { 12, 11, 123456789.0, "123456792.0" },
  { 13, 11, 123456789.0, "123456792.0" },
  { 14, 11, 123456789.0, "123456792.0" },
  { 15, 11, 123456789.0, "123456792.0" },

  /* fractional */
  { 0, 0, 0.123456, "" },
  { 1, 3, 0.123456, "0.1" },
  { 2, 4, 0.123456, "0.12" },
  { 3, 5, 0.123456, "0.123" },
  { 4, 6, 0.123456, "0.1235" },
  { 5, 7, 0.123456, "0.12346" },
  { 6, 8, 0.123456, "0.123456" },
  { 7, 9, 0.123456, "0.1234560" },
  { 8, 10, 0.123456, "0.12345600" },
  { 9, 11, 0.123456, "0.123456000" },
  { 10, 12, 0.123456, "0.1234560000" },

  /* negative integral */
  { 0, 0, -123456789.0, "" },
  { 1, 12, -123456789.0, "-123456792.0" },
  { 2, 12, -123456789.0, "-123456792.0" },
  { 3, 12, -123456789.0, "-123456792.0" },
  { 4, 12, -123456789.0, "-123456792.0" },
  { 5, 12, -123456789.0, "-123456792.0" },
  { 6, 12, -123456789.0, "-123456792.0" },
  { 7, 12, -123456789.0, "-123456792.0" },
  { 8, 12, -123456789.0, "-123456792.0" },
  { 9, 12, -123456789.0, "-123456792.0" },
  { 10, 12, -123456789.0, "-123456792.0" },
  { 11, 12, -123456789.0, "-123456792.0" },
  { 12, 12, -123456789.0, "-123456792.0" },
  { 13, 12, -123456789.0, "-123456792.0" },
  { 14, 12, -123456789.0, "-123456792.0" },
  { 15, 12, -123456789.0, "-123456792.0" },

  /* negative fractional */
  { 0, 0, -0.123456, "" },
  { 1, 4, -0.123456, "-0.1" },
  { 2, 5, -0.123456, "-0.12" },
  { 3, 6, -0.123456, "-0.123" },
  { 4, 7, -0.123456, "-0.1235" },
  { 5, 8, -0.123456, "-0.12346" },
  { 6, 9, -0.123456, "-0.123456" },
  { 7, 10, -0.123456, "-0.1234560" },
  { 8, 11, -0.123456, "-0.12345600" },
  { 9, 12, -0.123456, "-0.123456000" },
  { 10, 13, -0.123456, "-0.1234560000" },

  /* large */
  { 0, 0, 123456.987654, "" },
  { 1, 9, 123456.987654, "123456.10" },
  { 2, 9, 123456.987654, "123456.98" },
  { 3, 10, 123456.987654, "123456.984" },
  { 4, 11, 123456.987654, "123456.9844" },
  { 5, 12, 123456.987654, "123456.98438" },
  { 6, 13, 123456.987654, "123456.984375" },
  { 7, 14, 123456.987654, "123456.9843750" },
  { 8, 15, 123456.987654, "123456.98437504" },
  { 9, 16, 123456.987654, "123456.984374976" },

  /* negative large */
  { 0, 0, -123456.987654, "" },
  { 1, 10, -123456.987654, "-123456.10" },
  { 2, 10, -123456.987654, "-123456.98" },
  { 3, 11, -123456.987654, "-123456.984" },
  { 4, 12, -123456.987654, "-123456.9844" },
  { 5, 13, -123456.987654, "-123456.98438" },
  { 6, 14, -123456.987654, "-123456.984375" },
  { 7, 15, -123456.987654, "-123456.9843750" },
  { 8, 16, -123456.987654, "-123456.98437504" },
  { 9, 17, -123456.987654, "-123456.984374976" },
};

int main(void)
{
  char cnum[FMT_FLOAT];
  unsigned int ind;
  unsigned int len;

  for (ind = 0; ind < sizeof(tests) / sizeof(struct fmt_test); ++ind) {
    len = fmt_float(cnum, tests[ind].num, tests[ind].sig);
    if (len != tests[ind].len) {
      printf("fail: [%u] len %u != %u %s\n", ind, len, tests[ind].len, tests[ind].str);
      return 1;
    }
    len = fmt_float(FMT_LEN, tests[ind].num, tests[ind].sig);
    if (len != tests[ind].len) {
      printf("fail: [%u] FMT_LEN len %u != %u\n", ind, len, tests[ind].len);
      return 1;
    }
    cnum[len] = 0;
    if (!str_same(cnum, tests[ind].str)) {
      printf("fail: [%u] %s != %s\n", ind, cnum, tests[ind].str);
      return 1;
    }
    printf("[%u] %s == %s\n", ind, tests[ind].str, cnum);
  }

  return 0;
}
