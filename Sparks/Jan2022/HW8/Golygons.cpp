#include <iostream>
#include <set>
#include <map>
#include <string>
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
using namespace std;
typedef string str;

set<str> res;
map<int, set<int>> visx;
map<int, set<int>> visy;

void dfs(int x, int y, int l, bool d, str p)
{
    if (!l)
    {
        if (!x && !y)
            res.insert(p);
        return;
    }
    if (d)
    {
        if (visx[x].lb(y) == visx[x].ub(y + l))
            dfs(x, y + l, l - 1, 0, (char)1 + p);
        if (visx[x].lb(y - l) == visx[x].ub(y))
            dfs(x, y - l, l - 1, 0, (char)0 + p);
    }
    else
    {
        if (visy[y].lb(x) == visy[y].ub(x + l))
            dfs(x + l, y, l - 1, 1, (char)3 + p);
        if (visy[y].lb(x - l) == visy[y].ub(x))
            dfs(x - l, y, l - 1, 1, (char)2 + p);
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    cin >> n;
    while (n--)
    {
        res.clear();
        visx.clear();
        visy.clear();
        int l, b;
        cin >> l >> b;
        while (b--)
        {
            int x, y;
            cin >> x >> y;
            visx[x].insert(y);
            visy[y].insert(x);
        }
        dfs(0, 0, l, 0, "");
        dfs(0, 0, l, 1, "");
        for (str s : res)
        {
            for (char c : s)
                cout << "nsew"[(int)c];
            cout << endl;
        }
        cout << "Found " << res.size() << " golygon(s).";
        if (n)
            cout << endl
                 << endl;
    }
}