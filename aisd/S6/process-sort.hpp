#ifndef PROCESS_SORT_HPP
#define PROCESS_SORT_HPP

#include <deque>
#include <list>
#include <dictionary/forward-list/forward-list.hpp>

#include "out-storage.hpp"
#include <sort/qsort.hpp>
#include <sort/shell.hpp>
#include <sort/merge.hpp>

#include "random-storage.hpp"

#include <cstddef>
#include <ostream>

namespace turkin
{
  template< typename T, typename UnaryPred >
  void process(std::size_t amount, std::ostream & out)
  {
    std::deque< T > deque = fill< std::deque< T >, T >(amount);
    std::list< T > list;
    ForwardList< T > forward_list;
    for (auto it: deque)
    {
      list.push_front(it);
      forward_list.push_front(it);
    }

    UnaryPred p;

    merge_sort(forward_list.begin(), forward_list.size(), p);
    out_storage(forward_list.begin(), forward_list.end(), out) << "\n";

    quick_sort(list.begin(), list.end(), p);
    out_storage(list.begin(), list.end(), out) << "\n";
    shell_sort(list.begin(), list.end(), p);
    out_storage(list.begin(), list.end(), out) << "\n";
    merge_sort(list.begin(), list.size(), p);
    out_storage(list.begin(), list.end(), out) << "\n";

    quick_sort(deque.begin(), deque.end(), p);
    out_storage(deque.begin(), deque.end(), out) << "\n";
    shell_sort(deque.begin(), deque.end(), p);
    out_storage(deque.begin(), deque.end(), out) << "\n";
    merge_sort(deque.begin(), deque.size(), p);
    out_storage(deque.begin(), deque.end(), out) << "\n";
  }
}

#endif
