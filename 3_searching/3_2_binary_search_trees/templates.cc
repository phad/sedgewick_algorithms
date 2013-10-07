#include <iostream>
#include <string>

#include "bst.h"
#include "bst.cc"

namespace sedgewick {

template class BST<std::string, int>;

template std::ostream& operator<<(std::ostream& ostr,
    const BST<std::string, int>& bst);

}  // namespace sedgewick
