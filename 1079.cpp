#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100000;

int seq[maxn];
int seq_max[maxn];

void init()
{
	seq[0] = 0;
	seq[1] = 1;
	seq_max[0] = 0;
	seq_max[1] = 1;
	for (int i = 2; i < maxn; ++i)
	{
		if (i & 1)
			seq[i] = seq[i / 2] + seq[i / 2 + 1];
		else
			seq[i] = seq[i / 2];
		seq_max[i] = max(seq_max[i - 1], seq[i]);
	}
}

int main()
{
	init();
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		cout << seq_max[n] << endl;
	}
}