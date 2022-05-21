#include <iostream>
#include <map>
#define endl '\n'
#define loopp(i, n) for (int i = 1; i <= n; i++)
#define f first
#define s second
using namespace std;
typedef long long int lli;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    int n, x, res = 0, cur = 0;
    cin >> n;
    map<int, int> m, in;
    loopp(i, n)
    {
      cin >> x;
      if (m[x])
      {
        cur = m[x];
        while (1)
        {
          auto it = in.begin();
          if (it == in.end() || it->f > cur)
            break;
          m.erase(it->s);
          in.erase(it);
        }
      }
      m[x] = i;
      in[i] = x;
      res = max(res, i - cur);
    }
    cout << res << endl;
  }
}