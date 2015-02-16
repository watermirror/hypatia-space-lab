#pragma once

namespace base {

template <class T>
class Singleton {
 public:
  static T* GetInstance() {
    static T* unique_instance_ = nullptr;
    if (!unique_instance_)
      unique_instance_ = new T();
    return unique_instance_;
  }
};

}  // namespace base
