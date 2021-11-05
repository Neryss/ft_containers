#include "./lib/vector.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <iostream>

#define PURPLE "\e[35m"
#define GREEN "\e[32m"
#define RED "\e[31;1m"
#define RESET "\e[0m"

void contructors()
{
	std::cout << RED << "DEFAULT CONSTRUCTOR" << std::endl;

	ft::vector<char> tab;
	tab.push_back('c');
	tab.push_back('b');
	tab.push_back('a');

	ft::vector<char>::iterator it = tab.begin();

	while (it != tab.end())
		std::cout << PURPLE << *it++ << ' ';
	std::cout << " - ft" << std::endl;

	std::vector<char> tab2;
	tab2.push_back('c');
	tab2.push_back('b');
	tab2.push_back('a');

	std::vector<char>::iterator it2 = tab2.begin();

	while (it2 != tab2.end())
		std::cout << GREEN << *it2++ << ' ';
	std::cout << " - std" << std::endl;

	/*------------------------------------------------------------*/

	std::cout << RED << "FILL CONSTRUCTOR" << std::endl;

	ft::vector<int> fill(10, 5);
	std::vector<int> fill2(10, 5);

	ft::vector<int>::iterator fillIt = fill.begin();
	std::vector<int>::iterator fillIt2 = fill2.begin();

	while (fillIt != fill.end())
		std::cout << PURPLE << *fillIt++ << ' ';
	std::cout << " - ft" << std::endl;

	while (fillIt2 != fill2.end())
		std::cout << GREEN << *fillIt2++ << ' ';
	std::cout << " - std" << std::endl;

	/*------------------------------------------------------------*/

	std::cout << RED << "RANGE CONSTRUCTOR" << std::endl;

	ft::vector<int> range(fill.begin(), fill.end());
	std::vector<int> range2(fill2.begin(), fill2.end());

	ft::vector<int>::iterator rangeIt = range.begin();
	std::vector<int>::iterator rangeIt2 = range2.begin();

	while (rangeIt != range.end())
		std::cout << PURPLE << *rangeIt++ << ' ';
	std::cout << " - ft" << std::endl;

	while (rangeIt2 != range2.end())
		std::cout << GREEN << *rangeIt2++ << ' ';
	std::cout << " - std" << std::endl;

	/*------------------------------------------------------------*/

	std::cout << RED << "COPY CONSTRUCTOR" << std::endl;

	ft::vector<std::string> cop(5, "yo");
	std::vector<std::string> cop2(5, "yo");

	ft::vector<std::string> copy(cop);
	std::vector<std::string> copy2(cop2);

	ft::vector<std::string>::iterator copyIt = copy.begin();
	std::vector<std::string>::iterator copyIt2 = copy2.begin();

	while (copyIt != copy.end())
		std::cout << PURPLE << *copyIt++ << ' ';
	std::cout << " - ft" << std::endl;

	while (copyIt2 != copy2.end())
		std::cout << GREEN << *copyIt2++ << ' ';
	std::cout << " - std" << std::endl;

	std::cout << RED << "OPERATOR = " << std::endl;

	ft::vector<std::string> o1(5, "hey");
	std::vector<std::string> o2(5, "hey");

	ft::vector<std::string> o3 = o1;
	std::vector<std::string> o4 = o2;
	ft::vector<std::string>::iterator oit = o3.begin();
	std::vector<std::string>::iterator oit2 = o4.begin();

	while (oit != o3.end())
		std::cout << PURPLE << *oit++ << ' ';
	std::cout << " - ft" << std::endl;

	while (oit2 != o4.end())
		std::cout << GREEN << *oit2++ << ' ';
	std::cout << " - std" << std::endl;

	std::cout << std::endl;
}

