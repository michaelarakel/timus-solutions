#include <iostream>
#include <vector>
using namespace std;


int main ()
{
	int n = 199809;
	vector <char> prime(n + 1, true);
	vector <int> v;
	prime[0] = prime[1] = false;
	v.push_back(2);
	for (int i = 3; i <= n; i+= 2)
	{
		if (prime[i])
		{
			v.push_back(i);
			if (i <= 447)
				for (int j = i*i; j <= n; j+= i)
					prime[j] = false;
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		cout << v[num - 1] << endl;
	}
}