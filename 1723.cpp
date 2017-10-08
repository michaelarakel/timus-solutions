#include <iostream>
#include <map>
#include <string>

using namespace std;

int main ()
{
	string s;
	cin >> s;
	map <string, int> m;
	string best = "";
	int max = 0;
	for (int i = 0; i < s.size(); i++)
		for (int j = 1; j <= s.size() - i; j++)
		{
			string temp = s.substr(i, j);
			m[temp]++;
			if (max < m[temp])
			{
				max = m[temp];
				best = temp;
			}
		}
	cout << best;
}