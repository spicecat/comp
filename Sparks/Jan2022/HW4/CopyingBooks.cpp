#include <iostream>
#include <vector>
#define pb push_back
#define endl '\n'
#define lli long long int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

using namespace std;

int m, k;
lli a[501] = {};
bool res[501];
bool check(lli max)
{
  bool tmp[501] = {};
  int rem = k - 1;
  lli p = 0;
  for (int i = m - 1; i >= 0; i--)
    if (p + a[i] <= max && i >= rem)
      p += a[i];
    else
    {
      rem--;
      p = a[i];
      tmp[i] = true;
    }
  if (rem >= 0)
  {
    copy(tmp, tmp + m, res);
    return true;
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  while (N--)
  {
    cin >> m >> k;
    lli l = 0, r = 0, mid;
    for (int i = 0; i < m; i++)
    {
      cin >> a[i];
      r += a[i];
      l = max(l, a[i]);
    }
    for (; l < r; check(mid) ? r = mid : l = mid + 1)
      mid = (l + r) >> 1;
    for (int i = 0; i < m - 1; i++)
      cout << a[i] << (res[i] ? " / " : " ");
    cout << a[m - 1];
    if (N)
      cout << endl;
  }
}