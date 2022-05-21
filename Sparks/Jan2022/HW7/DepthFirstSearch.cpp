#include <iostream>
#include <algorithm>
#define endl '\n'
#define lli long long int
#define pii pair<int, int>
#define f first
#define s second

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

using namespace std;

int n, t = 1;
bool adj[100][100] = {}, visited[100] = {};
pii res[100] = {};

void dfs(int i)
{
  // cout << 't' << i;
  if (visited[i])
    return;
  visited[i] = true;
  res[i].f = t;
  t++;
  for (int j = 0; j < n; j++)
    if (adj[i][j])
      dfs(j);
  res[i].s = t;
  t++;
}

int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int u, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++)
    {
      int x;
      cin >> x;
      adj[u - 1][x - 1] = true;
    }
  }
  for (int i = 0; i < n; i++)
    dfs(i);
  for (int i = 0; i < n; i++)
    cout << i + 1 << ' ' << res[i].f << ' ' << res[i].s << endl;
}
