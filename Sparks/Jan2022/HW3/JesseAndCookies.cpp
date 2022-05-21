#include <iostream>
#include <queue>

using namespace std;

int main()
{
  int n, k, t = 0;
  priority_queue<int> A;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    A.push(-x);
  }
  while (A.size() > 1 && -A.top() < k)
  {
    int x = A.top();
    A.pop();
    A.push(x + 2 * A.top());
    // cout << x << ';' << A.top() << '\n';
    A.pop();
    t++;
  }
  cout << (-A.top() >= k ? t : -1);
}