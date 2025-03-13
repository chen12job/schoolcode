#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	char cake[100][100];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> cake[i][j];
		}
	}
	int sumhap = 0;
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (cake[i][j] == 'C')
			{
				count++;
			}
		}
		sumhap += (count*(count - 1)) / 2;
	}
	for (int j = 0; j < n; j++)
	{
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (cake[i][j] == 'C')
			{
				count++;
			}
		}
		sumhap += (count * (count - 1)) / 2;
	}
	cout << sumhap << endl;
}
