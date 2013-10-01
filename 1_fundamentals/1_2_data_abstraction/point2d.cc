#include <cmath>

#include "point2d.h"

namespace sedgewick {

Point2D::Point2D(double X, double Y)
   : x_(X), y_(Y) {
}

double Point2D::r() const {
  return distanceTo(Point2D(0.0, 0.0));
}

double Point2D::theta() const {
  return atan2(y_, x_);
}

double Point2D::distanceTo(const Point2D& other) const {
  double deltaX = x_ - other.x_;
  double deltaY = y_ - other.y_;
  return sqrt(pow(deltaX, 2.0) + pow(deltaY, 2.0));
}

}  // namespace sedgewick

