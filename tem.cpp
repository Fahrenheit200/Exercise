#include<iostream>

using namespace std;

template<class T>
class MyClass
{
	public:
		T a;
		template<typename t1, typename t2>
		T add(const t1 x, const t2 y);
};

template<class T>
	template<typename t1, typename t2>
T MyClass<T>::add(const t1 x, const t2 y)
{
	a = x + y;
	return a;
}

int main()
{
	MyClass<double> A;
	cout << A.add(1, 1.2) << endl;
	MyClass<double> B;
	cout << B.add(1.2, 1) << endl;

	return 0;
}
