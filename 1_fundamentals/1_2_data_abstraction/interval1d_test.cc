#include <cmath>

#include "gtest/gtest.h"
#include "interval1d.h"

using sedgewick::Interval1D;
using namespace std;

namespace {

TEST(Interval1DTest, zeroLengthInterval) {
  Interval1D i1(0.0, 0.0);
  ASSERT_EQ(0.0, i1.left());
  ASSERT_EQ(0.0, i1.right());
  ASSERT_EQ(0.0, i1.length());

  Interval1D i2(-4.0, -4.0);
  ASSERT_EQ(0.0, i2.length());
}

}  // namespace

