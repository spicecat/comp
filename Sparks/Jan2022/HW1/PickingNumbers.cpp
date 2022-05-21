#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int a[100] = {};
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		a[x]++;
	}
	int ans = 0;
	for (int i = 1; i < 100; i++)
	{
		if (a[i - 1] + a[i] > ans)
			ans = a[i - 1] + a[i];
	}
	cout << ans << "\n";
}