#include <iostream>
#include <vector>

using namespace std;

vector <int> traversal;

void traverse(const vector <int>& order)
{
	if (order.size() == 0)
		return;
	int node = order.front();
	vector <int> left,
			right;

	for (int i = 1; i < order.size(); ++i)
	{
		if (node > order[i])
			left.push_back(order[i]);
		else
			right.push_back(order[i]);
	}
	traversal.push_back(node);
	traverse(left);
	traverse(right);
}

int main()
{
	int n;
	cin >> n;
	vector <int> order(n);
	for (int i = n - 1; i >= 0; --i)
		cin >> order[i];

	traverse(order);

	for (int i = n - 1; i >= 0; --i)
		cout << traversal[i] << ' ';
}