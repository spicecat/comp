#include <iostream>
#define lli long long int

using namespace std;

int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int M = 1, N;
  while (cin >> N)
  {
    int A[N];
    lli P = 0;
    for (int i = 0; i < N; i++)
      cin >> A[i];
    for (int i = 0; i < N; i++)
      for (int j = i; j < N; j++)
      {
        lli p = 1;
        for (int k = i; k <= j; k++)
        {
          if (p *= A[k])
            P = max(P, p);
          else
            break;
        }
      }
    if (M > 1)
      cout << "\n\n";
    cout << "Case #" << M << ": The maximum product is " << P << '.';
    M++;
  }
}