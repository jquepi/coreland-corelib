#include "bin.h"
#include "buffer.h"
#include "error.h"
#include "str.h"

static int write_all(int (*op)(int, char *, unsigned int),
                     int fd, const char *s, unsigned int len)
{
  int w;
  int (*cop)(int, const char *, unsigned int);

  cop = (int (*)(int, const char *, unsigned int)) op;

  while (len) {
    w = cop(fd, s, len);
    if (w == -1) {
      if (errno == error_intr) continue;
      return w;
    }
    s += w;
    len -= w;
  }
  return 0;
}

int buffer_flush(buffer *b)
{
  int pos;

  pos = b->pos;
  if (!pos) return 0;
  b->pos = 0;
  return write_all(b->op, b->fd, b->buf, pos);
}

int buffer_put(buffer *b, const char *s, unsigned int len)
{
  unsigned int n;

  n = b->size;
  if (len > n - b->pos) {
    if (buffer_flush(b) == -1) return -1;
    if (n < BUFFER_OUTSIZE) n = BUFFER_OUTSIZE;
    while (len > b->size) {
      if (n > len) n = len;
      if (write_all(b->op, b->fd, s, n) == -1) return -1;
      s += n;
      len -= n;
    }
  }
  bin_copy(s, b->buf + b->pos, len);
  b->pos += len;
  return 0;
}

int buffer_putalign(buffer *b, const char *s, unsigned int len)
{
  unsigned int n;

  while (len > (n = b->size - b->pos)) {
    bin_copy(s, b->buf + b->pos, n);
    b->pos += n;
    s += n;
    len -= n;
    if (buffer_flush(b) == -1) return -1;
  }
  bin_copy(s, b->buf + b->pos, len);
  b->pos += len;
  return 0;
}

int buffer_puts(buffer *b, const char *s)
{
  return buffer_put(b, s, str_len(s));
}

int buffer_putsalign(buffer *b, const char *s)
{
  return buffer_putalign(b, s, str_len(s));
}

int buffer_putflush(buffer *b, const char *s, unsigned int len)
{
  if (buffer_flush(b) == -1) return -1;
  return write_all(b->op, b->fd, s, len);
}

int buffer_putsflush(buffer *b, const char *s)
{
  return buffer_putflush(b, s, str_len(s));
}
