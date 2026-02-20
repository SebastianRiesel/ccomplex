#ifndef _CCOMPLEX_H__
#define _CCOMPLEX_H__

typedef struct s_ccomplex {
  float r;
  float i;
} ccomplex_t;

ccomplex_t ccomplex_add(ccomplex_t c1, ccomplex_t c2);
ccomplex_t ccomplex_sub(ccomplex_t c1, ccomplex_t c2);
ccomplex_t ccomplex_mul(ccomplex_t c1, ccomplex_t c2);
ccomplex_t ccomplex_div(ccomplex_t c1, ccomplex_t c2);

ccomplex_t ccomplex_exp(ccomplex_t c1);

ccomplex_t ccomplex_abs(ccomplex_t c1);
ccomplex_t ccomplex_angle(ccomplex_t c1);
ccomplex_t ccomplex_conj(ccomplex_t c1);
ccomplex_t ccomplex_flip(ccomplex_t c1);

char *ccomplex_str(ccomplex_t c1);

#ifdef CCOMPLEX_IMPLEMENTATION

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

ccomplex_t ccomplex_add(ccomplex_t c1, ccomplex_t c2) {
  return (ccomplex_t){c1.r + c2.r, c1.i + c2.i};
}
ccomplex_t ccomplex_sub(ccomplex_t c1, ccomplex_t c2) {
  return (ccomplex_t){c1.r - c2.r, c1.i - c2.i};
}
ccomplex_t ccomplex_mul(ccomplex_t c1, ccomplex_t c2) {
  return (ccomplex_t){c1.r * c2.r - c1.i * c2.i, c1.r * c2.i + c1.i * c2.r};
}
ccomplex_t ccomplex_div(ccomplex_t c1, ccomplex_t c2) {
  float denominator = (c2.r * c2.r + c2.i * c2.i);
  float r = (c1.r * c2.r + c1.i * c2.i) / denominator;
  float i = (c1.i * c2.r - c1.r * c2.i) / denominator;
  return (ccomplex_t){r, i};
}
ccomplex_t ccomplex_exp(ccomplex_t c1) {
  float abs = exp(c1.r);
  return (ccomplex_t){abs * cos(c1.i), abs * sin(c1.i)};
}

ccomplex_t ccomplex_abs(ccomplex_t c1) {
  return (ccomplex_t){sqrtf(c1.r * c1.r + c1.i * c1.i), 0.0f};
}
ccomplex_t ccomplex_angle(ccomplex_t c1) {
  return (ccomplex_t){atan2pif(c1.i, c1.r), 0.0f};
}
ccomplex_t ccomplex_conj(ccomplex_t c1) { return (ccomplex_t){c1.r, -c1.i}; }

ccomplex_t ccomplex_flip(ccomplex_t c1) { return (ccomplex_t){c1.i, c1.r}; }

#define COMPLEX_MAX_STR_LENGTH 32
char *ccomplex_str(ccomplex_t c1) {
  char *buf = (char *)malloc(sizeof(char) * COMPLEX_MAX_STR_LENGTH);

  if (c1.i >= 0.0f) {
    snprintf(buf, COMPLEX_MAX_STR_LENGTH, "%.6g + i%.6g", c1.r, c1.i);
  } else {
    snprintf(buf, COMPLEX_MAX_STR_LENGTH, "%.6g - i%.6g", c1.r, -c1.i);
  }

  return buf;
}

#endif
#endif
