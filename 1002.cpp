#include <iostream>
#include <vector>
#include <string>

using namespace std;

void transform(string& s)
{
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'i' || s[i] == 'j')
			s[i] = '1';
		else if (s[i] == 'a' || s[i] == 'b' || s[i] == 'c')
			s[i] = '2';
		else if (s[i] == 'd' || s[i] == 'e' || s[i] == 'f')
			s[i] = '3';
		else if (s[i] == 'g' || s[i] == 'h')
			s[i] = '4';
		else if (s[i] == 'k' || s[i] == 'l')
			s[i] = '5';
		else if (s[i] == 'm' || s[i] == 'n')
			s[i] = '6';
		else if (s[i] == 'p' || s[i] == 'r' || s[i] == 's')
			s[i] = '7';
		else if (s[i] == 't' || s[i] == 'u' || s[i] == 'v')
			s[i] = '8';
		else if (s[i] == 'w' || s[i] == 'x' || s[i] == 'y')
			s[i] = '9';
		else
			s[i] = '0';
	}
}

void solve(const string& s)
{
	int n;
	cin >> n;
	vector <string> v;
	string temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		transform(temp);
		v.push_back(temp);
	}

	vector <int> dp(s.size());

}

int main()
{
	string s;
	while (cin >> s)
	{
		if (s == "-1")
			break;
		solve(s);
	}
}