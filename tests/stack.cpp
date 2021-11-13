#include <string>
#include <iostream>
#include <sstream>
#include <deque>

#ifdef STL
#include <vector>
#include <stack>
namespace ft = std;
#else
#include "../includes/stack.hpp"
#include "../includes/vector.hpp"
#endif

void operators_stack()
{
	ft::stack<int> foo;
	ft::stack<int> bar;

	foo.push(4);
	foo.push(87);
	foo.push(54);

	bar.push(1);
	bar.push(12);
	bar.push(5);
	bar.push(87);
	bar.push(-1);

	std::cout << (foo == bar) << std::endl;
	std::cout << (foo != bar) << std::endl;
	std::cout << (foo < bar) << std::endl;
	std::cout << (foo > bar) << std::endl;
	std::cout << (foo >= bar) << std::endl;
	std::cout << (foo <= bar) << std::endl;
}

void basic_stack()
{
	ft::stack<std::string> stest;
	std::cout << stest.size() << std::endl;
	std::cout << stest.empty() << std::endl;
	stest.push("salut");
	stest.push("les");
	stest.push("boys");
	std::cout << stest.empty() << std::endl;
	std::cout << stest.size() << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << stest.top() << std::endl;
		stest.pop();
	}
	std::cout << stest.empty() << std::endl;
}

void vstack()
{
	ft::stack<int, ft::vector<int> > vstack;
	std::cout << vstack.size() << std::endl;
	std::cout << vstack.empty() << std::endl;
	vstack.push(1);
	vstack.push(2);
	vstack.push(3);
	std::cout << vstack.empty() << std::endl;
	std::cout  << vstack.size() << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << vstack.top() << std::endl;
		vstack.pop();
	}
	std::cout << vstack.empty() << std::endl;
}

void dstack()
{
	ft::stack<int, std::deque<int> > dstack;
	std::cout << dstack.size() << std::endl;
	std::cout << dstack.empty() << std::endl;
	dstack.push(1);
	dstack.push(2);
	dstack.push(3);
	std::cout << dstack.empty() << std::endl;
	std::cout << dstack.size() << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << dstack.top() << std::endl;
		dstack.pop();
	}
	std::cout << dstack.empty() << std::endl;
}

void sped()
{
	ft::stack<int> sped;
	for (int i = 0; i < 15000000; i++)
	{
		sped.push(i);
		if (i % 1000000 == 0)
			std::cout << sped.size() << ' ' << sped.top() << std::endl;
	}
	std::cout << sped.size() << std::endl;
	while (sped.size() > 0)
		sped.pop();
	std::cout << sped.size() << std::endl;
}

void construct()
{
	ft::stack<int> *test = new ft::stack<int>();
	for (int i = 0; i < 10; i++)
		test->push(i * i);
	ft::stack<int> *copy = new ft::stack<int>(*test);
	ft::stack<int> *assign;
	assign = test;	
	std::cout << assign->top() << ' ' << assign->size() << std::endl;
	std::cout << test->top() << ' ' << assign->size() << std::endl;
	std::cout << copy->top() << ' ' << copy->size() << std::endl;
	test->push(72);
	std::cout << assign->top() << ' ' << assign->size() << std::endl;
	std::cout << test->top() << ' ' << assign->size() << std::endl;
	std::cout << copy->top() << ' ' << copy->size() << std::endl;
	while (test->size())
	{
		std::cout << test->top() << std::endl;
		test->pop();
	}
	while (copy->size())
	{
		std::cout << copy->top() << std::endl;
		copy->pop();
	}
	delete test;
	delete copy;
}

void stack_test()
{
	operators_stack();
	basic_stack();
	vstack();
	sped();
	construct();
}