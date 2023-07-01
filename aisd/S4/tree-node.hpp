#ifndef TREE_NODE
#define TREE_NODE

namespace turkin
{
  template< typename T >
  struct TreeNode
  {
    T data;
    TreeNode< T > * left;
    TreeNode< T > * right;
  };
  
  template< typename T >
  void free(TreeNode< T > * source)
  {
    
  }
  
  template< typename T >
  void copy(TreeNode< T > * source)
  {
    
  }
}

#endif
