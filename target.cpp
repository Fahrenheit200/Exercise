#include<string>
#include<iostream>

using namespace std;

string get_a_target_string()
{
	long target = 0;
	char buf[10];

	cout << "target:";
	cin >> target;
	snprintf(buf, 10, "%ld", target);
	return string(buf);
}

int main()
{
	cout << get_a_target_string() << endl;

	return 0;
}
