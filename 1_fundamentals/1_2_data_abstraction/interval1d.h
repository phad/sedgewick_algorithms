#ifndef INTERVAL_1D_H
#define INTERVAL_1D_H

namespace sedgewick {

class Interval1D {
 public:
  Interval1D(double left, double right);
  double left() const { return left_; }
  double right() const { return right_; }
  double length() const;
  bool contains(double x) const;
  bool intersects(const Interval1D& other) const;

 private:
  double left_;
  double right_;
};

}  // namespace sedgewick

#endif

