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

TEST_F(BSTTest, putNewKeysAddsNodes) {
  tree_.put("foo", 1);
  ASSERT_EQ(1, tree_.size()) << "Tree size should == 1";
  tree_.put("bar", 11);
  ASSERT_EQ(2, tree_.size()) << "Tree size should == 2";
  tree_.put("baz", 111);
  ASSERT_EQ(3, tree_.size()) << "Tree size should == 3";
}

TEST_F(BSTTest, getExistingKeysReturnsValues) {
  tree_.put("foo", 1);
  tree_.put("bar", 11);

  ASSERT_EQ(1, *tree_.get("foo")) << "Tree should return value for key 'foo'";
  ASSERT_EQ(11, *tree_.get("bar")) << "Tree should return value for key 'bar'";
}

TEST_F(BSTTest, putExistingKeysUpdatesNodes) {
  tree_.put("foo", 1);
  ASSERT_EQ(1, tree_.size()) << "Tree size should == 1";
  ASSERT_EQ(1, *tree_.get("foo")) << "Tree should return value for key 'foo'";

  tree_.put("foo", 2);
  ASSERT_EQ(1, tree_.size()) << "Tree size should == 1";
  ASSERT_EQ(2, *tree_.get("foo")) << "Tree should return value for key 'foo'";
}

}  // namespace
