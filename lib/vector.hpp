#pragma once
#include <iterator>
#include "./iterators/iterator_traits.hpp"
#include "./iterators/random_access_iterator.hpp"

namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		typedef T				value_type;
		typedef Alloc			allocator_type;
		typedef size_t 			size_type;
		typedef typename	allocator_type::reference &reference;
		typedef typename	allocator_type::const_reference &const_reference;
		typedef typename	allocator_type::pointer pointer;
		typedef typename	allocator_type::const_pointer const_pointer;

		typedef ft::random_access_iterator<value_type> iterator;
		typedef ft::random_access_iterator<const value_type> const_iterator;

		typedef typename ft::iterator_traits<iterator>::difference_type difference_type; //same as ptrdiff

		//ctors
		explicit vector(const allocator_type &alloc = allocator_type()) : _size(0), _volume(0), _allocator(alloc), _tab(NULL) {};
		private:
			size_type		_size;
			size_type		_volume;
			allocator_type	_allocator;
			pointer			_tab;
	};
}
