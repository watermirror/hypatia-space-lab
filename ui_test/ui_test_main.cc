#include <windows.h>

#include "ui/process.h"

int __stdcall wWinMain(HINSTANCE instance_handle,
                       HINSTANCE prev_instance_handle,
                       wchar_t* command_line,
                       int command_show) {
  ui::Process::GetInstance()->Init(instance_handle, command_line, command_show);
  MessageBox(nullptr, L"Hello Windows!", L"Talk to me", MB_OK);
}
