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

		random_access_iterator() : _it(NULL) {};
		random_access_iterator(pointer ptr) : _it(ptr) {};
		random_access_iterator(const random_access_iterator &other) : _it(other._it) {};
		~random_access_iterator() {};

		pointer operator->() const { return _it ;};
		reference operator*() const { return *_it ;};

		// Arit operators
		random_access_iterator	&operator++() {_it++; return (*this);};
		random_access_iterator	&operator--() {_it--; return (*this);};
		random_access_iterator	&operator++(int) {random_access_iterator tmp(*this); ++_it; return (tmp);};
		random_access_iterator	&operator--(int) {random_access_iterator tmp(*this); --_it; return (tmp);};
		random_access_iterator	operator+(difference_type n) const { return random_access_iterator<T>(_it + n);};
		difference_type			operator+(const random_access_iterator &other) {return _it + other._it;};
		random_access_iterator	operator-(difference_type n) const { return random_access_iterator<T>(_it - n);};
		difference_type			operator-(const random_access_iterator &other) {return _it + other._it;};

		// Comparaison operators
		bool operator==(const random_access_iterator &other) {return _it == other._it;};
		bool operator!=(const random_access_iterator &other) {return _it != other._it;};
		bool operator<(const random_access_iterator &other) {return _it < other._it;};
		bool operator<=(const random_access_iterator &other) {return _it <= other._it;};
		bool operator>(const random_access_iterator &other) {return _it > other._it;};
		bool operator>=(const random_access_iterator &other) {return _it >= other._it;};

		reference operator[](difference_type n) const { return _it[n];};
	private:
		pointer _it;
	};
}