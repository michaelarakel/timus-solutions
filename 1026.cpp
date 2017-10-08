#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int max_in = 5001;
int bucket[max_in];

int main()
{
	int n;
	cin >> n;
	int max_realin = 0;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		if (max_realin < num)
			max_realin = num;
		++bucket[num];
	}
	for (int i = 1; i <= max_realin; ++i)
		bucket[i] += bucket[i - 1];
	char c[3];
	cin >> c;
	int queries;
	cin >> queries;
	for (int i = 0; i < queries; ++i)
	{
		int pos;
		cin >> pos;
		cout << (lower_bound(bucket + 1, bucket + max_realin, pos) - bucket) << endl;
	}

}