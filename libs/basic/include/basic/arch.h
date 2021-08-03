/**
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2015-2016 Johan Van den Brande
 *
 * @file	arch.h
 */

#ifndef BASIC_ARCH_H_
#define BASIC_ARCH_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

int arch_init(void);

typedef void (*arch_load_out_cb)(char* line, void* context);
int arch_load(char* filename, arch_load_out_cb cb, void* context);

typedef uint16_t (*arch_save_cb)(char** line, void* context);
int arch_save(char* filename, arch_save_cb cb, void* context);

typedef void (*arch_dir_out_cb)(char* name, size_t size, bool label, void* context);
int arch_dir(arch_dir_out_cb cb, void* context);

int arch_delete(char* filename);

#endif  // BASIC_ARCH_H_