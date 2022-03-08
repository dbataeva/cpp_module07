#include <iostream>
#include "Array.hpp"

class Awesome {
	private:
		float _n;

	public:
		Awesome(void): _n(0) {}
		Awesome(float n): _n(n) {}
		float get_n() const {return (_n);}
};


std::ostream & operator<<(std::ostream &o, Awesome &a) {o << a.get_n(); return (o);}

int main() {
	{
		std::cout << "=== test int ===" << std::endl;
		std::cout << "=== test construction with no parameter ===";
		Array<int> a;
		std::cout << "\nok" << std::endl;
		try {
			std::cout << "\n=== test operator[] with empty array and invalid element number (5) ===" << std::endl;
			std::cout << a[a.size()] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n===test construction by copy with empty arrays ===";
		Array<int> b = a;
		std::cout << "\nok" << std::endl;
		std::cout << "\n=== test size with empty array ===" << std::endl;
		std::cout << b.size() << std::endl;
		std::cout << "\n=== test construction with a parametr ===";
		Array<int> c(5);
		std::cout << "\nok" << std::endl;
		c[0] = 1;
		c[1] = 2;
		c[2] = 3;
		c[3] = 4;
		c[4] = 5;
		try {
			std::cout << "\n=== test operator[] with full array and valid element number(1) ===" << std::endl;
			std::cout << c[1] << std::endl;
			std::cout << "\n=== try to change element of array throught operator[] ===" << std::endl;
			c[0] = 10;
			std::cout << c[0] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "\n=== test operator[] with full array and invalid element number (10) ===" << std::endl;
			std::cout << a[10] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n===test construction by copy with one empty array and one full array ===";
		Array<int> d = c;
		std::cout << "\nok"<< std::endl;
		try {
			std::cout << "\n=== test operator[] after construction by copy and valid element number(2) ===" << std::endl;
			std::cout << d[2] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "\n=== test operator[] after construction by copy and invalid element number (10) ===" << std::endl;
			std::cout << d[10] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n===test assignation operator with one empty array and one full array ===";
		b = c;
		std::cout << "\nok"<< std::endl;
		try {
			std::cout << "\n=== test operator[] after assignation operator and valid element number(3) ===" << std::endl;
			std::cout << d[3] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "\n=== test operator[] after assignation operator and invalid element number (10) ===" << std::endl;
			std::cout << d[10] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n=== test size with full array after copy ===" << std::endl;
		std::cout << b.size() << std::endl;
	}

	{
		std::cout << "\n\n=== test awesome ===" << std::endl;
		std::cout << "=== test construction with no parameter ===";
		Array<Awesome> a;
		std::cout << "\nok" << std::endl;
		try {
			std::cout << "\n=== test operator[] with empty array and invalid element number (5) ===" << std::endl;
			std::cout << "Awesome = " << a[5] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n===test construction by copy with empty arrays ===";
		Array<Awesome> b = a;
		std::cout << "\nok"<< std::endl;
		std::cout << "\n=== test size with empty array ===" << std::endl;
		std::cout << "size = " << b.size() << std::endl;
		std::cout << "\n=== test construction with a parametr ===";
		Array<Awesome> c(4);
		std::cout << "\nok" << std::endl;
		Awesome d(1.1);
		c[0] = d;
		Awesome e(2.22);
		c[1] = e;
		Awesome f(33.33);
		c[2] = f;
		Awesome g(444.4);
		c[3] = g;
		try {
			std::cout << "\n=== test operator[] with full array and valid element number(1) ===" << std::endl;
			std::cout << "Awesome = " << c[1] << std::endl;
			std::cout << "\n=== try to change element of array throught operator[] ===" << std::endl;
			Awesome i(5.5555);
			c[0] = i;
			std::cout << "Awesome = " << c[0] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "\n=== test operator[] with full array and invalid element number (10) ===" << std::endl;
			std::cout << "Awesome = " << a[10] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n===test construction by copy with one empty array and one full array ===";
		Array<Awesome> i = c;
		std::cout << "\nok"<< std::endl;
		try {
			std::cout << "\n=== test operator[] after construction by copy and valid element number(2) ===" << std::endl;
			std::cout << "Awesome = " << i[2] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "\n=== test operator[] after construction by copy and invalid element number (10) ===" << std::endl;
			std::cout << "Awesome = " << i[10] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n===test assignation operator with one empty array and one full array ===";
		b = c;
		std::cout << "\nok"<< std::endl;
		try {
			std::cout << "\n=== test operator[] after assignation operator and valid element number(3) ===" << std::endl;
			std::cout << "Awesome = " << i[3] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "\n=== test operator[] after assignation operator and invalid element number (10) ===" << std::endl;
			std::cout << "Awesome = " << i[10] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n=== test size with full array after copy ===" << std::endl;
		std::cout << "size = " << b.size() << std::endl;
	}

	return (0);
}