#ifndef BST_H
#define BST_H

#include <iostream>

namespace sedgewick {

template<typename K, typename V>
class BST {
 public:
  BST();
  ~BST();

  int size() const;
  bool isEmpty() const;

  const V* get(const K& key) const;
  void put(const K& key, V value);
  void remove(const K& key);

 private:
  class Node {
   public:
    Node(K key, V value);
    ~Node();

    std::ostream& op_l_chevr(std::ostream&, std::string, bool, bool);

    K key_;
    V value_;
    Node* left_;
    Node* right_;
    int n_;  
  };

  BST(const BST<K, V>&);
  BST<K, V>& operator=(const BST<K, V>&);

  const V* get(Node* node, const K& key) const;
  Node* put(Node* node, const K& key, V value);

  template<typename L, typename W>
  friend std::ostream& operator<<(std::ostream&, const sedgewick::BST<L, W>&);
  Node* root_;
};

}  // namespace sedgewick

#endif
