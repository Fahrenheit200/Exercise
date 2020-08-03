#include<vector>
#include<stdexcept>
#include<cstdlib> //abort()
#include<cstdio>  //snprintf()
#include<ctime>
#include<algorithm> //sort()
#include "V.h"
#include<iostream>

using namespace std;

void test_vector(long value)
{
	cout << "\ntest_vector() ..........\n";

	vector<string> c;
	char buf[10];
	clock_t timestart = clock();
	srand(time(NULL));
	for(long i = 0; i < value; i++)
	{
		try{
			snprintf(buf, 10, "%d", rand());
			c.push_back(string(buf));
		}
		catch(exception& p){
			cout << "i = " << i << " " << p.what() << endl;
			abort();
		}
	}

	cout << "milli-seconds: " << (clock() - timestart) << endl;
	cout << "vector.size(): " << c.size() << endl;
	cout << "vector.front(): " << c.front() << endl;
	cout << "vector.back(): " << c.back() << endl;
	cout << "vector.data(): " << c.data() << endl;
	cout << "vector.capacity(): " << c.capacity() << endl;

	string target = get_a_target_string();
	timestart = clock();

	auto pItem1 = ::find(c.begin(), c.end(), target);
	cout << "::find(), milli-seconds: " << (clock() - timestart) << endl;
	if(pItem1 != c.end())
		cout << "found " << *pItem1 << endl;
	else
		cout << "not found!" << endl;

	timestart = clock();
	sort(c.begin(), c.end());
	string* pItem2 = (string*)bsearch(&target, c.data(), c.size(), sizeof(string), compareStrings);
	cout << "sort() + bsearch() milli-seconds: " << (clock() - timestart) << endl;

	if(pItem2 != NULL)
		cout << "found " << *pItem2 << endl;
	else
		cout << "not found!" << endl;
}

int main()
{
	test_vector(1000000);
	return 0;
}
