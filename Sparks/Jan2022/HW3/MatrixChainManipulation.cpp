#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

int main()
{
  int n;
  cin >> n;
  map<char, pair<int, int>> matrix;
  for (int i = 0; i < n; i++)
  {
    char l;
    cin >> l;
    int m, n;
    cin >> m >> n;
    matrix[l] = {m, n};
  }
  string line;
  stack<pair<int, int>> eq;
  while (cin >> line && line != ":qa")
  {
    bool invalid = false;
    int ops = 0;
    for (char c : line)
      if (c == ')')
      {
        pair<int, int> a, b = eq.top();
        eq.pop();
        a = eq.top();
        eq.pop();
        if (invalid = a.second != b.first)
          break;
        ops += a.first * a.second * b.second;
        eq.push({a.first, b.second});
      }
      else if (c != '(')
        eq.push(matrix[c]);
    if (invalid)
      cout << "error\n";
    else
      cout << ops << endl;
  }
}