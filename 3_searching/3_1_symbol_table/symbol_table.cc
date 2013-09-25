#include <stddef.h>

#include "symbol_table.h"

namespace sedgewick {

const int kInitialCapacity = 8;

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
  return NULL;
}

template <typename K, typename V>
void ST<K, V>::del(const K& key) {
}

template <typename K, typename V>
bool ST<K, V>::contains(const K& key) const {
  return (get(key) != NULL);
}

template <typename K, typename V>
bool ST<K, V>::isEmpty() const {
  return (size() == 0);
}

template <typename K, typename V>
int ST<K, V>::size() const {
  return size_;
}

}  // namespace sedgewick

