#pragma once
#include <iterator>
#include <stack>

namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class Vector {
		typedef T				value_type;
		typedef Alloc			allocator_type;
		typedef size_type		size_t;
		typedef difference_type ptrdiff_t;
		typedef typename	allocator_type::reference &reference;
		typedef typename	allocator_type::const_reference &const_reference;
		typedef typename	allocator_type::pointer pointer;
		typedef typename	allocator_type::const_pointer const_pointer;
	};
}
