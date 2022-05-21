#include <iostream>
#include <queue>
#define endl '\n'
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--)
  {
    int n, m, s;
    cin >> n >> m;
    bool adj[1000][1000] = {};
    for (int i = 0; i < m; i++)
    {
      int x, y;
      cin >> x >> y;
      adj[x - 1][y - 1] = adj[y - 1][x - 1] = true;
    }
    cin >> s;
    s -= 1;
    int res[n], d = 1;
    for (int i = 0; i < n; i++)
      res[i] = 9999;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
      int qs = q.size();
      for (int dl = 0; dl < qs; dl++)
      {

        for (int i = 0; i < n; i++)
        {
          if (adj[q.front()][i] && d < res[i])
          {
            q.push(i);
            res[i] = d;
          }
        }
        q.pop();
      }
      d++;
    }
    for (int i = 0; i < n; i++)
      if (i != s)
        cout << (res[i] == 9999 ? -1 : res[i] * 6) << ' ';
    cout << endl;
  }
}
