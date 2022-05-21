#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define endl '\n'
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
using namespace std;

void print(vector<pair<int, int>> v)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a, d;
  vector<pair<int, int>> tasks(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a >> d;
    tasks[i] = {a, d};
  }
  sort(tasks.begin(), tasks.end());
  // print(tasks);
  long long int t = 0, ans = 0;
  for (int i = 0; i < n; i++)
  {
    t += tasks[i].first;
    ans += tasks[i].second - t;
  }
  cout << ans << '\n';
}