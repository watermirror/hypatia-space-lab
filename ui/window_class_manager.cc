#include "ui/window_class_manager.h"

#include "ui/process.h"

namespace {
const char kDefaultWindowClassName[] = "__default_window_class_name__";
}  // namespace

namespace ui {

WindowClassManager::WindowClassManager() {
  WindowClassInfo info;
  Register(kDefaultWindowClassName, info, true);
}

WindowClassManager::~WindowClassManager() {
  for (const auto& kvp : registered_classes_) {
    Unregister(kvp.first.c_str());
  }
}

const std::string& WindowClassManager::GetDefaultClassName() const {
  if (default_class_name_.empty()) {
    for (const auto& kvp : registered_classes_) {
      return kvp.first;
    }
  }
  return default_class_name_;
}

bool WindowClassManager::Register(const std::string& class_name,
                                  const WindowClassInfo& class_info,
                                  bool as_default) {
  if (registered_classes_.find(class_name) != std::end(registered_classes_))
    return false;

  WNDCLASSEXA wcex;
  wcex.cbSize = sizeof(WNDCLASSEX);
  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = nullptr;
  wcex.cbClsExtra = 0;
  wcex.cbWndExtra = 0;
  wcex.hInstance = Process::GetInstance()->instance_handle();
  wcex.hIcon = nullptr;
  wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
  wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
  wcex.lpszMenuName = nullptr;
  wcex.lpszClassName = class_name.c_str();
  wcex.hIconSm = nullptr;

  bool ret = (RegisterClassExA(&wcex) != 0);
  if (ret) {
    registered_classes_[class_name] = class_info;
    if (as_default)
      default_class_name_ = class_name;
  }
  return ret;
}

bool WindowClassManager::Unregister(const std::string& class_name) {
  if (UnregisterClassA(class_name.c_str(),
                       Process::GetInstance()->instance_handle())) {
    return true;
  }
  return false;
}

}  // namespace ui
