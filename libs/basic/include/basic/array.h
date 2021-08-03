/**
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2015-2016 Johan Van den Brande
 *
 * @file	array.h
 */

#ifndef BASIC_ARRAY_H_
#define BASIC_ARRAY_H_

#include <stddef.h>
typedef struct array array;

array* array_new(size_t element_size);

array* array_alloc(array* array, size_t size);

void array_destroy(array* array);

void* array_push(array* array, void* value);

void* array_get(array* array, size_t index);

void* array_set(array* array, size_t index, void* value);

size_t array_size(array* array);

#endif  // BASIC_ARRAY_H_