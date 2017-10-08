#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int curr_num = v[0],
		count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (curr_num == v[i])
			++count;
		else
		{
			cout << count << ' ' << curr_num << ' ';
			curr_num = v[i];
			count = 1;
		}
	}
	cout << count << ' ' << curr_num << endl;
}