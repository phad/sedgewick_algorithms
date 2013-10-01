#include <cmath>
#include <iostream>

#include "gtest/gtest.h"
#include "point2d.h"

using sedgewick::Point2D;
using namespace std;

namespace {

class Point2DTestr : public ::testing::Test {
 protected:
  Point2DTestr() { }

  virtual ~Point2DTestr() { }

  virtual void SetUp() { }

  virtual void TearDown() { } 
};

TEST(Point2DTest, constructorAndGetters) {
  Point2D p1(0.0, 0.0);
  ASSERT_EQ(0.0, p1.x());
  ASSERT_EQ(0.0, p1.y());

  Point2D p2(-1.4, 5.26);
  ASSERT_EQ(-1.4, p2.x());
  ASSERT_EQ(5.26, p2.y());
}

TEST(Point2DTest, radius) {
  Point2D p1(3.0, 4.0);
  ASSERT_EQ(5.0, p1.r());

  Point2D p2(-8.8, -6.6);
  ASSERT_EQ(11.0, p2.r());
}

TEST(Point2DTest, distanceTo) {
  Point2D p1(10.0, 0.0);
  Point2D p2(0.0, 10.0);
  ASSERT_EQ(10.0 * sqrt(2.0), p1.distanceTo(p2));
}

TEST(Point2DTest, theta) {
  const double kPiBy4 = atan(1.0);
  ASSERT_EQ(0 * kPiBy4,  Point2D(1.0, 0.0).theta());
  ASSERT_EQ(1 * kPiBy4,  Point2D(1.0, 1.0).theta());
  ASSERT_EQ(2 * kPiBy4,  Point2D(0.0, 1.0).theta());
  ASSERT_EQ(3 * kPiBy4,  Point2D(-1.0, 1.0).theta());
  ASSERT_EQ(4 * kPiBy4,  Point2D(-1.0, 0.0).theta());
  EXPECT_EQ(-3 * kPiBy4, Point2D(-1.0, -1.0).theta());
  ASSERT_EQ(-2 * kPiBy4, Point2D(0.0, -1.0).theta());
  ASSERT_EQ(-1 * kPiBy4, Point2D(1.0, -1.0).theta());
}

}  // namespace

