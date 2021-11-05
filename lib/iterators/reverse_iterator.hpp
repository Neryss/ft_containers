#pragma once

#include "./iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef Iterator iterator_type;
			typedef typename iterator_traits<Iterator>::value_type value_type;
			typedef typename iterator_traits<Iterator>::reference reference;
			typedef typename iterator_traits<Iterator>::pointer pointer;
			typedef typename iterator_traits<Iterator>::difference_type difference_type;
			typedef typename iterator_traits<Iterator>::iterator_category iterator_category;

			//CONSTRUCTORS
			reverse_iterator() : _baseIt(){}
			explicit reverse_iterator(iterator_type it) : _baseIt(it){}
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter> &rev_it) : _baseIt(rev_it.base()){}

			iterator_type base() const { return _baseIt; }

			//DEREFERENCED OPERATORS
			reference operator*() const 
			{
				iterator_type tmp = _baseIt;
				--tmp;
				return *tmp;
			}
			pointer operator->() const
			{
				return &(operator*());
			}
			//ARITHMETIC OPERATORS
			reverse_iterator operator+ (difference_type n) const { return reverse_iterator(_baseIt - n); }
			reverse_iterator operator- (difference_type n) const { return reverse_iterator(_baseIt + n); }
			//INCREMENT DECREMENT OPERATORS
			reverse_iterator &operator++()
			{
				--_baseIt;
				return *this;
			}
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				--_baseIt;
				return tmp;
			}
			reverse_iterator &operator--()
			{
				++_baseIt;
				return *this;
			}
			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				++_baseIt;
				return tmp;
			}
			
			reverse_iterator &operator+=(difference_type n)
			{
				_baseIt -= n;
				return *this;
			}
			reverse_iterator &operator-=(difference_type n)
			{
				_baseIt += n;
				return *this;
			}
			//ACCESS OPERATOR
			reference operator[](difference_type n) const { return *(_baseIt - n - 1); }

		private:
			iterator_type _baseIt;
	};

	//NON MEMBER FUNCTIONS
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
	{
		return rev_it + n;
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() - rhs.base();
	}
}
