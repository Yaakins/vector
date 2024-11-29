#include "vector.h"

vector *v_create(int initial_size, int e_size) {
  if (initial_size < 0 || e_size <= 0) {
    return NULL;
  }
  vector *res = malloc(sizeof(vector));
  if (res == NULL) {
    return NULL;
  }
  res->allocated_length = initial_size;
  res->length = 0;
  res->e_size = e_size;
  res->data = malloc(initial_size * e_size);
  return res;
}

void *v_get(vector *target, int i) {
  if (i < 0 || i >= target->length) {
    return NULL;
  }
  return target->data + (target->e_size * i);
}

unsigned char v_push(vector *target, void *e) {
  if (target == NULL || e == NULL) {
    return 1;
  }
  if (target->length == target->allocated_length) {
    void *new_data = malloc(2 * target->allocated_length * target->e_size);
    if (new_data == NULL) {
      return 1;
    }
    memcpy(new_data, target->data, target->length * target->e_size);
    free(target->data);
    target->data = new_data;
    target->allocated_length <<= 1;
  }
  memcpy(target->data + target->length * target->e_size, e, target->e_size);
  target->length++;

  return 0;
}

void *v_pop(vector *target) {  // potential security problem, as the value is still in vector memory area
  if (target == NULL) {        // when doing wrapping, user should copy&cast the value as soon as possible after popping
    return NULL;
  }
  void *res = target->data + target->length * target->e_size;
  target->length--;
  return res;
}

unsigned char v_set(vector *target, int i, void *e) {
  if (target == NULL || i < 0 || i >= target->length || e == NULL) {
    return 1;
  }
  memcpy(target->data + i * target->e_size, e, target->e_size);
  return 0;
}

unsigned char v_free(vector **target) {
  if (target == NULL || *target == NULL) {
    return 1;
  }
  free((*target)->data);
  free(*target);
  *target = NULL;
  return 0;
}
