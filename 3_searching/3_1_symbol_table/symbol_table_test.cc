#include "gtest/gtest.h"
#include "symbol_table.h"

using sedgewick::ST;

namespace {

class SymbolTableTest : public ::testing::Test {
 protected:
  SymbolTableTest() { }

  virtual ~SymbolTableTest() { }

  virtual void SetUp() { }

  virtual void TearDown() { } 

  ST<int, int> table_;
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

TEST_F(SymbolTableTest, putBeyondCapacityGrowsTable) {
  ST<int, int> table(2);
  ASSERT_EQ(2, table.capacity()) << "Initial capacity should be that specified";
  table.put(1, 2);
  table.put(2, 3);
  table.put(3, 4);
  ASSERT_EQ(4, table.capacity()) << "Table should have grown to double initial capacity";
  ASSERT_EQ(2, *table.get(1));
  ASSERT_EQ(3, *table.get(2));
  ASSERT_EQ(4, *table.get(3));
}

}  // namespace
