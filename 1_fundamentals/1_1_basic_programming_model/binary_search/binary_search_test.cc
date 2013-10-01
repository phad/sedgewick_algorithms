#include <iostream>

#include "gtest/gtest.h"
#include "binary_search.h"

using sedgewick::BinarySearch;
using namespace std;

namespace {

class BinarySearchTest : public ::testing::Test {
 protected:
  BinarySearchTest() { }

  virtual ~BinarySearchTest() { }

  virtual void SetUp() { }

  virtual void TearDown() { } 
};

const vector<int> kEmpty;

const int kOne_[]   = {3};
const vector<int> kOne(kOne_, kOne_ + (sizeof(kOne_)/sizeof(int)));

const int kTwo_[]   = {5, 8};
const vector<int> kTwo(kTwo_, kTwo_ + (sizeof(kTwo_)/sizeof(int)));

const int kTen_[]   = {1, 4, 5, 8, 13, 14, 16, 29, 31, 48};
const vector<int> kTen(kTen_, kTen_ + (sizeof(kTen_)/sizeof(int)));

TEST_F(BinarySearchTest, emptyValueList) {
  ASSERT_EQ(-1, BinarySearch::rank(1, kEmpty))
      << "searching empty list should return -1";
}

TEST_F(BinarySearchTest, searchingListSizeOne) {
  ASSERT_EQ(0, BinarySearch::rank(3, kOne))
      << "searching only element in list size 1 should return 0";
  ASSERT_EQ(-1, BinarySearch::rank(2, kOne))
      << "search lt only element in list size 1 should return -1";
  ASSERT_EQ(-1, BinarySearch::rank(4, kOne)) 
      << "search gt only element in list size 1 should return -1";
}

TEST_F(BinarySearchTest, searchingListSizeTwo) {
  ASSERT_EQ(0, BinarySearch::rank(5, kTwo));
  ASSERT_EQ(1, BinarySearch::rank(8, kTwo));
  ASSERT_EQ(-1, BinarySearch::rank(10, kTwo));
}

TEST_F(BinarySearchTest, searchingListSizeTen) {
  ASSERT_EQ(-1, BinarySearch::rank(0, kTen));
  ASSERT_EQ(0, BinarySearch::rank(1, kTen));
  ASSERT_EQ(4, BinarySearch::rank(13, kTen));
  ASSERT_EQ(5, BinarySearch::rank(14, kTen));
  ASSERT_EQ(9, BinarySearch::rank(48, kTen));
  ASSERT_EQ(-1, BinarySearch::rank(50, kTen));
}

}  // namespace

