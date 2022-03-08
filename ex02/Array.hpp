#ifndef ARRAY_HPP
#define ARRAY_HPP

template <class T>
class Array
{
	private:
		T *array;
		unsigned int _size;

	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array &old);
		const Array &operator=(const Array &to_assignation);
		T &operator[](unsigned int n);
		unsigned int size() const;
		class wrong_iter : public std::exception {
			virtual const char *what() const throw();
		};
		
};

template <class T>
Array<T>::Array() {
	this->array = new T[0];
	this->_size = 0;
	return ;
}

template <class T>
Array<T>::~Array() {
	delete [] this->array;
}

template <class T>
Array<T>::Array(unsigned int n) {
	this->array = new T[n];
	this->_size = n;
	return ;
}

template <class T>
Array<T>::Array(const Array &old) {
	unsigned int i = 0;
	this->array = new T[old.size()];
	while (i < old.size())
	{
		this->array[i] = old.array[i];
		i++;
	}
	this->_size = old.size();
	return ;
}

template <class T>
const Array<T> & Array<T>::operator=(const Array<T> &to_assignation) {
	if (this == &to_assignation)
		return (*this);
	if (this->array) {
		delete [] this->array;
	}
	unsigned int i = 0;
	this->array = new T[to_assignation.size()];
	while (i < to_assignation.size())
	{
		this->array[i] = to_assignation.array[i];
		i++;
	}
	this->_size = to_assignation.size();
	return (*this);	
}

template <class T>
T & Array<T>::operator[](unsigned int n) {
	if (this->size() <= n)
		throw (wrong_iter());
	return (this->array[n]);
}

template <class T>
unsigned int Array<T>::size() const {
	return (this->_size);
}

template <class T>
const char *Array<T>::wrong_iter::what() const throw() {
	return ("the array doesn't have member with such number!");
}

#endif
