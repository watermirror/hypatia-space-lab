#pragma once

#include <windows.h>

namespace ui {

class Color {
 public:
  Color() {}

  Color(unsigned int r, unsigned int g, unsigned int b)
      : integral_color_value_(RGB(r, g, b)) {}

  Color(unsigned int a, unsigned int r, unsigned int g, unsigned int b)
      : integral_color_value_(RGB(r, g, b)) {
    integral_color_value_ |= (a << 24);
  }

  void SetRGB(unsigned int r, unsigned int g, unsigned int b) {
    integral_color_value_ = RGB(r, g, b);
  }

  void SetARGB(unsigned int a, unsigned int r, unsigned int g, unsigned int b) {
    integral_color_value_ = RGB(r, g, b);
    integral_color_value_ |= (a << 24);
  }

  unsigned int a() const {
    return (LOBYTE((integral_color_value_) >> 24));
  }

  unsigned int r() const {
    return GetRValue(integral_color_value_);
  }

  unsigned int g() const {
    return GetGValue(integral_color_value_);
  }

  unsigned int b() const {
    return GetBValue(integral_color_value_);
  }

  operator COLORREF() const {
    return integral_color_value_;
  }

 private:
  unsigned int integral_color_value_ = 0;
};

}  // namespace ui
