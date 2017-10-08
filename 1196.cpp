#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	int n;
	cin >> n;
	unordered_set <int> s;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		s.insert(temp);
	}

	int m;
	cin >> m;

	int result = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> temp;
		if (s.find(temp) != s.end())
			++result;
	}

	cout << result << endl;
}