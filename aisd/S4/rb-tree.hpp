#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <utility>
#include <iterator.hpp>
#include <const-iterator.hpp>
#include "tree-node.hpp"

namespace turkin
{
  template< typename Key, typename Value, typename Compare >
  class RBtree
  {
    using tree_t = std::pair< Key, Value >;
    using tree = RBtree< Key, Value, Compare >;
    using it = Iterator< tree_t >;
    using cit = ConstIterator< tree_t >;
    public:
      RBtree();
      RBtree(const tree & rhs);
      RBtree(tree && rhs);
      tree operator=(const tree & rhs);
      tree operator=(tree && rhs);
      ~RBtree();
    private:
      TreeNode< tree_t > source_;
      Compare cmp_;
  };
}

#endif
