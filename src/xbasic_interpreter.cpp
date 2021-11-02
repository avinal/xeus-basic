
#include "xbasic/xbasic_interpreter.hpp"

std::string basic::output = "";

namespace xbasic {

  nl::json xbasic_interpreter::execute_request_impl(int execution_counter, const std::string &code,
                                                    bool /*silent*/, bool /*store_history*/,
                                                    nl::json /*user_expressions*/,
                                                    bool /*allow_stdin*/) {
    auto ok = []() {
      nl::json result;
      result["status"] = "ok";
      return result;
    };

    std::vector<std::string> traceback;
    auto handle_exception = [&](std::string what) {
      nl::json result;
      result["status"] = "error";
      result["ename"] = "Error";
      result["evalue"] = what;
      traceback.push_back((std::string)result["ename"] + ": " + what);
      publish_execution_error(result["ename"], result["evalue"], traceback);
      traceback.clear();
      return result;
    };

    auto dispose = [&]() {
      delete code_runner;
      code_runner = nullptr;
    };

    auto init_basic = [&]() { code_runner = new basic(); };

    if (!code_runner) {
      init_basic();
    }

    nl::json pub_data;
    bool is_complete = false;
    try {
      std::string line;
      std::stringstream to_line(code);
      while (std::getline(to_line, line, '\n')) {
        std::cout << line << "\n";
        if (line == "CLEAR" || line == "RUN") {
          is_complete = true;
          std::cout << "Disposing basic...\n";
        } else if (!code_runner->evaluate_line(line)) {
          std::cout << "Throw error\n";
          throw(code_runner->get_error());
        }
      }
      std::string result = code_runner->run();
      code_runner->clear_output();
      if (is_complete) {
        dispose();
        result += "\n\n Clearing Scope\n";
      }
      pub_data["text/plain"] = result;
      publish_execution_result(execution_counter, std::move(pub_data), nl::json::object());
      return ok();
    } catch (const std::exception &err) {
      std::cout << "Check error\n";
      return handle_exception(err.what());
    }
    return ok();
  }

  nl::json xbasic_interpreter::complete_request_impl(const std::string & /*code*/,
                                                     int /*cursor_pos*/) {
    nl::json result;
    result["status"] = "ok";
    return result;
  }

  nl::json xbasic_interpreter::inspect_request_impl(const std::string & /*code*/,
                                                    int /*cursor_pos*/, int /*detail_level*/) {
    nl::json result;
    result["status"] = "ok";
    return result;
  }

  nl::json xbasic_interpreter::is_complete_request_impl(const std::string & /*code*/) {
    nl::json result;
    result["status"] = "complete";
    return result;
  }

  void xbasic_interpreter::configure_impl() {}

  nl::json xbasic_interpreter::kernel_info_request_impl() {
    nl::json info;
    info["implementation"] = "xbasic";
    info["implementation_version"] = "0.1.0";
    std::string banner = R"V0G0N(
                `7MM***Yy.     db       .M***by. `7MMF'  .g8***bg.
                  MM    Yb    ;MM:     ,MI    `Y   MM  .dP'     `M
     `7M'   `MF'  MM    .P   ,V^MM.    `MMb.       MM  dM'       `
       `VA ,V'    MMooon*   ,M  `MM      `YMMNq.   MM  MM
         XMX      MM    `Y. AbmmmqMA   .     `MM   MM  MM.        
       ,V' VA.    MM    ,9 A'     VML  Mb     dM   MM  `Mb.     .'
     .AM.   .MA..JMMonald'AMA.   .AMMA.`*Ybmmd*  .JMML.  `*bMond^
                                                                   
      xeus-basic: a Jupyter Kernel for BASIC Language
      xBASIC Version: 0.1.0")V0G0N";
    info["banner"] = banner;
    info["language_info"]["name"] = "basic";
    info["langauge_info"]["codemirror_mode"] = "vb";
    info["language_info"]["version"] = "0.1.0";
    info["language_info"]["mimetype"] = "text/x-vb";
    info["language_info"]["file_extension"] = ".bas";
    return info;
  }

  void xbasic_interpreter::shutdown_request_impl() {}
}  // namespace xbasic