void iterators()
{
	std::cout << RED << "ITERATORS" << std::endl;

	ft::vector<char> tab;

	for (int i = 65; i < 85; i++)
		tab.push_back(i);
	ft::vector<char>::iterator it = tab.begin();
	while (it != tab.end())
		std::cout << PURPLE << *it++ << ' ';
	std::cout << " - ft" << std::endl;

	std::vector<char> tab2;

	for (int i = 65; i < 85; i++)
		tab2.push_back(i);
	std::vector<char>::iterator it2 = tab2.begin();
	while (it2 != tab2.end())
		std::cout << GREEN << *it2++ << ' ';
	std::cout << " - std" << std::endl;

	/*------------------------------------------------------------*/

	std::cout << RED << "CONST ITERATORS" << std::endl;

	ft::vector<char>::const_iterator cit = --it;
	std::vector<char>::const_iterator cit2 = --it2;

	std::cout << PURPLE << *cit << "  - ft" << std::endl;
	std::cout << GREEN << *cit2 << "  - std" << std::endl;

	/*------------------------------------------------------------*/
	std::cout << RED << "REVERSE ITERATORS" << std::endl;
	ft::vector<char> rtab;

	for (int i = 65; i < 85; i++)
		rtab.push_back(i);
	ft::vector<char>::reverse_iterator rit = rtab.rbegin();
	while (rit != rtab.rend())
		std::cout << PURPLE << *rit++ << ' ';
	std::cout << " - ft" << std::endl;

	std::vector<char> rtab2;

	for (int i = 65; i < 85; i++)
		rtab2.push_back(i);
	std::vector<char>::reverse_iterator rit2 = rtab2.rbegin();
	while (rit2 != rtab2.rend())
		std::cout << GREEN << *rit2++ << ' ';
	std::cout << " - std" << std::endl;

	/*------------------------------------------------------------*/

	std::cout << RED << "CONST REVERSE ITERATORS" << std::endl;

	ft::vector<char>::const_reverse_iterator rcit = --rit;
	std::vector<char>::const_reverse_iterator rcit2 = --rit2;

	std::cout << PURPLE << *rcit << "  - ft" << std::endl;
	std::cout << GREEN << *rcit2 << "  - std" << std::endl;

	std::cout << std::endl;
}

void capacity()
{
	std::cout << RED << "CAPACITY" << std::endl;

	ft::vector<int> tab(5, 10);
	std::vector<int> tab2(5, 10);

	std::cout << PURPLE << "size : " << tab.size() << "  - ft" << std::endl;
	std::cout << GREEN << "size : " << tab2.size() << "  - std" << std::endl;

	std::cout << PURPLE << "max size : " << tab.max_size() << "  - ft" << std::endl;
	std::cout << GREEN << "max size : " << tab2.max_size() << "  - std" << std::endl;

	tab.resize(10, 10);
	tab2.resize(10, 10);

	for (int i = 0; i < 10; i++)
		std::cout << PURPLE << tab[i] << ' ';
	std::cout << " - ft" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << GREEN << tab2[i] << ' ';
	std::cout << " - std" << std::endl;

	std::cout << PURPLE << "is empty : " << tab.empty() << "  - ft" << std::endl;
	std::cout << GREEN << "is empty : " << tab2.empty() << "  - std" << std::endl;

	tab.reserve(20);
	tab2.reserve(20);

	std::cout << PURPLE << "capacity : " << tab.capacity() << "  - ft" << std::endl;
	std::cout << GREEN << "capacity : " << tab2.capacity() << "  - std" << std::endl;

	std::cout << std::endl;
}

void access()
{
	std::cout << RED << "ELEMENT ACCESS" << std::endl;
	ft::vector<char> tab;
	for (int i = 65; i < 85; i++)
		tab.push_back(i);

	std::vector<char> tab2;
	for (int i = 65; i < 85; i++)
		tab2.push_back(i);

	std::cout << PURPLE << "tab[3] : " << tab[3] << "  - ft" << std::endl;
	std::cout << GREEN << "tab[3] : " << tab2[3] << "  - std" << std::endl;

	std::cout << PURPLE << "tab at 3 : " << tab.at(3) << "  - ft" << std::endl;
	std::cout << GREEN << "tab at 3 : " << tab2.at(3) << "  - std" << std::endl;

	std::cout << PURPLE << "front : " << tab.front() << "  - ft" << std::endl;
	std::cout << GREEN << "front : " << tab2.front() << "  - std" << std::endl;

	std::cout << PURPLE << "back : " << tab.back() << "  - ft" << std::endl;
	std::cout << GREEN << "back : " << tab2.back() << "  - std" << std::endl;

	std::cout << std::endl;
}

void printTab(ft::vector<int> &tab)
{
	std::cout << PURPLE << "tab : ";
	for (size_t i = 0; i < tab.size(); i++)
		std::cout << PURPLE << tab[i] << ' ';
	std::cout << " - ft" << std::endl;
}

