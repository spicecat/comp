#include <iostream>
#include <map>
#include <set>

int main()
{
  int T;
  std::cin >> T;
  for (int t = 0; t < T; t++)
  {
    int N;
    double lx = 0;
    std::cin >> N;
    std::map<int, std::set<int>> points;
    for (int i = 0; i < N; i++)
    {
      int x, y;
      std::cin >> x >> y;
      points[x].insert(y);
      lx += x;
    }
    lx /= N;
    bool invalid = false;
    for (auto p = points.begin(); p != points.end(); p++)
    {
      if (p->first >= lx)
        break;
      if (invalid = p->second != points[(int)(2 * lx - p->first)])
        break;
    }
    std::cout << (invalid ? "NO\n" : "YES\n");
  }
}