#pragma once

#include <string>
#include <windows.h>

#include "base/singleton.h"

namespace ui {

class Process : public base::Singleton<Process> {
 public:
  Process();
  virtual ~Process();

  void Init(HINSTANCE instance_handle,
           const std::wstring& command_line,
           int command_show);

  HINSTANCE instance_handle() {
    return instance_handle_;
  }

  const std::wstring& command_line() {
    return command_line_;
  }

  int command_show() {
    return command_show_;
  }

 private:
  HINSTANCE instance_handle_ = nullptr;
  std::wstring command_line_;
  int command_show_ = 0;
};

}  // namespace ui
