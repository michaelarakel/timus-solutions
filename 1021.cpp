#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n1, n2;
	cin >> n1;
	vector <int> v1(n1);
	for (int i = 0; i < n1; ++i)
		cin >> v1[i];
	cin >> n2;
	vector <int> v2(n2);
	for (int i = n2 - 1; i >= 0; --i)
		cin >> v2[i];

	for (int i = 0; i < n1; ++i)
	{
		int num = 10000 - v1[i];
		if (binary_search(v2.begin(), v2.end(), num))
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}