void printTab(std::vector<int> &tab)
{
	std::cout << GREEN << "tab : ";
	for (size_t i = 0; i < tab.size(); i++)
		std::cout << GREEN << tab[i] << ' ';
	std::cout << " - std" << std::endl;
}

void modifiers()
{
	std::cout << RED << "MODIFIERS" << std::endl;

	ft::vector<int> tab(3, 2);
	std::vector<int> tab2(3, 2);

	printTab(tab);
	printTab(tab2);

	std::cout << PURPLE << "push_back(5) : ";
	tab.push_back(5);
	printTab(tab);

	std::cout << GREEN << "push_back(5) : ";
	tab2.push_back(5);
	printTab(tab2);

	std::cout << PURPLE << "pop_back : ";
	tab.pop_back();
	printTab(tab);

	std::cout << GREEN << "pop_back : ";
	tab2.pop_back();
	printTab(tab2);

	std::cout << PURPLE << "assign two 3 : ";
	tab.assign(2, 3);
	printTab(tab);

	std::cout << GREEN << "assign two 3 : ";
	tab2.assign(2, 3);
	printTab(tab2);

	std::cout << PURPLE << "insert 1 : ";
	tab.insert(tab.begin(), 1);
	printTab(tab);

	std::cout << GREEN << "insert 1 : ";
	tab2.insert(tab2.begin(), 1);
	printTab(tab2);

	std::cout << PURPLE << "erase 1 : ";
	tab.erase(tab.begin());
	printTab(tab);

	std::cout << GREEN << "erase 1 : ";
	tab2.erase(tab2.begin());
	printTab(tab2);

	std::cout << PURPLE << "clear : ";
	tab.clear();
	printTab(tab);

	std::cout << GREEN << "clear : ";
	tab2.clear();
	printTab(tab2);

	ft::vector<int> a(3, 10);
	ft::vector<int> b(5, 7);

	std::cout << PURPLE << "a : ";
	printTab(a);
	std::cout << GREEN << "b : ";
	printTab(b);
	std::cout << RESET << "swap" << std::endl;
	a.swap(b);
	std::cout << PURPLE << "a : ";
	printTab(a);
	std::cout << GREEN << "b : ";
	std::cout << GREEN << "tab : ";
	for (size_t i = 0; i < b.size(); i++)
		std::cout << GREEN << b[i] << ' ';
	std::cout << " - std" << std::endl;

	std::cout << std::endl;
}

void operators()
{
	std::cout << RED << "OPERATORS" << std::endl;

	std::cout << PURPLE << "ft - " << std::endl;
	ft::vector<int> foo(3, 100);
	ft::vector<int> bar(2, 200);
	if (foo == bar)
		std::cout << "foo and bar are equal\n";
	if (foo != bar)
		std::cout << "foo and bar are not equal\n";
	if (foo < bar)
		std::cout << "foo is less than bar\n";
	if (foo > bar)
		std::cout << "foo is greater than bar\n";
	if (foo <= bar)
		std::cout << "foo is less than or equal to bar\n";
	if (foo >= bar)
		std::cout << "foo is greater than or equal to bar\n";

	std::cout << GREEN << "std - " << std::endl;
	std::vector<int> bar2(2, 200);
	std::vector<int> foo2(3, 100);
	if (foo2 == bar2)
		std::cout << "foo and bar are equal\n";
	if (foo2 != bar2)
		std::cout << "foo and bar are not equal\n";
	if (foo2 < bar2)
		std::cout << "foo is less than bar\n";
	if (foo2 > bar2)
		std::cout << "foo is greater than bar\n";
	if (foo2 <= bar2)
		std::cout << "foo is less than or equal to bar\n";
	if (foo2 >= bar2)
		std::cout << "foo is greater than or equal to bar\n";
}

void vector_test()
{
	std::cout << "-------------------------------------------------------------------" << std::endl;
	std::cout << "VECTOR TEST" << std::endl
			  << std::endl;
	contructors();
	iterators();
	capacity();
	access();
	modifiers();
	operators();
	std::cout << "--------------------------------------------------------------------" << std::endl;
}

int main(void)
{
	vector_test();
	return (0);
}