#include<iostream>
#include<ctime>
#include<array>
#include<cstdlib>
#include "A.h"

using namespace std;

void test_array()
{
	cout << "\ntest_array() ................\n";
	array<long, 500000> c;

	clock_t timestart = clock();
	srand(time(NULL));
	for(long i = 0; i < 500000; i++)
		c[i] = rand();
	cout << "milli-seconds: " << (clock() - timestart) << endl;
	cout << "array.size(): " << c.size() << endl;
	cout << "array.front(): " << c.front() << endl;
	cout << "array.back(): " << c.back() << endl;
	cout << "array.data(): " << c.data() << endl;

	long target = get_a_target_long();
	timestart = clock();
	qsort(c.data(), 500000, sizeof(long), compareLongs);
	long* pItem = (long*)bsearch(&target, c.data(), 500000, sizeof(long), compareLongs);
	cout << "qsort() + bsearch(), milli-seconds: " << (clock() - timestart) << endl;
	if(pItem != NULL)
		cout << "found " << *pItem << endl;
	else
		cout << "not found!" << endl;
}

int main()
{
	test_array();
	return 0;
}
