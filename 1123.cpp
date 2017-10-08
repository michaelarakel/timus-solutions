#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string probable_ans(string s, bool improved)
{
	int pos = s.size() / 2 - !(s.size() & 1);
	while (pos >= 0)
	{
		if (s[pos] != s[s.size() - pos - 1])
		{
			if (s[pos] > s[s.size() - pos - 1])
			{
				s[s.size() - pos - 1] = s[pos];
				improved = true;
			}
			else
			{
				if (!improved)
				{
					s[pos] = s[s.size() - pos - 1] = s[pos] + 1;
					for (int i = pos + 1; i < s.size() - pos - 1; ++i)
						s[i] = '0';
					improved = true;
				}
				else
					s[pos] = s[s.size() - pos - 1] = min(s[pos], s[s.size() - pos - 1]);
			}
		}
		--pos;
	}
	return s;
}

bool is_palindrome(const string& s)
{
	for (int i = 0; i <= s.size() / 2; ++i)
	if (s[i] != s[s.size() - i - 1])
		return false;
	return true;
}

int main()
{
	string s;
	cin >> s;
	vector <string> v;
	if (is_palindrome(s))
		v.push_back(s);
	v.push_back(probable_ans(s, false));
	int pos = s.size() / 2 - !(s.size() & 1);

	if (s[pos] < '9')
	{
		char temp = s[pos];
		s[pos] = s[s.size() - pos - 1] = temp + 1;
		v.push_back(probable_ans(s, true));
	}
	sort(v.begin(), v.end());
	cout << v[0];
}