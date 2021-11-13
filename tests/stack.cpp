#include <string>
#include <iostream>
#include <sstream>

#ifdef STL
#include <stack>
namespace ft = std;
#else
#include "../includes/stack.hpp"
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
	if (foo2==bar2) std::cout << "foo and bar are equal\n";
	if (foo2!=bar2) std::cout << "foo and bar are not equal\n";
	if (foo2< bar2) std::cout << "foo is less than bar\n";
	if (foo2> bar2) std::cout << "foo is greater than bar\n";
	if (foo2<=bar2) std::cout << "foo is less than or equal to bar\n";
	if (foo2>=bar2) std::cout << "foo is greater than or equal to bar\n";
}

void stack_test()
{
	// ft::stack<int> itest;
	// for (size_t i = 0; i < 0; i++)
	// 	itest.push(i);
	// ft::stack<char> ctest;
	// for (size_t i = 0; i < 0; i++)
	// 	ctest.push(i);
	// ft::stack<std::string> stest;
	// for (size_t i = 0; i < 0; i++)
	// 	stest.push(itoa(i));
	operators_stack();
}