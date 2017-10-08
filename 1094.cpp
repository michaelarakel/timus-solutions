#include <iostream>
#include <string>

using namespace std;

int main()
{
	char ans[80];
	for (int i = 0; i < 80; ++i)
		ans[i] = '\0';

	string result;
	string temp;
	while (getline(cin, temp))
	{
		result += temp;
		result.push_back(' ');
	}
	result.pop_back();

	int position = 1;
	for (int i = 0; i < result.size(); ++i)
	{
		if (result[i] == '<')
			--position;
		else if (result[i] == '>')
			++position;
		else
			ans[position++] = result[i];
	}
	for (int i = 0; i < 80; ++i)
		printf("%c", ans[i]);
}