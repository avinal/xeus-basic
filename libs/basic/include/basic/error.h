/**
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2015-2016 Johan Van den Brande
 *
 * @file	error.h
 */

#ifndef BASIC_ERROR_H_
#define BASIC_ERROR_H_

extern char *last_error;
void error(const char *error_msg);

#endif  // BASIC_ERROR_H_
