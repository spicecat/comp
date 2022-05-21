#include <iostream>
#include <map>
int main()
{
  while (1)
  {
    int n;
    std::cin >> n;
    if (n == 0)
      break;
    std::map<int, int> to, from;
    for (int i = 0; i < n; i++)
    {
      int x;
      std::cin >> x;
      to[x]++;
      std::cin >> x;
      from[x]++;
    }
    bool invalid = false;
    for (auto c : to)
      if (invalid = c.second != from[c.first])
        break;
    std::cout << (invalid ? "NO\n" : "YES\n");
  }
}