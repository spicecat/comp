#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int n, m, k;
int wall[500][500];

void dfs(int i, int j)
{
  if (k && !wall[i][j] && i >= 0 && i < n && j >= 0 && j < m)
  {
    wall[i][j] = 3;
    dfs(i, j - 1);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i + 1, j);
    if (k-- > 0)
      wall[i][j] = 2;
  }
}

int main()
{
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      char c;
      cin >> c;
      wall[i][j] = c == '#';
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      dfs(i, j);
  char o[4] = {'.', '#', 'X', '.'};
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cout << o[wall[i][j]];
    cout << endl;
  }
}