/**
 * SPDX-License-Identifier: Apache-2.0
 * SPDX-FileCopyrightText: 2021 Avinal Kumar <avinal.xlvii@gmail.com>
 *
 * @file	main.cc
 * @brief	Driver Code
 */

// #include <math.h>
// #include <readline/history.h>
// #include <readline/readline.h>
// #include <signal.h>
// #include <stdbool.h>
// #include <stdio.h>
// #include <string.h>

#include <fstream>
#include <iostream>
#include <sstream>

#include "basic.hpp"

// extern bool __RUNNING;
// extern bool __STOPPED;

// static void sigint_handler(int signum) {
//   signal(SIGINT, sigint_handler);
//   if (__RUNNING) {
//     __RUNNING = false;
//     __STOPPED = true;
//     printf("STOP\n");
//     fflush(stdout);
//   }
// }

// static char *readline_gets() {
//   char *line_read = readline("");

//   if (line_read && *line_read) {
//     add_history(line_read);
//   }

//   return line_read;
// }
std::string outputs;
// int out(int ch) {
//   outputs += char(ch);
//   return 1;
// }

// int in(void) { return getchar(); }

void replcc() {
  std::cout << " _               _      \n"
            << "| |__   __ _ ___(_) ___ \n"
            << "| '_ \\ / _` / __| |/ __|\n"
            << "| |_) | (_| \\__ \\ | (__ \n"
            << "|_.__/ \\__,_|___/_|\\___|\n"
            << "(c) 2015-2016 Johan Van den Brande\n";
  // using_history();
  std::string input;
  basic check;
  while (getline(std::cin, input)) {
    if (!input.compare("QUIT")) {
      // check.~basic();
      break;
    }
    if (!check.evaluate_line(input)) {
      std::cerr << check.get_error() << "\n";
    }
    // basic_eval((char *)input.c_str());
    if (input == "RUN") {
      std::cout << check.run();
    }
    // if (evaluate_last_error()) {
    //   std::cerr << "ERROR: " << evaluate_last_error() << "\n";
    //   clear_last_error();
    // }
  }
  // clear_history();
}

void runcc(std::string filename) {
  // std::fstream file(filename, std::ios::in);

  // if (!file.is_open()) {
  //   std::cerr << "Can't open " << filename << std::endl;
  //   exit(EXIT_FAILURE);
  // }
  // std::string line;
  // while (getline(file, line)) {
  //   basic_eval((char *)line.c_str());
  // }
  // file.close();
  // basic_run();
}

int main(int argc, char *argv[]) {
  // signal(SIGINT, sigint_handler);
  // basic_init(1024 * 8, 2048);
  // basic_register_io(out, in);

  if (argc > 1) {
    runcc(argv[1]);
  } else {
    replcc();
  }

  // basic_destroy();

  return EXIT_SUCCESS;
}
