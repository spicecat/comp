#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        while (true)
        {
            vector<int> out(n);
            cin >> out[0];
            if (out[0] == 0)
            {
                cout << endl;
                break;
            }
            for (int i = 1; i < n; i++)
                cin >> out[i];
            int p1 = 0, p2 = 1;
            stack<int> s;
            while (p1 < n)
            {
                if (s.size() && s.top() == out[p1])
                {
                    p1++;
                    s.pop();
                }
                else
                {
                    if (p2 > n)
                        break;
                    s.push(p2++);
                }
            }
            cout << (s.empty() ? "Yes\n" : "No\n");
        }
    }
}