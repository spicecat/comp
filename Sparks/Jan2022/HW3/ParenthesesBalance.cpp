#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isBalanced(string line)
{
  stack<char> p;
  bool valid = true;
  for (char c : line)
  {
    if (c == '(' || c == '[')
      p.push(c);
    else if (p.empty())
      return false;
    else
      switch (c)
      {
      case ')':
        if (p.top() == '(')
          p.pop();
        else
          return false;
      case ']':
        if (p.top() == '[')
          p.pop();
        else
          return false;
      }
  }
  return p.empty();
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    string line;
    cin >> line;
    cout << (isBalanced(line) ? "Yes\n" : "No\n");
  }
}