#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

namespace sedgewick {

template <typename K, typename V>
class ST {
 public:
  ST();
  virtual ~ST();

  void put(const K& key, const V& val);
  const V* get(const K& key) const;
  void del(const K& key);
  bool contains(const K& key) const;
  bool isEmpty() const;
  int size() const;
  // iterator tbc.

 private:
  // Locate key, returning index in keys_, or -1 if not found.
  int rank(const K& key) const;

  // Disallow copying and assignment.
  ST(const ST&);
  ST& operator=(const ST&);

  int capacity_;
  int size_;
  K* keys_;
  V* values_;
};

}  // namespace sedgewick

#endif

