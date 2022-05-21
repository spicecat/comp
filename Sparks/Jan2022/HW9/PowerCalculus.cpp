#include <iostream>
#include <set>
#define endl '\n'
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using namespace std;
typedef set<int> vi;

const int MAXN = 1010;
const int INF = 10000007;
int arr[MAXN], num;

bool dfs(int n, int step)
{
  if (num > step)
    return 0;
  if (arr[num] == n)
    return 1;
  if (arr[num] << (step - num) < n)
    return 0;
  for (int i = 0; i <= num; i++)
  {
    num++;
    arr[num] = arr[num - 1] + arr[i];
    if (arr[num] <= 10000 && dfs(n, step))
      return 1;
    arr[num] = arr[num - 1] - arr[i];
    if (arr[num] > 0 && dfs(n, step))
      return 1;
    num--;
  }
  return 0;
}
int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int n;
  while (cin >> n)
  {
    int i;
    for (i = 0;; i++)
    {
      arr[num = 0] = 1;
      if (dfs(n, i))
        break;
    }
    cout << i << endl;
  }
}