#include "ui/process.h"

namespace ui {

Process::Process() {
}


Process::~Process() {
}

void Process::Init(HINSTANCE instance_handle,
                   const std::wstring& command_line,
                   int command_show) {
  instance_handle_ = instance_handle;
  command_line_ = command_line;
  command_show_ = command_show;
}

}  // namespace ui
