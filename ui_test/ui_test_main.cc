#include <windows.h>

int __stdcall wWinMain(HINSTANCE instance_handle, 
                       HINSTANCE prev_instance_handle,
                       wchar_t* command_line,
                       int unused) {
  MessageBox(nullptr, L"Hello Windows!", L"Talk to me", MB_OK);
}
