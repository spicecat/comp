#include <iostream>

bool equals(int a[], int b[], int n)
{
  for (int i = 0; i < n; i++)
    if (a[i] != b[i])
      return false;
  return true;
}
void copy(int a[], int b[], int n)
{
  for (int i = 0; i < n; i++)
    a[i] = b[i];
}
int abs(int n)
{
  return n < 0 ? -n : n;
}
int main()
{
  int T;
  std::cin >> T;
  for (int t = 0; t < T; t++)
  {
    int n;
    std::cin >> n;
    int ntuple[n];
    for (int i = 0; i < n; i++)
    {
      int x;
      std::cin >> x;
      ntuple[i] = x;
    }
    int loop[1000][n];
    for (int l = 0; l < 1000; l++)
    {
      copy(loop[l], ntuple, n);
      int next[n];
      for (int i = 0; i < n - 1; i++)
        next[i] = abs(ntuple[i + 1] - ntuple[i]);
      next[n - 1] = abs(ntuple[n - 1] - ntuple[0]);
      bool repeat = false;
      for (int c = 0; c <= l; c++)
        if (equals(loop[c], next, n))
        {
          repeat = true;
          std::cout << (c == l ? "ZERO\n" : "LOOP\n");
          break;
        }
      if (repeat)
        break;
      copy(ntuple, next, n);
    }
  }
}