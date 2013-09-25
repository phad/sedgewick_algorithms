#include "gtest/gtest.h"
#include "symbol_table.h"

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
  EXPECT_TRUE(table_.isEmpty()) << "Table isEmpty should be true";
  EXPECT_EQ(0, table_.size()) << "Table size should == 0";
}

TEST_F(SymbolTableTest, putToEmptyTableChangesSize) {
  table_.put(1, 2);
  EXPECT_FALSE(table_.isEmpty()) << "Table should no longer be empty";
  EXPECT_EQ(1, table_.size()) << "Table size should be 1";
}

}  // namespace

