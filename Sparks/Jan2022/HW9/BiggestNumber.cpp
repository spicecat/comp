#include <iostream>
#include <string>
#include <algorithm>
#define endl '\n'
#define loopp(i, n) for (int i = 1; i <= n; i++)
#define loopa(i, n) for (auto i : n)
#define f first
#define s second
using namespace std;
typedef pair<int, int> pii;
typedef string str;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
int r, c, board[17][17] = {}, nums = 0;
str res = "";

bool comp(str a)
{
  return a.length() > res.length() || a.length() == res.length() && a.compare(res) > 0;
}

void dfs(int i, int j, str s)
{
  int loc = board[i][j];
  if (!loc)
    return;
  s += loc;
  if (comp(s))
    res = s;
  else if (!comp(s + str(nums - s.length(), '9')))
    return;
  board[i][j] = 0;
  dfs(i - 1, j, s);
  dfs(i + 1, j, s);
  dfs(i, j - 1, s);
  dfs(i, j + 1, s);
  board[i][j] = loc;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (1)
  {
    cin >> r >> c;
    if (!r)
      break;
    fill(board[0], board[0] + 17 * 17, 0);
    loopp(i, r)
        loopp(j, c)
    {
      char x;
      cin >> x;
      if (x == '#')
        board[i][j] = 0;
      else
      {
        board[i][j] = x;
        nums++;
      }
    }

    loopp(i, r)
        loopp(j, c)
            dfs(i, j, "");
    cout << res << endl;
  }
}
