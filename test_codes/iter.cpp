#include <cstddef>
#include <iostream>
#include <typeinfo>

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <class _Category, class _Tp, class _Distance = ptrdiff_t,
          class _Pointer = _Tp*, class _Reference = _Tp& >
struct iterator {
  typedef _Category  iterator_category;
  typedef _Tp        value_type;
  typedef _Distance  difference_type;
  typedef _Pointer   pointer;
  typedef _Reference reference;
};

template <class _Iterator>
struct iterator_traits {
  typedef typename _Iterator::iterator_category iterator_category;
  typedef typename _Iterator::value_type        value_type;
  typedef typename _Iterator::difference_type   difference_type;
  typedef typename _Iterator::pointer           pointer;
  typedef typename _Iterator::reference         reference;
};

class back_insert_iterator
  : public iterator<output_iterator_tag, void, void, void, void> {
public:
//   typedef output_iterator_tag iterator_category;
    int i;
};

int main() {
    // back_insert_iterator BI;
    // back_insert_iterator::iterator_category;
    // back_insert_iterator::value_type;
    // back_insert_iterator::difference_type;
    std::cout << typeid(back_insert_iterator::iterator_category).name() << std::endl;
    std::cout << typeid(back_insert_iterator::value_type).name() << std::endl;
    std::cout << typeid(back_insert_iterator::difference_type).name() << std::endl;
    std::cout << typeid(back_insert_iterator::pointer).name() << std::endl;
    std::cout << typeid(back_insert_iterator::reference).name() << std::endl;
}