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
  { 2, 4, 0.0, "0.00" },
  { 3, 5, 0.0, "0.000" },
  { 4, 6, 0.0, "0.0000" },
  { 5, 7, 0.0, "0.00000" },
  { 6, 8, 0.0, "0.000000" },
  { 7, 9, 0.0, "0.0000000" },
  { 8, 10, 0.0, "0.00000000" },
  { 9, 11, 0.0, "0.000000000" },
  { 10, 12, 0.0, "0.0000000000" },
  { 11, 13, 0.0, "0.00000000000" },
  { 12, 14, 0.0, "0.000000000000" },
  { 13, 15, 0.0, "0.0000000000000" },
  { 14, 16, 0.0, "0.00000000000000" },
  { 15, 17, 0.0, "0.000000000000000" },

  /* negative zero tests */
  { 0, 0, -0.0, "" },
  { 1, 4, -0.0, "-0.0" },
  { 2, 5, -0.0, "-0.00" },
  { 3, 6, -0.0, "-0.000" },
  { 4, 7, -0.0, "-0.0000" },
  { 5, 8, -0.0, "-0.00000" },
  { 6, 9, -0.0, "-0.000000" },
  { 7, 10, -0.0, "-0.0000000" },
  { 8, 11, -0.0, "-0.00000000" },
  { 9, 12, -0.0, "-0.000000000" },
  { 10, 13, -0.0, "-0.0000000000" },
  { 11, 14, -0.0, "-0.00000000000" },
  { 12, 15, -0.0, "-0.000000000000" },
  { 13, 16, -0.0, "-0.0000000000000" },
  { 14, 17, -0.0, "-0.00000000000000" },
  { 15, 18, -0.0, "-0.000000000000000" },

  /* integral */
  { 0, 0, 123456789.0, "" },
  { 1, 11, 123456789.0, "123456789.0" },
  { 2, 12, 123456789.0, "123456789.00" },
  { 3, 13, 123456789.0, "123456789.000" },
  { 4, 14, 123456789.0, "123456789.0000" },
  { 5, 15, 123456789.0, "123456789.00000" },
  { 6, 16, 123456789.0, "123456789.000000" },
  { 7, 17, 123456789.0, "123456789.0000000" },
  { 8, 18, 123456789.0, "123456789.00000000" },
  { 9, 19, 123456789.0, "123456789.000000000" },
  { 10, 20, 123456789.0, "123456789.0000000000" },
  { 11, 21, 123456789.0, "123456789.00000000000" },
  { 12, 22, 123456789.0, "123456789.000000000000" },
  { 13, 23, 123456789.0, "123456789.0000000000000" },
  { 14, 24, 123456789.0, "123456789.00000000000000" },
  { 15, 25, 123456789.0, "123456789.000000000000000" },

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

  /* DBL_MIN, DBL_MAX */
  { 15, 6, 1e37, "1.1e37" },
  { 15, 7, 1e-37, "1.1e-37" },

  /* t_scan_doub */
  { 15, 4, 1e1, "10.0" },
  { 15, 17, 1e-1, "0.100000000000000" },
  { 15, 13, 1e10, "10000000000.0" },
  { 15, 8, 1e-10, "1e-10" },
  { 15, 5, -1e1, "-10.0" },
  { 15, 5, -1e-1, "-0.1000000000000000" },
  { 15, 14, -1e10, "-10000000000.0" },
  { 15, 6, -1e-10, "-1e-10" },
  { 15, 5, 1.0e1, "10.0" },
  { 15, 6, 1.0e-1, "0.1000000000000000" },
  { 15, 6, 1.0e10, "10000000000.0" },
  { 15, 7, 1.0e-10, "1e-10" },
  { 15, 6, -1.0e1, "-10.0" },
  { 15, 7, -1.0e-1, "-0.1000000000000000" },
  { 15, 7, -1.0e10, "-10000000000.0" },
  { 15, 8, -1.0e-10, "-1e-10" },
  { 15, 3, 0.1, "0.1" },
  { 15, 4, 0.01, "0.01" },
  { 15, 5, 0.001, "0.001" },
  { 15, 6, 0.0001, "0.0001" },
  { 15, 7, 0.00001, "0.00001" },
  { 15, 8, 0.000001, "0.000001" },
  { 15, 9, 0.0000001, "0.0000001" },
  { 15, 10, 0.00000001, "0.00000001" },
  { 15, 11, 0.000000001, "0.000000001" },
  { 15, 12, 0.0000000001, "0.0000000001" },
  { 15, 13, 0.00000000001, "0.00000000001" },
  { 15, 14, 0.000000000001, "0.000000000001" },
  { 15, 15, 0.0000000000001, "0.0000000000001" },
  { 15, 16, 0.00000000000001, "0.00000000000001" },
  { 15, 17, 0.000000000000001, "0.000000000000001" },
  { 15, 4, -0.1, "-0.1" },
  { 15, 5, -0.01, "-0.01" },
  { 15, 6, -0.001, "-0.001" },
  { 15, 7, -0.0001, "-0.0001" },
  { 15, 8, -0.00001, "-0.00001" },
  { 15, 9, -0.000001, "-0.000001" },
  { 15, 10, -0.0000001, "-0.0000001" },
  { 15, 11, -0.00000001, "-0.00000001" },
  { 15, 12, -0.000000001, "-0.000000001" },
  { 15, 13, -0.0000000001, "-0.0000000001" },
  { 15, 14, -0.00000000001, "-0.00000000001" },
  { 15, 15, -0.000000000001, "-0.000000000001" },
  { 15, 16, -0.0000000000001, "-0.0000000000001" },
  { 15, 17, -0.00000000000001, "-0.00000000000001" },
  { 15, 18, -0.000000000000001, "-0.000000000000001" },
  { 15, 11, 1.234567890, "1.234567890" },
  { 15, 11, 12.34567890, "12.34567890" },
  { 15, 11, 123.4567890, "123.4567890" },
  { 15, 11, 1234.567890, "1234.567890" },
  { 15, 11, 12345.67890, "12345.67890" },
  { 15, 11, 123456.7890, "123456.7890" },
  { 15, 11, 1234567.890, "1234567.890" },
  { 15, 11, 12345678.90, "12345678.90" },
  { 15, 11, 123456789.0, "123456789.0" },
  { 15, 12, -1.234567890, "-1.234567890" },
  { 15, 12, -12.34567890, "-12.34567890" },
  { 15, 12, -123.4567890, "-123.4567890" },
  { 15, 12, -1234.567890, "-1234.567890" },
  { 15, 12, -12345.67890, "-12345.67890" },
  { 15, 12, -123456.7890, "-123456.7890" },
  { 15, 12, -1234567.890, "-1234567.890" },
  { 15, 12, -12345678.90, "-12345678.90" },
  { 15, 12, -123456789.0, "-123456789.0" },
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
    printf("[%u] %s == %s\n", ind, tests[ind].str, cnum);
  }

  return 0;
}
