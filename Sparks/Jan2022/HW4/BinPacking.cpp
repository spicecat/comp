#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    int l;
    cin >> n >> l;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    sort(v.begin(), v.end());
    int paired = 0, q = 0, i = 0, j = n - 1;
    while (i < j)
    {
      if (v[i] + v[j] <= l)
      {
        q++;
        i++;
        paired += 2;
      }
      j--;
    }
    cout << q + n - paired << endl;
    if (t)
      cout << endl;
  }
}
// int main()
// {
//   int t;
//   cin >> t;
//   while (t--)
//   {
//     int n, l;
//     cin >> n >> l;
//     vector<int> v;
//     for (int i = 0; i < n; i++)
//     {
//       int x;
//       cin >> x;
//       v.push_back(x);
//     }
//     int q = 0;
//     sort(v.begin(), v.end());
//     while (v.size())
//     {
//       auto it = upper_bound(v.begin(), v.end() - 1, l - v.back());
//       if (it - v.begin())
//         v.erase(it - 1);
//       v.pop_back();
//       q++;
//     }
//     cout << q;
//     if (t)
//       cout << "\n\n";
//   }
// }