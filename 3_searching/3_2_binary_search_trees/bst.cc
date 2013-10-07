#include <stddef.h>

#include "bst.h"

using std::cout;
using std::endl;
using std::ostream;

namespace sedgewick {

template<typename K, typename V>
BST<K, V>::BST() : root_(NULL) {
}

template<typename K, typename V>
BST<K, V>::~BST() {
  delete root_;
}

template<typename K, typename V>
int BST<K, V>::size() const {
  return root_ ? root_->n_ : 0;
}

template<typename K, typename V>
bool BST<K, V>::isEmpty() const {
  return size() == 0;
}

template<typename K, typename V>
const V* BST<K, V>::get(const K& key) const {
  return get(root_, key);
}

template<typename K, typename V>
void BST<K, V>::put(const K& key, V value) {
  root_ = put(root_, key, value);
}

template<typename K, typename V>
void BST<K, V>::remove(const K& /*key*/) {
  // tbd
}

template<typename K, typename V>
const V* BST<K, V>::get(Node* node, const K& key) const {
  if (key == node->key_) {
    return &node->value_;
  } else if (key < node->key_ && node->left_) {
    return get(node->left_, key);
  } else if (key > node->key_ && node->right_) {
    return get(node->right_, key);
  }
  return NULL;
}

template<typename K, typename V>
typename BST<K, V>::Node* BST<K, V>::put(Node* node, const K& key, V value) {
  if (!node) {
    return new Node(key, value);
  }
  if (key < node->key_) {
    node->left_ = put(node->left_, key, value);     
  } else if (key > node->key_) {
    node->right_ = put(node->right_, key, value);     
  } else {
    node->value_ = value;
  }
  node->n_ = 1 +
      (node->left_  ? node->left_->n_  : 0) +
      (node->right_ ? node->right_->n_ :0 );
  return node;
}

template<typename K, typename V>
std::ostream& operator<<(std::ostream& ostr, const BST<K, V>& bst) {
  return bst.root_->op_l_chevr(ostr, "" , false, true);
}

template<typename K, typename V>
BST<K, V>::Node::Node(K key, V value) :
  key_(key), value_(value), left_(NULL), right_(NULL), n_(1) {
}

template<typename K, typename V>
BST<K, V>::Node::~Node() {
  delete left_;
  delete right_;
}

// Tree output inspired by:
// http://stackoverflow.com/questions/1649027/how-do-i-print-out-a-tree-structure
template<typename K, typename V>
std::ostream& BST<K, V>::Node::op_l_chevr(std::ostream& ostr,
    std::string indent, bool isLeft, bool isLast) {
  ostr << indent;
  bool isRoot = indent.size() == 0;
  if (isLast) {
    ostr << "\\-";
    indent += "  ";
  } else {
    ostr << "|-";
    indent += "| ";
  }
  if (isRoot) {
    ostr << "o-";
  } else {
    ostr << (isLeft ? "<-" : ">-");
  }
  ostr << key_ << "(" << value_ << ")" << endl;
  if (left_) {
    left_->op_l_chevr(ostr, indent, true, (right_ == NULL));
  }
  if (right_) {
    right_->op_l_chevr(ostr, indent, false, true);
  }
  return ostr;
}

}  // namespace sedgewick
