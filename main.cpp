#include "./includes/vector.hpp"
#include "./includes/stack.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

#define PURPLE "\e[35m"
#define GREEN "\e[32m"
#define RED "\e[31;1m"
#define RESET "\e[0m"

void vector_test(void);
void stack_test(void);
void map_test(void);

int main(void)
{

#ifdef STL
	std::cout << "STL build" << std::endl;
#else
	std::cout << "FT build" << std::endl;
#endif

	clock_t start;
	clock_t end;

	start = clock();
	{
		size_t pass = 40;
		for (size_t i = 0; i < pass; i++)
		{
			std::cout << "pass " << i + 1 << '/' << pass << std::endl;
			vector_test();
			stack_test();
			map_test();
		}
	}
	end = clock();
	double difference = difftime(end, start);
	std::cout << std::fixed << std::showpoint << std::setprecision(3);
	std::cout << difference / 1000000 << " seconds" << std::endl;

	return 0;
}