#include "vector.h"

int v_get_i(vector *target, int i) {
  return *((int *) v_get(target, i));
}

unsigned char v_push_i(vector *target, int n) {
  return v_push(target, (void *)&n);
}

int v_pop_i(vector *target) {
  return *((int *) v_pop(target));
}

unsigned char v_set_i(vector *target, int i, int n) {
  return v_set(target, i, (void *)&n);
}
