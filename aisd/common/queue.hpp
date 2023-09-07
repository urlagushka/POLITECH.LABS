#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstring>
#include <stdexcept>
#include <utility>
#include <dictionary/forward-list/oneway-list.hpp>

namespace turkin
{
  template< typename T >
  class Queue
  {
    public:
      Queue();
      Queue(const Queue< T > & rhs);
      Queue(Queue< T > && rhs);
      Queue & operator=(const Queue< T > & rhs);
      Queue & operator=(Queue< T > && rhs);
      ~Queue();
      void swap(Queue< T > & rhs) noexcept;
      void push(const T & rhs);
      T & get();
      const T & get() const;
      void pop();
      bool isEmpty() const;
    private:
      OneWayNode< T > * value_;
      OneWayNode< T > * back_;
  };
}

template< typename T >
turkin::Queue< T >::Queue():
  value_(nullptr),
  back_(nullptr)
{}

template< typename T >
turkin::Queue< T >::Queue(const Queue< T > & rhs):
  value_(nullptr),
  back_(nullptr)
{
  auto clone = copyList(rhs.value_);
  value_ = clone.first;
  back_ = clone.second;
}

template< typename T >
turkin::Queue< T >::Queue(Queue< T > && rhs):
  value_(rhs.value_),
  back_(rhs.back_)
{
  rhs.value_ = nullptr;
  rhs.back_ = nullptr;
}

template< typename T >
turkin::Queue< T > & turkin::Queue< T >::operator=(const Queue< T > & rhs)
{
  Queue< T > temp(rhs);
  swap(temp);
  return * this;
}

template< typename T >
turkin::Queue< T > & turkin::Queue< T >::operator=(Queue< T > && rhs)
{
  free(value_);
  value_ = nullptr;
  back_ = nullptr;
  swap(rhs);
  return * this;
}

template< typename T >
turkin::Queue< T >::~Queue()
{
  free(value_);
}

template< typename T >
void turkin::Queue< T >::swap(Queue< T > & rhs) noexcept
{
  std::swap(value_, rhs.value_);
  std::swap(back_, rhs.back_);
}

template< typename T >
void turkin::Queue< T >::push(const T & rhs)
{
  OneWayNode< T > * element = new OneWayNode< T > {rhs, nullptr};
  if (isEmpty())
  {
    value_ = element;
    back_ = element;
    value_->next = back_;
  }
  else
  {
    back_->next = element;
    back_ = back_->next;
  }
}

template< typename T >
T & turkin::Queue< T >::get()
{
  if (isEmpty())
  {
    throw std::runtime_error("queue is empty");
  }
  return value_->data;
}

template< typename T >
const T & turkin::Queue< T >::get() const
{
  if (isEmpty())
  {
    throw std::runtime_error("queue is empty");
  }
  return value_->data;
}

template< typename T >
void turkin::Queue< T >::pop()
{
  if (isEmpty())
  {
    throw std::runtime_error("queue is empty");
  }
  OneWayNode< T > * element = value_;
  if (value_ == back_)
  {
    value_ = nullptr;
    back_ = nullptr;
  }
  else
  {
    value_ = value_->next;
  }
  delete element;
}

template< typename T >
bool turkin::Queue< T >::isEmpty() const
{
  return value_ == nullptr;
}

#endif
