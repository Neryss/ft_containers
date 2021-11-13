#include <string>
#include <iostream>
#include <cstdlib>
#include "../includes/utils/tests.hpp"

#ifdef STL
#include <map>
namespace ft = std;
#else
#include "../includes/map.hpp"
#endif

template <typename T1, typename T2>
void print_map(ft::map<T1, T2> map)
{
	for (typename ft::map<T1, T2>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << it->first << " [" << it->second << "] ";
	std::cout << std::endl;
}
template <typename T1, typename T2, typename T3>
void print_map(ft::map<T1, ft::pair<T2, T3> > map)
{
	for (typename ft::map<T1, T2>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << it->first << " [" << it->second.first << ", " << it->second.second << "]";
	std::cout << std::endl;
}
template <typename T1, typename T2, typename T3>
void print_map(ft::map<T1, T2, T3> map)
{
	for (typename ft::map<T1, T2, T3>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << it->first << " [" << it->second << "] ";
	std::cout << std::endl;
}

int get_rand(int min, int max)
{
	return (((std::rand() / (float)RAND_MAX) * (max - min)) + min);
}

void map_test()
{
	// if (false)
	{
		ft::map<char, int> test;
		test['a'] = 10;
		test['b'] = 30;
		test['d'] = 70;
		ft::map<char, int> test2(test.begin(), test.end());
		ft::map<char, int> test3(test2);
		test3.insert(ft::make_pair('c', 15));
		test3.insert(ft::make_pair('j', 150));
		test3['d'] = 100;
		ft::map<char, int> test4 = test3;
		test['b'] = 40;
		test3['d'] = 90;
		print_map(test);
		print_map(test2);
		print_map(test3);
		print_map(test4);
	}
	// if (false)
	{
		ft::map<char, int> m1;

		for (int i = 65; i < 85; i++)
			m1.insert(ft::make_pair(i, 1));
		ft::map<char, int>::iterator it = m1.begin();
		ft::map<char, int>::const_iterator cit = ++m1.begin();
		ft::map<char, int>::reverse_iterator rit = m1.rbegin();
		ft::map<char, int>::const_reverse_iterator crit = ++m1.rbegin();
		while (it != m1.end())
			std::cout << it++->first << ' ';
		std::cout << std::endl;
		std::cout << cit->first << std::endl;
		while (rit != m1.rend())
			std::cout << rit++->first << ' ';
		std::cout << std::endl;
		std::cout << crit->first << std::endl;
		std::cout << std::endl;
	}
	// if (false)
	{
		ft::map<std::string, char> tab;
		tab.insert(ft::make_pair("hey", 'A'));
		tab.insert(ft::make_pair("kk", 'D'));
		tab.insert(ft::make_pair("lol", 'K'));
		std::cout << tab.size() << std::endl;
		std::cout << tab.empty() << std::endl;
		std::cout << tab.max_size() << std::endl;
		std::cout << tab.get_allocator().max_size() << std::endl;
	}
	// if (false)
	{
		ft::map<std::string, char> tab;
		tab.insert(ft::make_pair("hey", 'A'));
		tab.insert(ft::make_pair("kk", 'D'));
		tab.insert(ft::make_pair("lol", 'K'));
		std::cout << tab["lol"] << std::endl;
		std::cout << tab["kk"] << std::endl;
	}
	// if (false)
	{
		ft::map<char, int> mymap;
		mymap.insert(ft::pair<char, int>('a', 100));
		mymap.insert(ft::pair<char, int>('z', 200));
		ft::pair<ft::map<char, int>::iterator, bool> ret;
		ret = mymap.insert(ft::pair<char, int>('z', 500));
		if (ret.second == false)
			std::cout << ret.first->second << std::endl;
		ft::map<char, int>::iterator it = mymap.begin();
		mymap.insert(it, ft::pair<char, int>('b', 300));
		mymap.insert(it, ft::pair<char, int>('c', 400));
		ft::map<char, int> anothermap;
		anothermap.insert(mymap.begin(), mymap.find('c'));
		for (it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << ' ';
		std::cout << std::endl;
		for (it = anothermap.begin(); it != anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << ' ';
		std::cout << std::endl;
	}
	// if (false)
	{
		ft::map<char, int> mymap;
		ft::map<char, int>::iterator it;
		mymap['a'] = 10;
		mymap['b'] = 20;
		mymap['c'] = 30;
		mymap['d'] = 40;
		mymap['e'] = 50;
		mymap['f'] = 60;
		it = mymap.find('b');
		mymap.erase(it);
		mymap.erase('c');
		it = mymap.find('e');
		mymap.erase(it, mymap.end());
		for (it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << ' ';
		std::cout << std::endl;
	}
	// if (false)
	{
		ft::map<char, int> foo;
		ft::map<char, int> bar;
		foo['x'] = 100;
		foo['y'] = 200;
		bar['a'] = 11;
		bar['b'] = 22;
		bar['c'] = 33;
		foo.swap(bar);
		for (ft::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
			std::cout << it->first << " => " << it->second << ' ';
		std::cout << std::endl;
		for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
			std::cout << it->first << " => " << it->second << ' ';
		std::cout << std::endl;
	}
	// if (false)
	{
		ft::map<int, int> tab;
		tab.insert(ft::make_pair(1, 5));
		tab.insert(ft::make_pair(3, 8));
		tab.insert(ft::make_pair(5, 66));
		tab.insert(ft::make_pair(13, 5));
		std::cout << tab.size() << std::endl;
		tab.clear();
		std::cout << tab.size() << std::endl;
	}
	// if (false)
	{
		ft::map<char, int> mymap;
		char c;
		mymap['a'] = 101;
		mymap['c'] = 202;
		mymap['f'] = 303;
		for (c = 'a'; c < 'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c) > 0)
				std::cout << true;
			else
				std::cout << false;
		}
		std::cout << std::endl;
	}
	// if (false)
	{
		ft::map<char, int> mymap;
		ft::map<char, int>::iterator itlow;
		ft::map<char, int>::iterator itup;
		mymap['a'] = 20;
		mymap['b'] = 40;
		mymap['c'] = 60;
		mymap['d'] = 80;
		mymap['e'] = 100;
		itlow = mymap.lower_bound('b');
		itup = mymap.upper_bound('d');
		mymap.erase(itlow, itup);
		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << ' ';
		std::cout << std::endl;
	}
	// if (false)
	{
		ft::map<char, int> mymap;
		mymap['a'] = 10;
		mymap['b'] = 20;
		mymap['c'] = 30;
		ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
		ret = mymap.equal_range('b');
		std::cout << ret.first->first << " => " << ret.first->second << ' ';
		std::cout << std::endl;
		std::cout << ret.second->first << " => " << ret.second->second << ' ';
		std::cout << std::endl;
	}
	// if (false)
	{
		ft::map<int, char> test;
		ft::map<int, char> test2;
		ft::map<int, char> test3;
		test.insert(ft::make_pair(1, 'a'));
		test.insert(ft::make_pair(2, 'b'));
		test.insert(ft::make_pair(3, 'c'));
		test2.insert(ft::make_pair(7, 'Z'));
		test2.insert(ft::make_pair(8, 'Y'));
		test2.insert(ft::make_pair(9, 'X'));
		test2.insert(ft::make_pair(10, 'W'));
		test3.insert(ft::make_pair(1, 'a'));
		test3.insert(ft::make_pair(2, 'b'));
		test3.insert(ft::make_pair(3, 'c'));
		std::cout << (test == test2);
		std::cout << (test != test2);
		std::cout << (test < test2);
		std::cout << (test <= test2);
		std::cout << (test > test2);
		std::cout << (test >= test2);
		std::cout << (test == test3);
		std::cout << (test != test3);
		std::cout << (test < test3);
		std::cout << (test <= test3);
		std::cout << (test > test3);
		std::cout << (test >= test3);
		std::cout << std::endl;
	}
	// if (false)
	{
		std::srand(1);
		ft::map<int, char> test;
		for (size_t i = 0; i < 1000000; i++)
		{
			test.insert(ft::make_pair(get_rand(0, 100), get_rand(0, 100)));
			if (i % 100000 == 0)
			{
				std::cout << i << ' ' << i << ' ' << test.empty() << ' ' << test.size() << std::endl;
			}
		}
		std::cout << ' ' << test.empty() << ' ' << test.size() << ' ' << test.get_allocator().max_size() << ' ' << test.max_size() << std::endl;
	}
	// if (false)
	{
		std::srand(1);
		cmpValues cmp;
		ft::map<int, char, cmpValues> test(cmp);
		for (size_t i = 0; i < 1000; i++)
		{
			test.insert(ft::make_pair(get_rand(0, 100), get_rand(32, 127)));
			if (i % 100 == 0)
			{
				std::cout << i << ' ' << i << ' ' << test.empty() << ' ' << test.size() << std::endl;
			}
		}
		print_map(test);
		std::cout << ' ' << test.empty() << ' ' << test.size() << ' ' << test.get_allocator().max_size() << ' ' << test.max_size() << std::endl;
	}
}