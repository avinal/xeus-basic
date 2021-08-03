/**
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2015-2016 Johan Van den Brande
 *
 * @file	error.c
 */

#include <execinfo.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern uint16_t __line;

const char *last_error = NULL;

void error(const char *error_msg) {
  void *array[10];
  size_t size;
  char **strings;
  size_t i;

  last_error = error_msg;

  printf("--- ERROR: %d %s\n", __line, error_msg);

  size = backtrace(array, 10);
  strings = backtrace_symbols(array, size);

  printf("SHOW %zd STACK FRAMES:\n", size);

  for (i = 0; i < size; i++) {
    printf("  %s\n", strings[i]);
  }

  free(strings);
}
