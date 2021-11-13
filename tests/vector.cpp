#include <string>
#include <iostream>
#include <sstream>

#ifdef STL
#include <vector>
namespace ft = std;
#else
#include "../includes/vector.hpp"
#endif

template <typename T>
void print_vector(ft::vector<T> vt)
{
	typename ft::vector<T>::iterator it = vt.begin();

	while (it != vt.end())
		std::cout << *it++ << " ";
	std::cout << std::endl;
}

std::string itoa(int a)
{
	std::ostringstream temp;
	temp << a;
	return temp.str();
}

void vector_test()
{
	// if (false)
	{
		ft::vector<char> test;
		for (size_t i = 'a'; i <= 'f'; i++)
			test.push_back(i);
		print_vector(test);
		ft::vector<char> testcpy = ft::vector<char>(test);
		print_vector(testcpy);
		ft::vector<char> testassign = test;
		print_vector(testassign);
		test[2] = 'e';
		print_vector(test);
		print_vector(testcpy);
		print_vector(testassign);
	}
	// if (false)
	{
		ft::vector<char> *test = new ft::vector<char>();
		for (size_t i = 'a'; i <= 'f'; i++)
			test->push_back(i);
		print_vector(*test);
		ft::vector<char> *testcpy = new ft::vector<char>(*test);
		print_vector(*testcpy);
		ft::vector<char> *testassign;
		testassign = test;
		print_vector(*testassign);
		(*test)[2] = 'e';
		print_vector(*test);
		print_vector(*testcpy);
		print_vector(*testassign);
		delete testcpy;
		delete test;
	}
	// if (false)
	{
		ft::vector<char> test;
		for (size_t i = 'a'; i <= 'f'; i++)
			test.push_back(i);
		print_vector(test);
		test.clear();
		print_vector(test);
		for (size_t i = 'a'; i <= 'f'; i++)
			test.push_back(i);
		test.erase(test.begin() + 3);
		print_vector(test);
		test.insert(test.begin() + 3, 'd');
		print_vector(test);
		test.pop_back();
		print_vector(test);
		std::cout << test.front() << ' ' << *test.begin() << ' ' << test.back() << ' ' << *(test.end() - 1) << ' ' << test.empty() << std::endl;
		std::cout << *test.rbegin() << ' ' << *(test.rend() - 1) << ' ' << test.capacity() << std::endl;
		print_vector(test);
		test.clear();
		std::cout << test.size() << ' ' << test.capacity() << ' ' << test.empty() << std::endl;
		print_vector(test);
	}
	// if (false)
	{
		ft::vector<int> itest;
		for (size_t i = 0; i <= 10; i++)
			itest.push_back(i);
		ft::vector<char> ctest;
		for (size_t i = 0; i <= 10; i++)
			ctest.push_back(i);
		ft::vector<std::string> stest;
		for (size_t i = 0; i <= 10; i++)
			stest.push_back(itoa(i));
		std::cout << itest.get_allocator().max_size() << std::endl;
		std::cout << itest.max_size() << std::endl;
		std::cout << ctest.get_allocator().max_size() << std::endl;
		std::cout << ctest.max_size() << std::endl;
		std::cout << stest.get_allocator().max_size() << std::endl;
		std::cout << stest.max_size() << std::endl;
	}
	// if (false)
	{
		ft::vector<char> test;
		for (size_t i = 0; i <= 4; i++)
			test.push_back('a' + i);
		std::cout << test.capacity() << ' ' << test.empty() << ' ' << test.size() << ' ' << test.get_allocator().max_size() << ' ' << test.max_size() << std::endl;
		std::cout << test[0] << ' ' << test[3] << ' ' << test.at(0) << ' ' << test.at(3) << std::endl;
		std::cout << test.capacity() << ' ' << test.empty() << ' ' << test.size() << ' ' << test.get_allocator().max_size() << ' ' << test.max_size() << std::endl;
		// test.resize(10);
		// test.reserve(10);
		test.resize(20);
		std::cout << test.capacity() << ' ' << test.empty() << ' ' << test.size() << ' ' << test.get_allocator().max_size() << ' ' << test.max_size() << std::endl;
		std::cout << std::endl;
		test.push_back('a');
		test.push_back('a');
		test.push_back('a');
		std::cout << test.capacity() << ' ' << test.empty() << ' ' << test.size() << ' ' << test.get_allocator().max_size() << ' ' << test.max_size() << std::endl;
	}
	// if (false)
	{
		ft::vector<char> test1;
		for (size_t i = 0; i <= 2; i++)
			test1.push_back('a' + 1);
		ft::vector<char> test2;
		for (size_t i = 0; i <= 15; i++)
			test2.push_back('a' + 1);
		ft::vector<char> test3;
		for (size_t i = 0; i <= 2; i++)
			test2.push_back('a' + 1);
		std::cout << (test1 < test1) << (test1 <= test1) << (test1 == test1) << (test1 != test1) << (test1 >= test1) << (test1 > test1) << std::endl;
		std::cout << (test1 < test2) << (test1 <= test2) << (test1 == test2) << (test1 != test2) << (test1 >= test2) << (test1 > test2) << std::endl;
		std::cout << (test1 < test3) << (test1 <= test3) << (test1 == test3) << (test1 != test3) << (test1 >= test3) << (test1 > test3) << std::endl;
	}
	// if (false)
	{
		// ft::vector<char> test(10, 'a');
		ft::vector<char> test;
		//BUG : crash if `ft::vector<char> test;`
		print_vector(test);
		test.resize(15, 'e');
		test.reserve(50);
		std::cout << test.capacity() << ' ' << test.empty() << ' ' << test.size() << ' ' << test.get_allocator().max_size() << ' ' << test.max_size() << std::endl;
		test.push_back('b');
		std::cout << test.capacity() << ' ' << test.empty() << ' ' << test.size() << ' ' << test.get_allocator().max_size() << ' ' << test.max_size() << std::endl;
		print_vector(test);
		std::cout << test.capacity() << ' ' << test.empty() << ' ' << test.size() << ' ' << test.get_allocator().max_size() << ' ' << test.max_size() << std::endl;
		ft::vector<char> test2;
		for (size_t i = 0; i <= 10; i++)
			test2.push_back('a' + i);
		ft::vector<char> test3(test2.begin(), test2.end());
		test.swap(test3);
		test2.pop_back();
		test3.erase(test3.begin() + 2);
		test2.erase(test2.begin() + 2, test2.begin() + 2);
		print_vector(test);
		std::cout << test.capacity() << ' ' << test.empty() << ' ' << test.size() << ' ' << test.get_allocator().max_size() << ' ' << test.max_size() << std::endl;
		print_vector(test2);
		std::cout << test2.capacity() << ' ' << test2.empty() << ' ' << test2.size() << ' ' << test2.get_allocator().max_size() << ' ' << test2.max_size() << std::endl;
		print_vector(test3);
		std::cout << test3.capacity() << ' ' << test3.empty() << ' ' << test3.size() << ' ' << test3.get_allocator().max_size() << ' ' << test3.max_size() << std::endl;
		ft::swap(test2, test);
		print_vector(test);
		std::cout << test.capacity() << ' ' << test.empty() << ' ' << test.size() << ' ' << test.get_allocator().max_size() << ' ' << test.max_size() << std::endl;
		print_vector(test2);
		std::cout << test2.capacity() << ' ' << test2.empty() << ' ' << test2.size() << ' ' << test2.get_allocator().max_size() << ' ' << test2.max_size() << std::endl;
	}
	// if (false)
	{
		ft::vector<int> test;
		size_t last = -1;
		for (size_t i = 0; i <= 15000000; i++)
		{
			test.push_back(i);
			if (last != test.capacity())
			{
				std::cout << i << ' ' << test.capacity() << ' ' << test.empty() << ' ' << test.size() << std::endl;
				last = test.capacity();
			}
		}
		std::cout << test.capacity() << ' ' << test.empty() << ' ' << test.size() << ' ' << test.get_allocator().max_size() << ' ' << test.max_size() << std::endl;
	}
	// if (false)
	{
		ft::vector<char> tab;
		for (int i = 65; i < 85; i++)
			tab.push_back(i);
		ft::vector<char>::iterator it = tab.begin();
		while (it != tab.end())
			std::cout << *it++ << ' ';
		std::cout << std::endl;
		ft::vector<char>::const_iterator cit = --it;
		std::cout << *cit << std::endl;
		ft::vector<char> rtab;
		for (int i = 65; i < 85; i++)
			rtab.push_back(i);
		ft::vector<char>::reverse_iterator rit = rtab.rbegin();
		while (rit != rtab.rend())
			std::cout << *rit++ << ' ';
		std::cout << std::endl;
		ft::vector<char>::const_reverse_iterator rcit = --rit;
		std::cout << *rcit << std::endl;
		std::cout << std::endl;
	}
}