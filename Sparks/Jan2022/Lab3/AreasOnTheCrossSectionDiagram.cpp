#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    char c;
    stack<int> s;
    stack<pair<int, int>> puddles;
    int sum = 0;
    for (int i = 0; cin >> c && c != 'q'; i++)
    {
        if (c == '\\')
            s.push(i);
        else if (c == '/')
        {
            if (s.size())
            {
                int t = s.top();
                s.pop();
                sum += i - t;
                int thispuddle = i - t;
                while (puddles.size() && puddles.top().first > t)
                {
                    thispuddle += puddles.top().second;
                    puddles.pop();
                }
                puddles.push({t, thispuddle});
            }
        }
    }
    cout << sum << endl;
    cout << puddles.size();
    vector<int> ans;
    while (puddles.size())
    {
        ans.push_back(puddles.top().second);
        puddles.pop();
    }
    reverse(ans.begin(), ans.end());
    for (auto c : ans)
        cout << " " << c;
    cout << endl;
}