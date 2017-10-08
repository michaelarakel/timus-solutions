#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	map <string, vector <string> > team;
	map <string, int> dist;
	map <string, bool> used;
	string pl[3];
	bool Isenbaev = false;
	for (int i = 0; i < n; i++)
	{
		cin >> pl[0] >> pl[1] >> pl[2];
		team[pl[0]].push_back(pl[1]);
		team[pl[0]].push_back(pl[2]);
		team[pl[1]].push_back(pl[0]);
		team[pl[1]].push_back(pl[2]);
		team[pl[2]].push_back(pl[0]);
		team[pl[2]].push_back(pl[1]);
		if (pl[0] == "Isenbaev" || pl[1] == "Isenbaev" || pl[2] == "Isenbaev")
			Isenbaev = true;
	}
	if (Isenbaev)
	{
		dist["Isenbaev"] = 0;
		used["Isenbaev"] = 0;
		deque <string> d;
		d.push_back("Isenbaev");
		while (!d.empty())
		{
			used[d[0]] = true;
			for (int i = 0; i < team[d[0]].size(); i++)
				if (!used[team[d[0]][i]])
				{
					used[team[d[0]][i]] = true;
					d.push_back(team[d[0]][i]);
					dist[team[d[0]][i]] = dist[d[0]] + 1;
				}
			d.pop_front();
		}
	}
	for (map <string, vector <string> >::iterator it = team.begin(); it != team.end(); ++it)
		if (!used[(*it).first])
			dist[(*it).first] = -1;
	for (map <string, int>::iterator it = dist.begin(); it != dist.end(); ++it)
	{
		cout << (*it).first  << " ";
		if ((*it).second == -1)
			cout << "undefined";
		else
			cout << (*it).second;
		cout << endl;
	}
}