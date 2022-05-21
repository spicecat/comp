#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define endl '\n'
#define f first
#define s second
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, res = 0, cur = 0;
    cin >> n;
    vii events(n);
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        events.pb({a, 1});
        events.pb({b, -1});
    }
    sort(ALL(events));
    for (pii c : events)
    {
        cur += c.s;
        res = max(res, cur);
    }
    cout << res << endl;
}