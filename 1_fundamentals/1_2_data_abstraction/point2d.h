#ifndef POINT_2D_H
#define POINT_2D_H

namespace sedgewick {

class Point2D {
 public:
  Point2D(double X, double Y);
  double x() const { return x_; }
  double y() const { return y_; }
  double r() const;
  double theta() const;
  double distanceTo(const Point2D& other) const;

 private:
  double x_;
  double y_;
};

}  // namespace sedgewick

#endif

