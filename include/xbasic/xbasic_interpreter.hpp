#ifndef XBASIC_INTERPRETER_HPP_
#define XBASIC_INTERPRETER_HPP_

#include <iostream>

#include "basic/basic.hpp"
#include "nlohmann/json.hpp"
#include "xeus/xinterpreter.hpp"

using xeus::xinterpreter;
namespace nl = nlohmann;

namespace xbasic {

  class xbasic_interpreter : public xinterpreter {
  private:
    basic* code_runner = nullptr;

  public:
    xbasic_interpreter() = default;

    virtual ~xbasic_interpreter() = default;

    void configure_impl() override;

    nl::json execute_request_impl(int execution_counter, const std::string& code, bool silent,
                                  bool store_history, nl::json user_expressions,
                                  bool allow_stdin) override;

    nl::json complete_request_impl(const std::string& code, int cursor_pos) override;

    nl::json inspect_request_impl(const std::string& code, int cursor_pos,
                                  int detail_level) override;

    nl::json is_complete_request_impl(const std::string& code) override;
    nl::json kernel_info_request_impl() override;

    void shutdown_request_impl() override;
  };
}  // namespace xbasic

#endif  // XBASIC_INTERPRETER_HPP_