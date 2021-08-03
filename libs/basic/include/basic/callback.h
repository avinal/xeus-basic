/**
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2015-2016 Johan Van den Brande
 *
 * @file	callback.h
 */

#ifndef BASIC_CALLBACK_H_
#define BASIC_CALLBACK_H_

#include <stdbool.h>

typedef struct error {
  int error;
};

typedef bool (*callback)(error err, void* data);

#endif  // BASIC_CALLBACK_H_