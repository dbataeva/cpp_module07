#include "iter.hpp"
#include <iostream>
#include <string>

class Awesome {
	private:
		int _n;

	public:
		Awesome(void): _n(42) {return ;}
		int get_n() const {return (this->_n);}
};

std::ostream & operator<<(std::ostream &o, Awesome const &rhs) {o << rhs.get_n(); return (o);}

template<typename T>
void print(T const &x) {std::cout << x << std::endl; return ;}

int main () {
	{
		int tab[] = {0, 1, 2, 3, 4};
		Awesome tab2[5];

		std::cout << "=== test int ===" <<std::endl;
		iter(tab, 5, print);
		std::cout << "\n=== test own class ===" <<std::endl;
		iter(tab2, 5, print);
	}
	{
		float tab[] = {1.1, 2.2, 3.3, 4.4};
		std::cout << "\n=== test float ===" <<std::endl;
		iter(tab, 4, print);
	}
	{
		std::cout << "\n=== test string ===" <<std::endl;
		std::string str[] = {"qwerty", "asdfg", "zxcvb"};
		iter(str, 3, print);
	}
	return (0);
}