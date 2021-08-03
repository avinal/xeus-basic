/**
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2015-2016 Johan Van den Brande
 *
 * @file	lines.h
 */

#ifndef BASIC_LINES_H_
#define BASIC_LINES_H_
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct line line;

struct line {
  uint16_t number;
  uint8_t length;
  char contents;
};

void lines_init(char* memory, size_t memory_size);

size_t lines_memory_used(void);
size_t lines_memory_available(void);

bool lines_delete(uint16_t number);

bool lines_store(uint16_t number, char* contents);

typedef void (*lines_list_cb)(uint16_t number, char* contents);

void lines_list(uint16_t start, uint16_t end, lines_list_cb out);

void lines_clear(void);

char* lines_get_contents(uint16_t number);

uint16_t lines_first(void);
uint16_t lines_next(uint16_t number);

#endif  // BASIC_LINES_H_
