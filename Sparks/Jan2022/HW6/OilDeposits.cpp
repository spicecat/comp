#include <iostream>
#define endl '\n'

using namespace std;

bool map[100][100];
int m, n;

void dfs(int i, int j)
{
  if (map[i][j] && i >= 0 && i < m && j >= 0 && j < n)
  {
    map[i][j] = false;
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
    dfs(i - 1, j - 1);
    dfs(i + 1, j - 1);
    dfs(i - 1, j + 1);
    dfs(i + 1, j + 1);
  }
}

int main()
{
  while (1)
  {
    cin >> m >> n;
    if (!m)
      break;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        char c;
        cin >> c;
        map[i][j] = c == '@';
      }
    }
    int res = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (map[i][j])
        {
          res++;
          dfs(i, j);
        }
    cout << res << endl;
  }
}