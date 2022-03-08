#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *address, int length, void (*f)(T const &x)) {
	int i = 0;
	while (address && (i < length))
	{
		f(address[i]);
		i++;
	}
	return ;
}

#endif