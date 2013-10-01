#include <stddef.h>
#include <stdexcept>

#include "symbol_table.h"

namespace sedgewick {

const int kInitialCapacity = 8;
const int kKeyNotFound = -1;

template<typename K, typename V>
ST<K, V>::ST() : capacity_(kInitialCapacity), size_(0) {
  keys_ = new K[capacity_];
  values_ = new V[capacity_];
}

template<typename K, typename V>
ST<K, V>::ST(int initial_capacity) : capacity_(initial_capacity), size_(0) {
  if (initial_capacity <= 0) {
    throw new std::invalid_argument("capacity");
  }
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
  if (size_ == capacity_) {
    grow();
  }
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
int ST<K, V>::capacity() const {
  return capacity_;
}

// private methods

template <typename K, typename V>
int ST<K, V>::rank(const K& key) const {
  for (int idx = 0; idx < size_; ++idx) {
    if (keys_[idx] == key) {
      return idx;
    }
  }
  return kKeyNotFound;
}

template <typename K, typename V>
void ST<K, V>::grow() {
  int next_capacity = 2 * capacity_;
  K* next_keys   = new K[next_capacity];
  V* next_values = new V[next_capacity];
  for (int idx = 0; idx < size_; ++idx) {
    next_keys[idx] = keys_[idx];
    next_values[idx] = values_[idx];
  }
  delete [] keys_;
  delete [] values_;
  keys_ = next_keys;
  values_ = next_values;
  capacity_ = next_capacity;
}

}  // namespace sedgewick


