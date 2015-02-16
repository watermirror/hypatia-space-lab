#pragma once

#include <map>
#include <string>
#include <windows.h>

#include "base/singleton.h"
#include "ui/color.h"

namespace ui {

struct WindowClassInfo {
};

class WindowClassManager : public base::Singleton<WindowClassManager> {
 public:
  WindowClassManager();
  virtual ~WindowClassManager();

  const std::string& GetDefaultClassName() const;

  bool Register(const std::string& class_name,
                const WindowClassInfo& class_info,
                bool as_default = false);
  bool Unregister(const std::string& class_name);

 private:
  std::map<std::string, WindowClassInfo> registered_classes_;
  std::string default_class_name_;
};

}  // namespace ui
