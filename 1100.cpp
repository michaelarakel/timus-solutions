#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	map <int, vector <int> > m;
	for (int i = 0; i < n; ++i)
	{
		int ID, solved;
		cin >> ID >> solved;
		m[solved * -1].push_back(ID);
	}
	for (auto it = m.begin(); it != m.end(); ++it)
		for (int i = 0; i < it->second.size(); ++i)
			cout << it->second[i] << ' ' << -it->first << endl;
}