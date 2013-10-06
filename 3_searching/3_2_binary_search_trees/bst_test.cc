#include <string>

#include "gtest/gtest.h"
#include "bst.h"

using sedgewick::BST;
using std::string;

namespace {

class BSTTest : public ::testing::Test {
 protected:
  BSTTest() { }

  virtual ~BSTTest() { }

  virtual void SetUp() { }

  virtual void TearDown() { } 

  BST<string, int> tree_;
};


TEST_F(BSTTest, emptyTree) {
  ASSERT_TRUE(tree_.isEmpty()) << "Tree isEmpty should be true";
  ASSERT_EQ(0, tree_.size()) << "Tree size should == 0";
}

}  // namespace
