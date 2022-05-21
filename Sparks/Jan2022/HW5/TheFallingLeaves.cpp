#include <iostream>
#include <stack>
#include <algorithm>
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define endl '\n'
#define lli long long int
#define vi vector<int>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 0;
  stack<int> s;
  while (1)
  {
    t++;
    bool end = true;
    int res[1000] = {}, p = 500, minp = p, maxp = p;
    while (1)
    {
      int x;
      cin >> x;
      if (x == -1)
      {
        if (s.empty())
          break;
        p = s.top() + 1;
        s.pop();
      }
      else
      {
        res[p] += x;
        s.push(p);
        minp = min(minp, p);
        maxp = max(maxp, p);
        p--;
        end = false;
      }
    }
    if (end)
      break;
    cout << "Case " << t << ":\n";
    for (int i = minp; i < maxp; i++)
      cout << res[i] << ' ';
    cout << res[maxp] << "\n\n";
  }
}