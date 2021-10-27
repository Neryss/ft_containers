#pragma once
#include <iterator>

namespace ft
{
	template <class T>
	class random_access_iterator
	{
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef ptrdiff_t difference_type;
		random_access_iterator() : _it(NULL){};
		random_access_iterator(pointer ptr) : _it(ptr){};
		random_access_iterator(const random_access_iterator &other) : _it(other._it){};
		~random_access_iterator();

		bool operator==(const random_access_iterator &other){return _it == other._it};
		bool operator!=(const random_access_iterator &other){return _it != other._it};
	private:
		pointer _it;
	};
}