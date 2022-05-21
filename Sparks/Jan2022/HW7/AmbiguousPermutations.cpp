#include <iostream>
#define endl '\n'
#define lli long long int

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

using namespace std;

int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  lli n, i;
  while (1)
  {
    cin >> n;
    if (!n)
      break;
    lli a[n];
    for (i = 0; i < n; i++)
      cin >> a[i];
    bool valid = true;
    for (i = 0; i < n; i++)
      if (i + 1 != a[a[i] - 1])
      {
        valid = false;
        break;
      }
    cout << (valid ? "" : "not ") << "ambiguous\n";
  }
}
