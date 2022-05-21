#include <iostream>
#include <algorithm>

int main()
{
  int n;
  std::cin >> n;
  std::pair<int, int> movies[n];
  for (int i = 0; i < n; i++)
  {
    int a, b;
    std::cin >> a >> b;
    movies[i] = {b, a};
  }
  std::sort(movies, movies + n);
  int time = 0, ans = 0;
  for (int i = 0; i < n; i++)
    if (movies[i].second >= time)
    {
      time = movies[i].first;
      ans++;
    }
  std::cout << ans << '\n';
}