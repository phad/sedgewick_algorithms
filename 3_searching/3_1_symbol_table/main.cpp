#include <assert.h>

#include "symbol_table.h"

int main(int argc, char** argv) {
  ST<int, int> table;
  assert(table.size() == 0);
  assert(table.isEmpty());

  table.put(1, 2);
  assert(table.size() == 1);
  assert(!table.isEmpty());

  return 0;
}

