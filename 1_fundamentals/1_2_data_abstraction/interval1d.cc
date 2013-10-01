#include <cmath>

#include "interval1d.h"

namespace sedgewick {

Interval1D::Interval1D(double left, double right)
   : left_(left), right_(right) {
}

double Interval1D::length() const {
  return right_ - left_;
}

bool Interval1D::contains(double x) const {
  return (x >= left_) && (right_ >= x);
}

bool Interval1D::intersects(const Interval1D& other) const {
  return false;
}

}  // namespace sedgewick

