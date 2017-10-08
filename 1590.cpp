#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s;
	cin >> s;
	unordered_set <string> hash_ans;
	int n = s.size();
	for (int i = 1; i <= n; i++)
	{
		string temp = s.substr(0, i);
		hash_ans.insert(temp);
		for (int j = 1; j < n - i + 1; ++j)
		{

		}
	}
	cout << hash_ans.size();
}