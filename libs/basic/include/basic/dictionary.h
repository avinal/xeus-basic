/**
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2015-2016 Johan Van den Brande
 *
 * @file	dictionary.h
 */

#ifndef BASIC_DICTIONARY_H_
#define BASIC_DICTIONARY_H_

#include <stdbool.h>

typedef struct dictionary dictionary;

typedef void (*dictionary_each_cb)(char* name, void* value, void* context);

dictionary* dictionary_new(void);
void dictionary_destroy(dictionary* d, dictionary_each_cb cb);
void dictionary_put(dictionary* d, char* name, void* value);
bool dictionary_has(dictionary* d, char* name);
void* dictionary_get(dictionary* d, char* name);
void dictionary_each(dictionary* d, dictionary_each_cb cb, void* context);
void* dictionary_del(dictionary* d, char* name);

#endif  // BASIC_DICTIONARY_H_
