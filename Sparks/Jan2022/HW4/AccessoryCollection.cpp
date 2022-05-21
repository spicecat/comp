#include <iostream>
#include <set>

using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int L, A, N, D, res = 0;
    cin >> L >> A >> N >> D;

    set<int> acc;
    res += A * (N - D + 1);

    cout << res << endl;
  }
}