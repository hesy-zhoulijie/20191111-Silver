#include <bits/stdc++.h>
using namespace std;
int n, m, sum[1000][1000], f[1000][1000];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cin >> sum[i][j];
		sort(sum[i] + 1, sum[i] + m + 1);
		for (int j = 2; j <= m; j++)
			sum[i][j] += sum[i][j - 1];
	}
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			for (int k = i - 1; k <= j; k++)
				if (j - k <= m)
					f[i][j] = min(f[i][j], f[i - 1][k] + sum[i][j - k] + (j - k) * (j - k));
	cout << f[n][n];
	return 0;
}
