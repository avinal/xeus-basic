/**
 * SPDX-License-Identifier: Apache-2.0
 * SPDX-FileCopyrightText: 2021 Avinal Kumar <avinal.xlvii@gmail.com>
 *
 * @file	main.cc
 * @brief	Driver Code
 */

#include <fstream>
#include <iostream>
#include <sstream>

#include "basic/basic.hpp"

std::string outputs;

void replcc() {
  std::cout << " _               _      \n"
            << "| |__   __ _ ___(_) ___ \n"
            << "| '_ \\ / _` / __| |/ __|\n"
            << "| |_) | (_| \\__ \\ | (__ \n"
            << "|_.__/ \\__,_|___/_|\\___|\n"
            << "(c) 2015-2016 Johan Van den Brande\n";
  std::string input;
  basic check;
  while (getline(std::cin, input)) {
    if (!input.compare("QUIT")) {
      break;
    }
    if (!check.evaluate_line(input)) {
      std::cerr << check.get_error() << "\n";
    }
    if (input == "RUN") {
      std::cout << check.run();
    }
  }
}

int main(int argc, char *argv[]) {
  replcc();
  return EXIT_SUCCESS;
}
