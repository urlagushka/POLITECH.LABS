#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

namespace turkin
{
  template< typename K, typename C >
  bool eq(const K & lhs, const K & rhs)
  {
    return !C{}(lhs, rhs) && !C{}(rhs, lhs);
  }

  template< typename K, typename C >
  bool neq(const K & lhs, const K & rhs)
  {
    return !eq< K, C >(lhs, rhs);
  }
}

#endif
