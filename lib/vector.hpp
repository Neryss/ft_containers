#pragma once
#include <iterator>
#include "../utils/is_integral.hpp"
#include "./iterators/iterator_traits.hpp"
#include "./iterators/random_access_iterator.hpp"

namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		public:
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
			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _size(n), _volume(n), _allocator(alloc), _tab(NULL)
			{
				_tab = _allocator.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_tab[i], val);
			};
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL) : _size(0), _volume(0), _allocator(alloc), _tab(NULL)
			{
				_size = last - first;
				_volume = _size;
				_tab = _allocator.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_tab[i], *(first + i));
			}
			vector(const vector &o) : _size(0)
			{
				_size = o._size;
				_volume = o._volume;
				_tab = _allocator.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_tab[i], x._tab[i]);
			}

			~vector() {_allocator.deallocate(_tab, _size);};
			
			reference operator[] (size_type n)
			{
				reference idx = *(_tab + n);
				return idx;
			};
		private:
			size_type		_size;
			size_type		_volume;
			allocator_type	_allocator;
			pointer			_tab;
	};
}
