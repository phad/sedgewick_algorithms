#include <stddef.h>

#include "symbol_table.h"

namespace sedgewick {

const int kInitialCapacity = 8;
const int kKeyNotFound = -1;

template<typename K, typename V>
ST<K, V>::ST() : capacity_(kInitialCapacity), size_(0) {
  keys_ = new K[capacity_];
  values_ = new V[capacity_];
}

template <typename K, typename V>
ST<K, V>::~ST() {
  delete [] keys_;
  delete [] values_;
}

template <typename K, typename V>
void ST<K, V>::put(const K& key, const V& val) {
  keys_[size_] = key;
  values_[size_] = val;
  ++size_;
}

template <typename K, typename V>
const V* ST<K, V>::get(const K& key) const {
  int r = rank(key);
  return (r == kKeyNotFound) ? NULL : &values_[r];
}

template <typename K, typename V>
void ST<K, V>::del(const K& /*key*/) {
}

template <typename K, typename V>
bool ST<K, V>::contains(const K& key) const {
  return (rank(key) != kKeyNotFound);
}

template <typename K, typename V>
bool ST<K, V>::isEmpty() const {
  return (size() == 0);
}

template <typename K, typename V>
int ST<K, V>::size() const {
  return size_;
}

template <typename K, typename V>
int ST<K, V>::rank(const K& key) const {
  for (int idx = 0; idx < size_; ++idx) {
    if (keys_[idx] == key) {
      return idx;
    }
  }
  return kKeyNotFound;
}

}  // namespace sedgewick

