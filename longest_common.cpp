#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(string x, string y)
{
	return (x.size() < y.size());
}

string longestCommon(vector<string>& strs)
{
	sort(strs.begin(), strs.end(), compare);
	auto p = strs.begin();
	string com = *p;
	int len = com.size();
	p++;
	for(; p != strs.end(); ++p)
	{
		while(len != 0)
		{
			if(com == (*p).substr((*p).size() - len))
				break;
			else{
				com = com.substr(1);
				len = com.size();
			}
		}
		if(len == 0)
			break;
	}

	return com;
}

int main()
{
	vector<string> strs;
	cout << "Please input several strings: " << endl;
	string in;
	while(cin >> in)
	{
		strs.push_back(in);
		if(getchar() == '\n')
			break;
	}

	string com = longestCommon(strs);
	if(com.size() != 0)
		cout << com << endl;
	else
		cout << "No common suffix" << endl;

	return 0;
}
