/**
 * SPDX-License-Identifier: Apache-2.0
 * SPDX-FileCopyrightText: 2021 Avinal Kumar <avinal.xlvii@gmail.com>
 *
 * @file	basic.hpp
 * @brief	Wrapper around basic
 */

#ifndef BASIC_BASIC_HPP_
#define BASIC_BASIC_HPP_

#include <string>
extern "C" {
#include "parser.h"
}

class basic {
private:
  std::string last_error = "";
  static std::string output;
  static int out(int ch) {
    output.push_back(ch);
    return 1;
  }

  static int in() { return getchar(); }

public:
  basic() {
    basic_init(1024 * 8, 2048);
    basic_register_io(out, in);
  }

  ~basic() { basic_destroy(); }

  bool evaluate_line(const std::string& line) {
    char* input = const_cast<char*>(line.c_str());
    basic_eval(input);
    if (evaluate_last_error()) {
      last_error.append(evaluate_last_error());
      clear_last_error();
      return false;
    }
    return true;
  }

  std::string get_error() { return last_error; }

  std::string run() {
    evaluate_line("RUN");
    return output;
  }

  void clear_output() { output = ""; }
};

#endif  // BASIC_BASIC_HPP_