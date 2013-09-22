#include <stddef.h>

#include "symbol_table.h"

template<class K, class V>
ST<K, V>::ST() {
}

template <class K, class V>
ST<K, V>::~ST() {
}

template <class K, class V>
void ST<K, V>::put(const K& key, V val) {
}

template <class K, class V>
const V* ST<K, V>::get(const K& key) const {
  return NULL;
}

template <class K, class V>
void ST<K, V>::del(const K& key) {
}

template <class K, class V>
bool ST<K, V>::contains(const K& key) const {
  return (get(key) != NULL);
}

template <class K, class V>
bool ST<K, V>::isEmpty() const {
  return (size() == 0);
}

template <class K, class V>
int ST<K, V>::size() const {
  return 0;
}


