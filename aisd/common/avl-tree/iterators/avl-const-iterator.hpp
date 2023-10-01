#ifndef AVL_CONST_ITERATOR_HPP
#define AVL_CONST_ITERATOR_HPP

#include <utility>
#include <cassert>
#include "avl-tree/tree-node.hpp"

namespace turkin
{
  template< typename K, typename V, typename C >
  class AVLtree;
  template< typename K, typename V, typename C >
  class AVLIterator;
  template< typename K, typename V, typename C >
  class AVLConstIterator
  {
    friend class AVLtree< K, V, C >;
    friend class AVLIterator< K, V, C >;
    using it = AVLIterator< K, V, C >;
    using cit = AVLConstIterator< K, V, C >;
    using tree_t = std::pair< K, V >;
    using node_t = TreeNode< tree_t > *;
    public:
      AVLConstIterator();
      cit & operator=(const cit & rhs) = default;
      ~AVLConstIterator() = default;
      cit & operator++();
      cit operator++(int);
      cit & operator--();
      cit operator--(int);
      const tree_t & operator*() const;
      const tree_t * operator->() const;
      bool operator==(const cit & rhs) const;
      bool operator!=(const cit & rhs) const;
    private:
      explicit AVLConstIterator(node_t rhs, node_t end);
      explicit AVLConstIterator(const it & rhs);
      node_t cur_;
      node_t end_;
  };
}

template< typename K, typename V, typename C >
turkin::AVLConstIterator< K, V, C >::AVLConstIterator():
  cur_(nullptr),
  end_(nullptr)
{}

template< typename K, typename V, typename C >
turkin::AVLConstIterator< K, V, C >::AVLConstIterator(node_t rhs, node_t end):
  cur_(rhs),
  end_(end)
{}

template< typename K, typename V, typename C >
turkin::AVLConstIterator< K, V, C >::AVLConstIterator(const it & rhs):
  cur_(rhs.cur_),
  end_(rhs.end_)
{}

template< typename K, typename V, typename C >
turkin::AVLConstIterator< K, V, C > & turkin::AVLConstIterator< K, V, C >::operator++()
{
  assert(cur_ != nullptr);
  if (cur_->right != end_)
  {
    cur_ = cur_->right;
    while (cur_->left != end_)
    {
      cur_ = cur_->left;
    }
  }
  else
  {
    node_t parent = cur_->parent;
    while (parent != end_ && cur_ == parent->right)
    {
      cur_ = parent;
      parent = parent->parent;
    }
    cur_ = parent;
  }
  return * this;
}

template< typename K, typename V, typename C >
turkin::AVLConstIterator< K, V, C > turkin::AVLConstIterator< K, V, C >::operator++(int)
{
  assert(cur_ != nullptr);
  auto result(*this);
  ++(*this);
  return result;
}

template< typename K, typename V, typename C >
turkin::AVLConstIterator< K, V, C > & turkin::AVLConstIterator< K, V, C >::operator--()
{
  assert(cur_ != nullptr);
  if (cur_->left != end_)
  {
    cur_ = cur_->left;
    while (cur_->right != end_)
    {
      cur_ = cur_->right;
    }
  }
  else
  {
    node_t parent = cur_->parent;
    if (cur_ != end_)
    {
      while (parent != end_ && cur_ == parent->left)
      {
        cur_ = parent;
        parent = parent->parent;
      }
    }
    cur_ = parent;
  }
  return * this;
}

template< typename K, typename V, typename C >
turkin::AVLConstIterator< K, V, C > turkin::AVLConstIterator< K, V, C >::operator--(int)
{
  assert(cur_ != nullptr);
  auto result(*this);
  --(*this);
  return result;
}

template< typename K, typename V, typename C >
const std::pair< K, V > & turkin::AVLConstIterator< K, V, C >::operator*() const
{
  assert(cur_ != nullptr);
  return cur_->data;
}

template< typename K, typename V, typename C >
const std::pair< K, V > * turkin::AVLConstIterator< K, V, C >::operator->() const
{
  assert(cur_ != nullptr);
  return std::addressof(cur_->data);
}

template< typename K, typename V, typename C >
bool turkin::AVLConstIterator< K, V, C >::operator==(const AVLConstIterator< K, V, C > & rhs) const
{
  return cur_ == rhs.cur_;
}

template< typename K, typename V, typename C >
bool turkin::AVLConstIterator< K, V, C >::operator!=(const AVLConstIterator< K, V, C > & rhs) const
{
  return !(rhs == *this);
}

#endif
