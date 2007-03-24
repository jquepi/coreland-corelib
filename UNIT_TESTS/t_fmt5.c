#include <stdio.h>
#include "../fmt.h"
#include "../str.h"

struct fmt_test {
  unsigned int sig;
  unsigned int len;
  double num;
  char *str;
};

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
  { 1, 11, 123456789.0, "123456789.0" },
  { 2, 11, 123456789.0, "123456789.0" },
  { 3, 11, 123456789.0, "123456789.0" },
  { 4, 11, 123456789.0, "123456789.0" },
  { 5, 11, 123456789.0, "123456789.0" },
  { 6, 11, 123456789.0, "123456789.0" },
  { 7, 11, 123456789.0, "123456789.0" },
  { 8, 11, 123456789.0, "123456789.0" },
  { 9, 11, 123456789.0, "123456789.0" },
  { 10, 11, 123456789.0, "123456789.0" },
  { 11, 11, 123456789.0, "123456789.0" },
  { 12, 11, 123456789.0, "123456789.0" },
  { 13, 11, 123456789.0, "123456789.0" },
  { 14, 11, 123456789.0, "123456789.0" },
  { 15, 11, 123456789.0, "123456789.0" },

  /* fractional */
  { 0, 0, 0.123456789, "" },
  { 1, 3, 0.123456789, "0.1" },
  { 2, 4, 0.123456789, "0.12" },
  { 3, 5, 0.123456789, "0.123" },
  { 4, 6, 0.123456789, "0.1235" },
  { 5, 7, 0.123456789, "0.12346" },
  { 6, 8, 0.123456789, "0.123457" },
  { 7, 9, 0.123456789, "0.1234568" },
  { 8, 10, 0.123456789, "0.12345679" },
  { 9, 11, 0.123456789, "0.123456789" },
  { 10, 12, 0.123456789, "0.1234567890" },
  { 11, 13, 0.123456789, "0.12345678900" },
  { 12, 14, 0.123456789, "0.123456789000" },
  { 13, 15, 0.123456789, "0.1234567890000" },
  { 14, 16, 0.123456789, "0.12345678900000" },
  { 15, 17, 0.123456789, "0.123456789000000" },

  /* negative integral */
  { 0, 0, -123456789.0, "" },
  { 1, 12, -123456789.0, "-123456789.0" },
  { 2, 12, -123456789.0, "-123456789.0" },
  { 3, 12, -123456789.0, "-123456789.0" },
  { 4, 12, -123456789.0, "-123456789.0" },
  { 5, 12, -123456789.0, "-123456789.0" },
  { 6, 12, -123456789.0, "-123456789.0" },
  { 7, 12, -123456789.0, "-123456789.0" },
  { 8, 12, -123456789.0, "-123456789.0" },
  { 9, 12, -123456789.0, "-123456789.0" },
  { 10, 12, -123456789.0, "-123456789.0" },
  { 11, 12, -123456789.0, "-123456789.0" },
  { 12, 12, -123456789.0, "-123456789.0" },
  { 13, 12, -123456789.0, "-123456789.0" },
  { 14, 12, -123456789.0, "-123456789.0" },
  { 15, 12, -123456789.0, "-123456789.0" },

  /* negative fractional */
  { 0, 0, -0.123456789, "" },
  { 1, 4, -0.123456789, "-0.1" },
  { 2, 5, -0.123456789, "-0.12" },
  { 3, 6, -0.123456789, "-0.123" },
  { 4, 7, -0.123456789, "-0.1235" },
  { 5, 8, -0.123456789, "-0.12346" },
  { 6, 9, -0.123456789, "-0.123457" },
  { 7, 10, -0.123456789, "-0.1234568" },
  { 8, 11, -0.123456789, "-0.12345679" },
  { 9, 12, -0.123456789, "-0.123456789" },
  { 10, 13, -0.123456789, "-0.1234567890" },
  { 11, 14, -0.123456789, "-0.12345678900" },
  { 12, 15, -0.123456789, "-0.123456789000" },
  { 13, 16, -0.123456789, "-0.1234567890000" },
  { 14, 17, -0.123456789, "-0.12345678900000" },
  { 15, 18, -0.123456789, "-0.123456789000000" },

  /* large */
  { 0, 0, 123456789.987654321, "" },
  { 1, 12, 123456789.987654321, "123456789.10" },
  { 2, 12, 123456789.987654321, "123456789.99" },
  { 3, 13, 123456789.987654321, "123456789.988" },
  { 4, 14, 123456789.987654321, "123456789.9877" },
  { 5, 15, 123456789.987654321, "123456789.98765" },
  { 6, 16, 123456789.987654321, "123456789.987654" },
  { 7, 17, 123456789.987654321, "123456789.9876543" },
  { 8, 18, 123456789.987654321, "123456789.98765433" },
  { 9, 19, 123456789.987654321, "123456789.987654328" },
  { 10, 20, 123456789.987654321, "123456789.9876543283" },
  { 11, 21, 123456789.987654321, "123456789.98765432835" },
  { 12, 22, 123456789.987654321, "123456789.987654328346" },
  { 13, 23, 123456789.987654321, "123456789.9876543283463" },
  { 14, 24, 123456789.987654321, "123456789.98765432834625" },
  { 15, 25, 123456789.987654321, "123456789.987654328346253" },

  /* negative large */
  { 0, 0, -123456789.987654321, "" },
  { 1, 13, -123456789.987654321, "-123456789.10" },
  { 2, 13, -123456789.987654321, "-123456789.99" },
  { 3, 14, -123456789.987654321, "-123456789.988" },
  { 4, 15, -123456789.987654321, "-123456789.9877" },
  { 5, 16, -123456789.987654321, "-123456789.98765" },
  { 6, 17, -123456789.987654321, "-123456789.987654" },
  { 7, 18, -123456789.987654321, "-123456789.9876543" },
  { 8, 19, -123456789.987654321, "-123456789.98765433" },
  { 9, 20, -123456789.987654321, "-123456789.987654328" },
  { 10, 21, -123456789.987654321, "-123456789.9876543283" },
  { 11, 22, -123456789.987654321, "-123456789.98765432835" },
  { 12, 23, -123456789.987654321, "-123456789.987654328346" },
  { 13, 24, -123456789.987654321, "-123456789.9876543283463" },
  { 14, 25, -123456789.987654321, "-123456789.98765432834625" },
  { 15, 26, -123456789.987654321, "-123456789.987654328346253" },
};

int main(void)
{
  char cnum[FMT_DOUBLE];
  unsigned int ind;
  unsigned int len;

  for (ind = 0; ind < sizeof(tests) / sizeof(struct fmt_test); ++ind) {
    len = fmt_double(cnum, tests[ind].num, tests[ind].sig);
    if (len != tests[ind].len) {
      printf("fail: [%u] len %u != %u %s\n", ind, len, tests[ind].len, tests[ind].str);
      return 1;
    }
    len = fmt_double(FMT_LEN, tests[ind].num, tests[ind].sig);
    if (len != tests[ind].len) {
      printf("fail: [%u] FMT_LEN len %u != %u\n", ind, len, tests[ind].len);
      return 1;
    }
    cnum[len] = 0;
    if (!str_same(cnum, tests[ind].str)) {
      printf("fail: [%u] %s != %s\n", ind, cnum, tests[ind].str);
      return 1;
    }
    printf("[%lu] %s == %s\n", ind, tests[ind].str, cnum);
  }

  return 0;
}