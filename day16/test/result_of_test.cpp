#include <iostream>
#include <type_traits>

#include <functional>

typedef double(*FUNC)(double);

// typedef int(*FUNC)(double)
 
double func(double d)
{
	return d;
}

// result_of<函数指针(参数)>
int main()
{
	std::result_of<FUNC(double)>::type d = func(9.0);
	return 0;
}