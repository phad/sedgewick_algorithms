#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>

namespace sedgewick {

class BinarySearch {
 public:
  static int rank(int key, const std::vector<int>& values);
};

}  // namespace sedgewick

#endif

