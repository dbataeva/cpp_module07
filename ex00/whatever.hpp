template <class T>
void swap(T &a, T &b) {
	T store = a;

	a = b;
	b = store;
	return ;
}

template <class T>
T min(T a, T b) {
	if (a < b)
		return (a);
	if (b < a)
		return (b);
	return (b);
}

template <class T>
T max(T a, T b) {
	if (a > b)
		return (a);
	if (b > a)
		return (b);
	return (b);
}
