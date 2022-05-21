#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int h[n];
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    h[i] = x;
  }

  int res = 0;
  stack<int> s;
  for (int i = 0; i < n; i++)
  {
    // for every building read, if the previous building was taller, pop all the taller previous and push the new
    if (h[n] >= s.top())
      s.push(i);
    else
    {
      res = max(res, 1);
      s.pop();
    }
  }
}