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

// std::string itoa(int a)
// {
// 	std::ostringstream temp;
// 	temp << a;
// 	return temp.str();
// }

void operators_stack()
{
	std::cout << "ft - " << std::endl;
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

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << "std - " << std::endl;
	ft::stack<int> foo2;
	ft::stack<int> bar2;

	foo2.push(4);
	foo2.push(87);
	foo2.push(54);

	bar2.push(1);
	bar2.push(12);
	bar2.push(5);
	bar2.push(87);
	bar2.push(-1);
	if (foo2==bar2)
		std::cout << "foo and bar are equal\n";
	if (foo2!=bar2)
		std::cout << "foo and bar are not equal\n";
	if (foo2< bar2)
		std::cout << "foo is less than bar\n";
	if (foo2> bar2)
		std::cout << "foo is greater than bar\n";
	if (foo2<=bar2)
		std::cout << "foo is less than or equal to bar\n";
	if (foo2>=bar2)
		std::cout << "foo is greater than or equal to bar\n";
}

void basic_stack()
{
	ft::stack<std::string> stest;
	std::cout << "size after construct : " << stest.size() << std::endl;
	std::cout << "stest empty ? " << stest.empty() << std::endl;
	stest.push("salut");
	stest.push("les");
	stest.push("boys");
	std::cout << "stest empty ? " << stest.empty() << std::endl;
	std::cout << "stest size : " << stest.size() << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << stest.top() << std::endl;
		stest.pop();
	}
	std::cout << "stest size after pop : " << stest.empty() << std::endl;
}

void vstack()
{
	ft::stack<int, ft::vector<int> > vstack;
	std::cout << "size after construct : " << vstack.size() << std::endl;
	std::cout << "vstack empty ? " << vstack.empty() << std::endl;
	vstack.push(1);
	vstack.push(2);
	vstack.push(3);
	std::cout << "vstack empty ? " << vstack.empty() << std::endl;
	std::cout << "vstack size : " << vstack.size() << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << vstack.top() << std::endl;
		vstack.pop();
	}
	std::cout << "vstack size after pop : " << vstack.empty() << std::endl;
}

void dstack()
{
	ft::stack<int, std::deque<int> > dstack;
	std::cout << "size after construct : " << dstack.size() << std::endl;
	std::cout << "dstack empty ? " << dstack.empty() << std::endl;
	dstack.push(1);
	dstack.push(2);
	dstack.push(3);
	std::cout << "dstack empty ? " << dstack.empty() << std::endl;
	std::cout << "dstack size : " << dstack.size() << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << dstack.top() << std::endl;
		dstack.pop();
	}
	std::cout << "dstack size after pop : " << dstack.empty() << std::endl;
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
	ft::stack<int> *copytest = new ft::stack<int>(*test);
	for (int i = 0; i < 10; i++)
		test->push(i * i);
	ft::stack<int> *assign;
	assign = test;
	// (void)copytest;
	std::cout << assign->top() << ' ' << assign->size() << std::endl;
	std::cout << test->top() << ' ' << assign->size() << std::endl;
	std::cout << copytest->top() << ' ' << assign->size() << std::endl;
	// test->push(72);
	// std::cout << assign->top() << ' ' << assign->size() << std::endl;
	// std::cout << test->top() << ' ' << assign->size() << std::endl;
	// std::cout << copytest->top() << ' ' << assign->size() << std::endl;
	// while (test->size())
	// {
	// 	std::cout << test->top() << std::endl;
	// 	test->pop();
	// }
	// while (copytest->size())
	// {
	// 	std::cout << copytest->top() << std::endl;
	// 	copytest->pop();
	// }
	// delete test;
	// delete copytest;
}

void stack_test()
{
	operators_stack();
	basic_stack();
	vstack();
	sped();
	construct();
}