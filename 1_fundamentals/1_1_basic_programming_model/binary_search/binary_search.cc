#include "binary_search.h"

using std::vector;

namespace sedgewick {

// static
int BinarySearch::rank(int key, const vector<int>& values) {
  int idxLow = 0;
  int idxHigh = values.size() - 1;
  while (idxLow <= idxHigh) {
    int idxMid = idxLow + (idxHigh - idxLow) / 2;
    if (key < values[idxMid]) {
      idxHigh = idxMid - 1;
    } else if (key > values[idxMid]) {
      idxLow = idxMid + 1;
    } else {
      return idxMid;
    }
  }
  return -1;
}

}  // namespace sedgewick

