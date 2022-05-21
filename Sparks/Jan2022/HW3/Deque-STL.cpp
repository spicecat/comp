#include <iostream>
#include <deque>

using namespace std;

int main()
{
  int T;
  cin >> T;

  for (int t = 0; t < T; t++)
  {
    int N, K;
    cin >> N >> K;
    int A[N];
    for (int i = 0; i < N; i++)
    {
      int x;
      cin >> x;
      A[i] = x;
    }
    deque<int> window;
    for (int i = 0; i < N; i++)
    {
      while (window.size() && (A[window.front()] <= A[i] || window.front() <= i - K))
        window.pop_front();
      window.push_back(i);
      if (i >= K - 1)
        cout << A[window.front()] << " ";
    }
    cout << endl;
  }
}