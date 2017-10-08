#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.size(); ++i)
		sum += s[i] - '0';
	if (sum % 3 == 0)
		cout << 2;
	else
		cout << 1 << endl << sum % 3 << endl;
}