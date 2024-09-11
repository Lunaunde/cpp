#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int max_s, s[5][257][257];
	s[0][1][1] = 1;
	cin >> max_s;
	for (int y = 1; y <= pow(2, max_s); y++)
	{
		for (int x = 1; x <= pow(2, max_s); x++)
		{
			cout << s[max_s][x][y] << " ";
		}
		cout << endl;
	}
	return 0;
}