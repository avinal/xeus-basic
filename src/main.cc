#include <memory>

#include "xbasic/xbasic_interpreter.hpp"
#include "xeus/xkernel.hpp"
#include "xeus/xkernel_configuration.hpp"
int main(int argc, char const *argv[]) {
  // Load configuration file
  std::string file_name = (argc == 1) ? "connection.json" : argv[2];
  xeus::xconfiguration config = xeus::load_configuration(file_name);

  // Create interpreter instance
  using interpreter_ptr = std::unique_ptr<xbasic::xbasic_interpreter>;
  interpreter_ptr interpreter = std::make_unique<xbasic::xbasic_interpreter>();

  // Create kernel instance and start it
  xeus::xkernel kernel(config, xeus::get_user_name(), std::move(interpreter));
  kernel.start();
  return 0;
}
