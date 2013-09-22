#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

template <class K, class V>
class ST {
 public:
  ST();
  virtual ~ST();

  void put(const K& key, V val);
  const V* get(const K& key) const;
  void del(const K& key);
  bool contains(const K& key) const;
  bool isEmpty() const;
  int size() const;
  // iterator
};

#endif

