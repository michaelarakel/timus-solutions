#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	long long num;
	vector <long long> ans;
	while (cin >> num)
		ans.push_back(num);
	for (int i = ans.size() - 1; i >= 0; --i)
		cout << fixed << setprecision(4) << sqrt(ans[i] * 1.) << endl;
}