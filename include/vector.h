#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int allocated_length;
  int length;
  int e_size;
  void *data;
} vector;

/* allocates a vector struct, with `initial_size` data length,
 * each element `e_size` bytes long
 */
vector *v_create(int initial_size, int e_size);

/* returns a void* to the ith element in vector
 * one should setup wrapping functions to get desired type
 * (see examples/int_wrapping.c)
 */
void *v_get(vector *target, int i);

/* appends a value stored at address `e` at the end of
 * the vector.
 * May lead to slow operations when resizing is needed
 * returns 0 on success
 */
unsigned char v_push(vector *target, void *e);

/* returns the last vector element and shortens it from one
 * /!\ needs to be wrapped carefully, as the returned pointer
 * points to the vector's memory area
 * wrapper should copy the value before doing anything else
 */
void *v_pop(vector *target);

/* sets the ith element in vector, from value stored at `e`address
 * returns 0 on success
 */
unsigned char v_set(vector *target, int i, void *e);

/* frees the target and its data, setting it to NULL
 */
void v_free(vector **target);

#endif
