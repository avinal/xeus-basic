/**
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2015-2016 Johan Van den Brande
 *
 * @file	io.h
 */

#ifndef BASIC_IO_H_
#define BASIC_IO_H_

#include <stdlib.h>

typedef int (*basic_putchar)(int ch);
typedef int (*basic_getchar)(void);
void basic_io_print(char* buffer);
char* basic_io_readline(char* prompt, char* buffer, size_t buffer_size);

#endif  // BASIC_IO_H_
