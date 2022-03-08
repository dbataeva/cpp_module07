#include "whatever.hpp"
#include <iostream>
#include <string>

class Awesome {
	private:
		int _n;

	public:
		Awesome(void): _n(0) {}
		Awesome(int n): _n(n) {}
		Awesome & operator=(Awesome & a) {_n = a._n; return (*this);}
		bool operator==(Awesome const &rhs) const {return (this->_n == rhs._n);}
		bool operator!=(Awesome const &rhs) const {return (this->_n != rhs._n);}
		bool operator>(Awesome const &rhs) const {return (this->_n > rhs._n);}
		bool operator<(Awesome const &rhs) const {return (this->_n < rhs._n);}
		bool operator>=(Awesome const &rhs) const {return (this->_n >= rhs._n);}
		bool operator<=(Awesome const &rhs) const {return (this->_n <= rhs._n);}
		int get_n() const {return (_n);}
};


std::ostream & operator<<(std::ostream &o, Awesome &a) {o << a.get_n(); return (o);}

int main(void) {
	{
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	{
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "\nc = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		char a = 'a';
		char b = 'b';
		std::cout << "\n=== before swap ===\nchar a = " << a << "\nchar b = " << b << std::endl;
		::swap<char>(a, b);
		std::cout << "=== after swap ===\nchar a = " << a << "\nchar b = " << b << std::endl;
		std::cout << "=== min value between a & b = " << ::min<char>(a, b) << std::endl;
		std::cout << "=== max value between a & b = " << ::max<char>(a, b) << std::endl;
	}
	{
		float a = 1.1;
		float b = 1.2;
		std::cout << "\n=== before swap ===\nfloat a = " << a << "\nfloat b = " << b << std::endl;
		::swap<float>(a, b);
		std::cout << "=== after swap ===\nfloat a = " << a << "\nfloat b = " << b << std::endl;
		std::cout << "=== min value between a & b = " << ::min<float>(a, b) << std::endl;
		std::cout << "=== max value between a & b = " << ::max<float>(a, b) << std::endl;
	}
	Awesome a(2), b(4);
	std::cout << "\n=== before swap ===\nAwesome a = " << a << "\nAwesome b = " << b << std::endl;
	::swap<Awesome>(a, b);
	std::cout << "=== after swap ===\nAwesome a = " << a << "\nAwesome b = " << b << std::endl;
	Awesome mi = ::min<Awesome>(a, b);
	std::cout << "=== min value between a & b = " << mi << std::endl;
	Awesome ma = ::max<Awesome>(a, b);
	std::cout << "=== max value between a & b = " << ma << std::endl;
	return (0);
}
