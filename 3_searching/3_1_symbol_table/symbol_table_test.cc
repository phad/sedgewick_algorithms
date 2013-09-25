#include "gtest/gtest.h"
#include "symbol_table.h"

namespace {

class SymbolTableTest : public ::testing::Test {
 protected:
  SymbolTableTest() { }

  virtual ~SymbolTableTest() { }

  virtual void SetUp() { }

  virtual void TearDown() { } 

  sedgewick::ST<int, int> table_;
};


TEST_F(SymbolTableTest, emptyTable) {
  ASSERT_TRUE(table_.isEmpty()) << "Table isEmpty should be true";
  ASSERT_EQ(0, table_.size()) << "Table size should == 0";
}

TEST_F(SymbolTableTest, putToEmptyTableChangesSize) {
  table_.put(1, 2);
  ASSERT_FALSE(table_.isEmpty()) << "Table should no longer be empty";
  ASSERT_EQ(1, table_.size()) << "Table size should be 1";

  table_.put(3, 4);
  ASSERT_EQ(2, table_.size()) << "Table size should be 2";
}

TEST_F(SymbolTableTest, getFromEmptyTableReturnsNull) {
  ASSERT_EQ(NULL, table_.get(1)) << "When table empty, get should return NULL";
}

TEST_F(SymbolTableTest, getRetrievesItemsInTable) {
  table_.put(1, 2);
  ASSERT_FALSE(table_.get(1) == NULL) << "Table should have value for key";
  ASSERT_EQ(2, *table_.get(1)) << "Table should return item previously put";
}

}  // namespace

